/*
 * @lc app=leetcode.cn id=48 lang=rust
 * @lcpr version=30204
 *
 * [48] 旋转图像
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn rotate(matrix: &mut Vec<Vec<i32>>) {
        for i in 0..(n + 1) / 2 {
            for j in 0..n / 2 {
                (
                    matrix[i][j],
                    matrix[n - 1 - j][i],
                    matrix[n - 1 - i][n - 1 - j],
                    matrix[j][n - 1 - i],
                ) = (
                    matrix[n - 1 - j][i],
                    matrix[n - 1 - i][n - 1 - j],
                    matrix[j][n - 1 - i],
                    matrix[i][j],
                );
            }
        }
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */
