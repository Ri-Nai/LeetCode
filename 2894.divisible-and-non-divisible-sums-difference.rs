/*
 * @lc app=leetcode.cn id=2894 lang=rust
 * @lcpr version=30204
 *
 * [2894] 分类求和并作差
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        (1 + n) * n / 2 - (n / m) * (m + n / m * m)
    }
}
// @lc code=end



/*
// @lcpr case=start
// 10\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n6\n
// @lcpr case=end

// @lcpr case=start
// 5\n1\n
// @lcpr case=end

 */

