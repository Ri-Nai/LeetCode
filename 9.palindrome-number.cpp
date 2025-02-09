/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=30204
 *
 * [9] 回文数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <string>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

