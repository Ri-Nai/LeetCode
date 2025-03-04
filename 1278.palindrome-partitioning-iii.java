/*
 * @lc app=leetcode.cn id=1278 lang=java
 * @lcpr version=30204
 *
 * [1278] 分割回文串 III
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public int palindromePartition(String s, int k) {
        int n = s.length();
        int[][] cost = new int[n][n];
        for (int l = 0; l < n; ++l)
            for (int r = l + 1; r < n; ++r)
                for (int i = l, j = r; i < j; ++i, --j)
                    if (s.charAt(i) != s.charAt(j))
                        ++cost[l][r];
        int[][] dp = new int[n][k + 1];
        // fill dp int max / 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = Integer.MAX_VALUE / 2;
            }
        }
        for (int i = 0; i < n; i++) {
            dp[i][1] = cost[0][i];
        }
        for (int i = 1; i < n; i++) 
            for (int j = 2; j <= k && j <= i + 1; j++)
                for (int l = 0; l < i; l++) 
                    dp[i][j] = Math.min(dp[i][j], dp[l][j - 1] + cost[l + 1][i]);
        return dp[n - 1][k];
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abc"\n2\n
// @lcpr case=end

// @lcpr case=start
// "aabbc"\n3\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n8\n
// @lcpr case=end

 */

