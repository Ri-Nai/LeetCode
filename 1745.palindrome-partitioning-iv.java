/*
 * @lc app=leetcode.cn id=1745 lang=java
 * @lcpr version=30204
 *
 * [1745] 分割回文串 IV
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public boolean checkPartitioning(String s) {
        boolean isPalindrome[][] = new boolean[s.length()][s.length()];
        for (int len = 0; len < s.length(); ++len) {
            for (int l = 0; l + len < s.length(); ++l) {
                int r = l + len;
                if (len == 0) {
                    isPalindrome[l][r] = true;
                } else if (len == 1) {
                    isPalindrome[l][r] = s.charAt(l) == s.charAt(r);
                } else {
                    isPalindrome[l][r] = s.charAt(l) == s.charAt(r) && isPalindrome[l + 1][r - 1];
                }
            }
        }
        for (int i = 1; i < s.length() - 1; i++) {
            for (int j = i + 1; j < s.length(); j++) {
                if (isPalindrome[0][i - 1] && isPalindrome[i][j - 1] && isPalindrome[j][s.length() - 1]) {
                    return true;
                }
            }
        }
        return false;
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abcbdd"\n
// @lcpr case=end

// @lcpr case=start
// "bcbddxy"\n
// @lcpr case=end

 */

