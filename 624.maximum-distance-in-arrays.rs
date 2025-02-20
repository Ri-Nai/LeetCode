/*
 * @lc app=leetcode.cn id=624 lang=rust
 * @lcpr version=30204
 *
 * [624] 数组列表中的最大距离
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
        arrays
            .iter()
            .fold(
                (std::i32::MAX / 2, std::i32::MIN / 2, 0),
                |(min, max, max_diff), arr| {
                    // println!("min: {}, max: {}, max_diff: {}", min, max, max_diff);
                    let max_diff = max_diff.max(max - arr[0]).max(arr.last().unwrap() - min);
                    (min.min(arr[0]), max.max(*arr.last().unwrap()), max_diff)
                },
            )
            .2
    }
}
// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5],[1,2,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1],[1]]\n
// @lcpr case=end

 */
