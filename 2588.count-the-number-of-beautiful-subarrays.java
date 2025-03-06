/*
 * @lc app=leetcode.cn id=2588 lang=java
 * @lcpr version=30204
 *
 * [2588] 统计美丽子数组数目
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public long beautifulSubarrays(int[] nums) {
        // hashmap
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        long ans = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > 0)
                nums[i] ^= nums[i - 1];
            ans += map.getOrDefault(nums[i], 0);
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
        }
        return ans;
    }
}
// @lc code=end



/*
// @lcpr case=start
// [4,3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,10,4]\n
// @lcpr case=end

 */

