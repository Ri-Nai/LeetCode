/*
 * @lc app=leetcode.cn id=1017 lang=cpp
 * @lcpr version=30122
 *
 * [1017] 负二进制转换
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    string baseNeg2(int n)
    {
        string ans;
        while (n)
            ans += (n & 1) + '0', n -= n & 1, n /= -2;
        reverse(ans.begin(), ans.end());
        if (ans.empty())
            ans += "0";
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
