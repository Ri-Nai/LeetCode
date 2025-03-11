/*
 * @lc app=leetcode.cn id=2012 lang=java
 * @lcpr version=30204
 *
 * [2012] 数组美丽值求和
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int sumOfBeauties(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = Math.max(left[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = Math.min(right[i + 1], nums[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (left[i - 1] < nums[i] && nums[i] < right[i + 1]) {
                ans += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
        }
        return ans;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n
// @lcpr case=end

 */

