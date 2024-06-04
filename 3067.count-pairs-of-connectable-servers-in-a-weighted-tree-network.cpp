// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3067 lang=cpp
 * @lcpr version=30203
 *
 * [3067] 在带权树网络中统计可连接服务器对数目
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
    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        vector<vector<pair<int, int>>> E;
        for (auto V : edges)
        {
            int u = V[0], v = V[1], w = V[2];
            E.resize(max(max(u, v) + 1, int(E.size())));
            E[u].push_back({v, w});
            E[v].push_back({u, w});
        }
        int n = E.size();
        vector<int> ans(n);
        auto get_ans = [&](int S)
        {
            vector<int> cnt(n);
            auto dfs = [&](auto self, int u, int f, int dis) -> void
            {
                if (dis % signalSpeed == 0)
                    ++cnt[u];
                for (auto [v, w] : E[u])
                {
                    if (v == f)
                        continue;
                    self(self, v, u, dis + w);
                    cnt[u] += cnt[v];
                }
            };
            dfs(dfs, S, -1, 0);
            int res = 0;
            int now = 0;
            for (auto [v, w] : E[S])
                res += now * cnt[v], now += cnt[v];
            return res;
        };
        for (int i = 0; i < n; ++i)
            ans[i] = get_ans(i);
        return ans;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=countPairsOfConnectableServers
// paramTypes= ["number[][]","number"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]]\n3\n
// @lcpr case=end

 */
