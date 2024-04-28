/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30122
 *
 * [51] N 皇后
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
    vector<vector<string>> solveNQueens(int n)
    {
        vector<bool> mark(n);
        const string T(n, '.');
        vector<vector<string>> ans;
        auto dfs = [&](auto self, int x, vector<int> P) -> void
        {
            if (x == n)
            {
                auto replace = [&](int x)
                {
                    string s = T;
                    s[x] = 'Q';
                    return s;
                };
                vector<string> res(P.size());
                transform(P.begin(), P.end(), res.begin(), replace);
                ans.push_back(res);
            }
            for (int i = 0; i < n; ++i)
            {
                if (mark[i])
                    continue;
                auto Q = P;
                bool flag = 1;
                for (int j = 0;flag && j < P.size(); ++j)
                    if (abs(P[j] - i) == abs(x - j))
                        flag = 0;
                if (!flag) continue;
                mark[i] = 1;
                Q.push_back(i);
                self(self, x + 1, Q);
                mark[i] = 0;
            }
        };
        dfs(dfs,0,{});
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
