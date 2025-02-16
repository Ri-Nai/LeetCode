/*
 * @lc app=leetcode.cn id=1706 lang=rust
 * @lcpr version=30204
 *
 * [1706] 球会落何处
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_ball(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let (m, n) = (grid.len(), grid[0].len());
        (0..n)
            .map(|j| {
                let mut j = j as i32;
                for i in 0..m {
                    let dir = grid[i][j as usize];
                    j += dir;
                    if j < 0
                        || j >= n as i32
                        || grid[i][j as usize] != dir
                    {
                        return -1;
                    }
                }
                j as i32
            })
            .collect()
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,1,1,-1,-1],[1,1,1,-1,-1],[-1,-1,-1,1,1],[1,1,1,1,-1],[-1,-1,-1,-1,-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[-1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1],[1,1,1,1,1,1],[-1,-1,-1,-1,-1,-1]]\n
// @lcpr case=end

 */
