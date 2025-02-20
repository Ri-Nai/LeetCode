/*
 * @lc app=leetcode.cn id=2595 lang=rust
 * @lcpr version=30204
 *
 * [2595] 奇偶位数
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        (0..32).fold(vec![0, 0], |mut res, i| {
            res[(i % 2) as usize] += (n >> i) & 1;
            res
        })
    }
}
// @lc code=end

/*
// @lcpr case=start
// 50\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

 */
