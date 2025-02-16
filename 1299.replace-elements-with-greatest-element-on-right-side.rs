/*
 * @lc app=leetcode.cn id=1299 lang=rust
 * @lcpr version=30204
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn replace_elements(arr: Vec<i32>) -> Vec<i32> {
        arr.iter()
            .rev()
            .fold((vec![], -1), |(mut acc, max), &x| {
                acc.push(max);
                (acc, max.max(x))
            })
            .0
            .into_iter()
            .rev()
            .collect()
    }
}
// @lc code=end

/*
// @lcpr case=start
// [17,18,5,4,6,1]\n
// @lcpr case=end

// @lcpr case=start
// [400]\n
// @lcpr case=end

 */
