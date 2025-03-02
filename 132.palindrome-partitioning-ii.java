/*
 * @lc app=leetcode.cn id=132 lang=java
 * @lcpr version=30204
 *
 * [132] 分割回文串 II
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {

    public int minCut(String s) {
        int[] dp = new int[s.length()];
        for (int i = 0; i < s.length(); i++) {
            dp[i] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            // odd length
            for (int j = 0; i - j >= 0 && i + j < s.length() && s.charAt(i - j) == s.charAt(i + j); j++) {
                if (i - j == 0) {
                    dp[i + j] = 0;
                } else {
                    dp[i + j] = Math.min(dp[i + j], dp[i - j - 1] + 1);
                }
            }
            // even length
            for (int j = 0; i - j >= 0 && i + j + 1 < s.length() && s.charAt(i - j) == s.charAt(i + j + 1); j++) {
                if (i - j == 0) {
                    dp[i + j + 1] = 0;
                } else {
                    dp[i + j + 1] = Math.min(dp[i + j + 1], dp[i - j - 1] + 1);
                }
            }
        }
        return dp[s.length() - 1];    
    }
}
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "ab"\n
// @lcpr case=end

 */

