/*
 * @lc app=leetcode.cn id=1328 lang=java
 * @lcpr version=30204
 *
 * [1328] 破坏回文串
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    public String breakPalindrome(String palindrome) {
        int n = palindrome.length();
        if (n == 1) {
            return "";
        }
        char[] chars = palindrome.toCharArray();
        for (int i = 0; i < n / 2; i++) {
            if (palindrome.charAt(i) != 'a') {
                return palindrome.substring(0, i) + 'a' + palindrome.substring(i + 1);
            }
        }
        return palindrome.substring(0, n - 1) + 'b';
    }
}
// @lc code=end



/*
// @lcpr case=start
// "abccba"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

