/*
 * @lc app=leetcode.cn id=2234 lang=java
 * @lcpr version=30204
 *
 * [2234] 花园的最大总美丽值
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public long maximumBeauty(int[] flowers, long newFlowers, int target, int full, int partial) {
        int n = flowers.length;
        for (int i = 0; i < n; i++) {
            flowers[i] = Math.min(flowers[i], target);
        }
        Arrays.sort(flowers);
        reverse(flowers);
        long sum = 0;
        for (int flower : flowers) {
            sum += flower;
        }
        long ans = 0;
        if ((long) target * n - sum <= newFlowers) {
            ans = (long) full * n;
        }
        long pre = 0;
        int ptr = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                pre += flowers[i - 1];
            }
            if (flowers[i] == target) {
                continue;
            }
            long rest = newFlowers - ((long) target * i - pre);
            if (rest < 0) {
                break;
            }
            while (!(ptr >= i && (long) flowers[ptr] * (n - ptr) - sum <= rest)) {
                sum -= flowers[ptr];
                ptr++;
            }
            rest -= (long) flowers[ptr] * (n - ptr) - sum;
            ans = Math.max(ans, (long) full * i + (long) partial * Math.min(flowers[ptr] + rest / (n - ptr), (long) target - 1));
        }
        return ans;
    }

    private void reverse(int[] nums) {
        for (int i = 0, j = nums.length - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,3,1,1]\n7\n6\n12\n1\n
// @lcpr case=end

// @lcpr case=start
// [2,4,5,3]\n10\n5\n2\n6\n
// @lcpr case=end

 */

