/*
 * @lc app=leetcode.cn id=1463 lang=cpp
 * @lcpr version=30122
 *
 * [1463] 摘樱桃 II
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
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        const int inf = 1e9;
        auto get_max = [&](int &x, int y) -> void
        {
            if (y > x)
                x = y;
            return;
        };
        vector<vector<vector<int>>> dp(n);
        for (int i = 0; i < n; ++i)
        {
            dp[i].resize(m);
            for (int j = 0; j < m; ++j)
                dp[i][j].assign(m, -inf);
            auto not_in_grid = [&](int y1, int y2)
            {
                return y1 >= m || y2 >= m || y1 < 0 || y2 < 0;
            };
            auto get = [&](int x, int y1, int y2)
            {
                if (not_in_grid(y1, y2))
                    return -inf;
                if (y1 == y2 && grid[x][y1])
                    return grid[x][y1];
                return grid[x][y1] + grid[x][y2];
            };
            if (i == 0)
            {
                dp[0][0][m - 1] = get(0, 0, m - 1);
                continue;
            }
            const int dx[] = {0, 1, -1};

            for (int j = 0; j < m; ++j)
                for (int k = 0; k < m; ++k)
                    for (int d1 = 0; d1 <= 2; ++d1)
                        for (int d2 = 0; d2 <= 2; ++d2)
                        {
                            int y1 = j + dx[d1];
                            int y2 = k + dx[d2];
                            if (not_in_grid(y1, y2))
                                continue;
                            get_max(dp[i][y1][y2], dp[i - 1][j][k] + get(i, y1, y2));
                        }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                get_max(ans, dp[n - 1][i][j]);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1],[1,1]]\n
// @lcpr case=end

 */
