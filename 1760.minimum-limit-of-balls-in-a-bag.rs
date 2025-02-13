/*
 * @lc app=leetcode.cn id=1760 lang=rust
 * @lcpr version=30204
 *
 * [1760] 袋子里最少数目的球
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let mut l = 1;
        let mut r = *nums.iter().max().unwrap();
        let check = |size: i32| -> bool {
            let mut operations = 0;
            for &num in nums.iter() {
                operations += (num + size - 1) / size - 1;
            }
            operations <= max_operations
        };
        let mut ans = r;
        while l <= r {
            let m = (l + r) / 2;
            if check(m) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        ans
    }
}
// @lc code=end

/*
// @lcpr case=start
// [9]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,8,2]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,17]\n2\n
// @lcpr case=end

 */
