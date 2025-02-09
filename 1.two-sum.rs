/*
 * @lc app=leetcode.cn id=1 lang=rust
 * @lcpr version=30204
 *
 * [1] 两数之和
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut sorted = nums.iter().enumerate().collect::<Vec<_>>();
        // 按照值排序
        sorted.sort_by_key(|x| x.1);

        let mut left = 0;
        let mut right = nums.len() - 1;
        while left < right {
            let sum = sorted[left].1 + sorted[right].1;
            if sum == target {
                return vec![sorted[left].0 as i32, sorted[right].0 as i32];
            } else if sum < target {
                left += 1;
            } else {
                right -= 1;
            }
        }
        vec![]
    }
}
// @lc code=end

/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [3,2,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [3,3]\n6\n
// @lcpr case=end

 */
