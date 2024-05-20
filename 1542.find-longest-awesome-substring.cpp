/*
 * @lc app=leetcode.cn id=1542 lang=cpp
 * @lcpr version=30202
 *
 * [1542] 找出最长的超赞子字符串
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
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        vector<int>last(1 << 10, -1);
        int now = 0;
        int ans = 1;
        auto get_last = [&](int x) -> int
        {
            if (x == 0)
                return -1;
            return last[x] == -1 ? 1e9 : last[x];
        };
        auto get_ans = [&](int x)
        {
            int res = get_last(x);
            for (int i = 0; i < 10; ++i)
                res = min(res, get_last(1 << i ^ x));
            return res;
        };
        for (int i = 0; i < n; ++i)
        {
            now ^= 1 << s[i] - '0';
            if (last[now] == -1)
                last[now] = i;
            ans = max(ans, i - get_ans(now));
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "3242415"\n
// @lcpr case=end

// @lcpr case=start
// "12345678"\n
// @lcpr case=end

// @lcpr case=start
// "213123"\n
// @lcpr case=end

// @lcpr case=start
// "00"\n
// @lcpr case=end

 */

