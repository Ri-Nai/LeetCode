/*
 * @lc app=leetcode.cn id=1742 lang=rust
 * @lcpr version=30204
 *
 * [1742] 盒子中小球的最大数量
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn count_balls(low_limit: i32, high_limit: i32) -> i32 {
        let mut map = std::collections::HashMap::new();
        let count_nums = |num| {
            let mut num = num;
            let mut count = 0;
            while num > 0 {
                count += num % 10;
                num /= 10;
            }
            count
        };
        for i in low_limit..=high_limit {
            let count = count_nums(i);
            *map.entry(count).or_insert(0) += 1;
        }
        map.values().max().unwrap().clone()
    }
}
// @lc code=end

/*
// @lcpr case=start
// 1\n10\n
// @lcpr case=end

// @lcpr case=start
// 5\n15\n
// @lcpr case=end

// @lcpr case=start
// 19\n28\n
// @lcpr case=end

 */
