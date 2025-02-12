/*
 * @lc app=leetcode.cn id=1728 lang=rust
 * @lcpr version=30204
 *
 * [1728] 猫和老鼠 II
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
use std::collections::VecDeque;

const MOUSE_TURN: usize = 0;
const CAT_TURN: usize = 1;
const UNKNOWN: i32 = 0;
const MOUSE_WIN: i32 = 1;
const CAT_WIN: i32 = 2;
const MAX_MOVES: i32 = 1000;
static DIRS: [(i32, i32); 4] = [(-1, 0), (1, 0), (0, -1), (0, 1)];

impl Solution {
    pub fn can_mouse_win(grid: Vec<String>, cat_jump: i32, mouse_jump: i32) -> bool {
        let grid: Vec<Vec<char>> = grid.into_iter().map(|s| s.chars().collect()).collect();
        let rows = grid.len();
        let cols = grid[0].len();
        let total = rows * cols;

        let mut start_mouse = 0;
        let mut start_cat = 0;
        let mut food = 0;
        for (i, row) in grid.iter().enumerate() {
            for (j, &ch) in row.iter().enumerate() {
                let pos = i * cols + j;
                match ch {
                    'M' => start_mouse = pos,
                    'C' => start_cat = pos,
                    'F' => food = pos,
                    _ => (),
                }
            }
        }

        let mut degrees = vec![vec![vec![0; 2]; total]; total];
        for mouse in 0..total {
            let mouse_row = mouse / cols;
            let mouse_col = mouse % cols;
            if grid[mouse_row][mouse_col] == '#' {
                continue;
            }
            for cat in 0..total {
                let cat_row = cat / cols;
                let cat_col = cat % cols;
                if grid[cat_row][cat_col] == '#' {
                    continue;
                }
                degrees[mouse][cat][MOUSE_TURN] += 1;
                degrees[mouse][cat][CAT_TURN] += 1;

                for &(dx, dy) in DIRS.iter() {
                    let mut row = mouse_row as i32 + dx;
                    let mut col = mouse_col as i32 + dy;
                    let mut jump = 1;
                    while jump <= mouse_jump {
                        if row < 0 || row >= rows as i32 || col < 0 || col >= cols as i32 {
                            break;
                        }
                        let r = row as usize;
                        let c = col as usize;
                        if grid[r][c] == '#' {
                            break;
                        }
                        let next_mouse = r * cols + c;
                        degrees[next_mouse][cat][MOUSE_TURN] += 1;
                        row += dx;
                        col += dy;
                        jump += 1;
                    }

                    let mut row = cat_row as i32 + dx;
                    let mut col = cat_col as i32 + dy;
                    let mut jump = 1;
                    while jump <= cat_jump {
                        if row < 0 || row >= rows as i32 || col < 0 || col >= cols as i32 {
                            break;
                        }
                        let r = row as usize;
                        let c = col as usize;
                        if grid[r][c] == '#' {
                            break;
                        }
                        let next_cat = r * cols + c;
                        degrees[mouse][next_cat][CAT_TURN] += 1;
                        row += dx;
                        col += dy;
                        jump += 1;
                    }
                }
            }
        }

        let mut results = vec![vec![vec![[UNKNOWN, 0]; 2]; total]; total];
        let mut q = VecDeque::new();

        for pos in 0..total {
            let row = pos / cols;
            let col = pos % cols;
            if grid[row][col] == '#' {
                continue;
            }
            results[pos][pos][MOUSE_TURN] = [CAT_WIN, 0];
            results[pos][pos][CAT_TURN] = [CAT_WIN, 0];
            q.push_back((pos, pos, MOUSE_TURN));
            q.push_back((pos, pos, CAT_TURN));
        }

        for mouse in 0..total {
            let mouse_row = mouse / cols;
            let mouse_col = mouse % cols;
            if grid[mouse_row][mouse_col] == '#' || mouse == food {
                continue;
            }
            results[mouse][food][MOUSE_TURN] = [CAT_WIN, 0];
            results[mouse][food][CAT_TURN] = [CAT_WIN, 0];
            q.push_back((mouse, food, MOUSE_TURN));
            q.push_back((mouse, food, CAT_TURN));
        }

        for cat in 0..total {
            let cat_row = cat / cols;
            let cat_col = cat % cols;
            if grid[cat_row][cat_col] == '#' || cat == food {
                continue;
            }
            results[food][cat][MOUSE_TURN] = [MOUSE_WIN, 0];
            results[food][cat][CAT_TURN] = [MOUSE_WIN, 0];
            q.push_back((food, cat, MOUSE_TURN));
            q.push_back((food, cat, CAT_TURN));
        }

        while let Some((mouse, cat, turn)) = q.pop_front() {
            let result = results[mouse][cat][turn][0];
            let moves = results[mouse][cat][turn][1];
            let prev_states =
                Self::get_prev_states(mouse, cat, turn, rows, cols, &grid, mouse_jump, cat_jump);
            for (prev_mouse, prev_cat, prev_turn) in prev_states {
                if results[prev_mouse][prev_cat][prev_turn][0] != UNKNOWN {
                    continue;
                }
                if (result == MOUSE_WIN && prev_turn == MOUSE_TURN)
                    || (result == CAT_WIN && prev_turn == CAT_TURN)
                {
                    results[prev_mouse][prev_cat][prev_turn][0] = result;
                    results[prev_mouse][prev_cat][prev_turn][1] = moves + 1;
                    q.push_back((prev_mouse, prev_cat, prev_turn));
                } else {
                    degrees[prev_mouse][prev_cat][prev_turn] -= 1;
                    if degrees[prev_mouse][prev_cat][prev_turn] == 0 {
                        let lose_result = if prev_turn == MOUSE_TURN {
                            CAT_WIN
                        } else {
                            MOUSE_WIN
                        };
                        results[prev_mouse][prev_cat][prev_turn][0] = lose_result;
                        results[prev_mouse][prev_cat][prev_turn][1] = moves + 1;
                        q.push_back((prev_mouse, prev_cat, prev_turn));
                    }
                }
            }
        }

        let res = results[start_mouse][start_cat][MOUSE_TURN][0];
        let steps = results[start_mouse][start_cat][MOUSE_TURN][1];
        res == MOUSE_WIN && steps <= MAX_MOVES
    }

    fn get_prev_states(
        mouse: usize,
        cat: usize,
        turn: usize,
        rows: usize,
        cols: usize,
        grid: &[Vec<char>],
        mouse_jump: i32,
        cat_jump: i32,
    ) -> Vec<(usize, usize, usize)> {
        let mouse_row = mouse / cols;
        let mouse_col = mouse % cols;
        let cat_row = cat / cols;
        let cat_col = cat % cols;
        let prev_turn = if turn == MOUSE_TURN {
            CAT_TURN
        } else {
            MOUSE_TURN
        };
        let max_jump = if prev_turn == MOUSE_TURN {
            mouse_jump
        } else {
            cat_jump
        };
        let (start_row, start_col) = if prev_turn == MOUSE_TURN {
            (mouse_row, mouse_col)
        } else {
            (cat_row, cat_col)
        };
        let mut prev_states = vec![(mouse, cat, prev_turn)];

        for &(dx, dy) in DIRS.iter() {
            let mut row = start_row as i32 + dx;
            let mut col = start_col as i32 + dy;
            let mut jump = 1;
            while jump <= max_jump {
                if row < 0 || row >= rows as i32 || col < 0 || col >= cols as i32 {
                    break;
                }
                let r = row as usize;
                let c = col as usize;
                if grid[r][c] == '#' {
                    break;
                }
                let (prev_mouse, prev_cat) = if prev_turn == MOUSE_TURN {
                    (r * cols + c, cat)
                } else {
                    (mouse, r * cols + c)
                };
                prev_states.push((prev_mouse, prev_cat, prev_turn));
                row += dx;
                col += dy;
                jump += 1;
            }
        }

        prev_states
    }
}
// @lc code=end

/*
// @lcpr case=start
// ["####F","#C...","M...."]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// ["M.C...F"]\n1\n4\n
// @lcpr case=end

// @lcpr case=start
// ["M.C...F"]\n1\n3\n
// @lcpr case=end

// @lcpr case=start
// ["C...#","...#F","....#","M...."]\n2\n5\n
// @lcpr case=end

// @lcpr case=start
// [".M...","..#..","#..#.","C#.#.","...#F"]\n3\n1\n
// @lcpr case=end

 */
