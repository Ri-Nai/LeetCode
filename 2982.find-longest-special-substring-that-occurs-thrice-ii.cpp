/*
 * @lc app=leetcode.cn id=2982 lang=cpp
 * @lcpr version=30202
 *
 * [2982] 找出出现至少三次的最长特殊子字符串 II
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
#include <map>

// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int maximumLength(string s)
    {
        map<int, int> has[26];
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            while (j < n && s[j] == s[i])
                ++j;
            ++has[s[i] - 'a'][j - i];
            i = j - 1;
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i)
        {
            vector<pair<int, int>> v;
            for (auto p : has[i])
                v.push_back(p);
            reverse(v.begin(), v.end());
            if (v.empty())
                continue;
            for (int j = 0; j < v.size(); ++j)
            {
                auto [x, y] = v[j];
                if (y >= 3)
                    ans = max(ans, x);
                else if (j + 1 < v.size())
                    ans = max(ans, v[j + 1].first);
                if (y == 2 && x >= 2)
                    ans = max(ans, x - 1);
                else if (y == 1 && x >= 3)
                    ans = max(ans, x - 2);
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */
