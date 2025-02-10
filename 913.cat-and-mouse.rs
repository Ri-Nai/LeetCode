/*
 * @lc app=leetcode.cn id=913 lang=rust
 * @lcpr version=30204
 *
 * [913] 猫和老鼠
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

impl Solution {
    const MOUSE_TURN: i32 = 0;
    const CAT_TURN: i32 = 1;
    const DRAW: i32 = 0;
    const MOUSE_WIN: i32 = 1;
    const CAT_WIN: i32 = 2;

    pub fn cat_mouse_game(graph: Vec<Vec<i32>>) -> i32 {
        let n = graph.len();
        let mut degrees = vec![vec![vec![0; 2]; n]; n];
        let mut results = vec![vec![vec![0; 2]; n]; n];

        // queue: (mouse, cat, turn)

        let mut queue: std::collections::VecDeque<(i32, i32, i32)> =
            std::collections::VecDeque::new();

        for i in 0..n {
            for j in 1..n {
                degrees[i][j][Self::MOUSE_TURN as usize] = graph[i].len();
                degrees[i][j][Self::CAT_TURN as usize] = graph[j].len();
            }
        }

        for node in graph[0].iter() {
            for i in 0..n {
                degrees[i][*node as usize][Self::CAT_TURN as usize] -= 1;
            }
        }

        for i in 1..n {
            results[0][i][Self::MOUSE_TURN as usize] = Self::MOUSE_WIN;
            results[0][i][Self::CAT_TURN as usize] = Self::MOUSE_WIN;

            queue.push_back((0, i as i32, Self::MOUSE_TURN as i32));
            queue.push_back((0, i as i32, Self::CAT_TURN as i32));
        }

        for i in 1..n {
            results[i][i][Self::MOUSE_TURN as usize] = Self::CAT_WIN;
            results[i][i][Self::CAT_TURN as usize] = Self::CAT_WIN;

            queue.push_back((i as i32, i as i32, Self::MOUSE_TURN as i32));
            queue.push_back((i as i32, i as i32, Self::CAT_TURN as i32));
        }

        while !queue.is_empty() {
            let (mouse, cat, turn) = queue.pop_front().unwrap();
            let prev_state = {
                let mut prev_state: Vec<(i32, i32, i32)> = Vec::new();
                let prev_turn = turn ^ 1;
                match prev_turn {
                    Self::MOUSE_TURN => {
                        for &prev_mouse in graph[mouse as usize].iter() {
                            prev_state.push((prev_mouse, cat, prev_turn));
                        }
                    }
                    _ => {
                        for &prev_cat in graph[cat as usize].iter() {
                            if prev_cat != 0 {
                                prev_state.push((mouse, prev_cat, prev_turn));
                            }
                        }
                    }
                }
                prev_state
            };
            let result = results[mouse as usize][cat as usize][turn as usize];
            for (prev_mouse, prev_cat, prev_turn) in prev_state.iter() {
                if results[*prev_mouse as usize][*prev_cat as usize][*prev_turn as usize]
                    != Self::DRAW
                {
                    continue;
                }
                let can_win = (result == Self::MOUSE_WIN && *prev_turn == Self::MOUSE_TURN)
                    || (result == Self::CAT_WIN && *prev_turn == Self::CAT_TURN);
                if can_win {
                    results[*prev_mouse as usize][*prev_cat as usize][*prev_turn as usize] = result;
                    queue.push_back((*prev_mouse, *prev_cat, *prev_turn));
                } else {
                    degrees[*prev_mouse as usize][*prev_cat as usize][*prev_turn as usize] -= 1;
                    if degrees[*prev_mouse as usize][*prev_cat as usize][*prev_turn as usize] > 0 {
                        continue;
                    }
                    let lose_result = if *prev_turn == Self::MOUSE_TURN {
                        Self::CAT_WIN
                    } else {
                        Self::MOUSE_WIN
                    };
                    results[*prev_mouse as usize][*prev_cat as usize][*prev_turn as usize] =
                        lose_result;
                    queue.push_back((*prev_mouse, *prev_cat, *prev_turn));
                }
            }
        }

        results[1][2][Self::MOUSE_TURN as usize] as i32
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[0],[3],[0,2]]\n
// @lcpr case=end

 */
