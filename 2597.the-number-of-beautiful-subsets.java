/*
 * @lc app=leetcode.cn id=2597 lang=java
 * @lcpr version=30204
 *
 * [2597] 美丽子集的数目
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int beautifulSubsets(int[] nums, int k) {
        int n = nums.length;
        int setSize = 1 << n;
        int ans = 0;
        for (int i = 1; i < setSize; ++i) {
            boolean flag = true;
            for (int j = 0; j < n && flag; ++j) {
                if ((i & (1 << j)) != 0) {
                    for (int t = j + 1; t < n && flag; ++t) {
                        if ((i & (1 << t)) != 0) {
                            if (Math.abs(nums[j] - nums[t]) == k) {
                                flag = false;
                            }
                        }
                    }
                }
            }
            if (flag) {
                ++ans;
            }
        }
        return ans;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [2,4,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */

