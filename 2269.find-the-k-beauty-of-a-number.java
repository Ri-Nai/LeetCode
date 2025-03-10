/*
 * @lc app=leetcode.cn id=2269 lang=java
 * @lcpr version=30204
 *
 * [2269] 找到一个数字的 K 美丽值
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int divisorSubstrings(int num, int k) {
        // num -> string
        String numStr = String.valueOf(num);
        int n = numStr.length();
        int ans = 0;
        for (int i = 0; i <= n - k; i++) {
            // 从第i位开始的子串
            int subNum = Integer.parseInt(numStr.substring(i, i + k));
            if (subNum != 0 && num % subNum == 0) {
                ans++;
            }
        }
        return ans;
    }
}
// @lc code=end



/*
// @lcpr case=start
// 240\n2\n
// @lcpr case=end

// @lcpr case=start
// 430043\n2\n
// @lcpr case=end

 */

