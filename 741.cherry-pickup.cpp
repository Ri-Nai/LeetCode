/*
 * @lc app=leetcode.cn id=741 lang=cpp
 * @lcpr version=30122
 *
 * [741] 摘樱桃
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
#include <map>
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
        const int inf = 1e9;
        vector<vector<vector<int>>> dp(2 * n);
        for (int i = 0; i < 2 * n - 1; ++i)
        {
            dp[i].resize(i + 1);
            for (int j = 0; j <= i; ++j)
                dp[i][j].assign(i + 1, -inf);
            auto get = [&](int step, int x1, int x2)
            {
                int y1 = step - x1;
                int y2 = step - x2;
                if (x1 >= n || y1 >= n || x2 >= n || y2 >= n)
                    return -inf;
                if (grid[x1][y1] == -1 || grid[x2][y2] == -1)
                    return -inf;
                if (x1 == x2 && grid[x1][y1])
                    return 1;
                return grid[x1][y1] + grid[x2][y2];
            };
            if (i == 0)
                dp[0][0][0] = get(0, 0, 0);
            const int dx[] = {0, 1};
            auto get_max = [&](int &x, int y) -> void
            {
                if (y > x)
                    x = y;
                return ;
            };
            for (int j = 0; j < i; ++j)
                for (int k = 0; k < i; ++k)
                    for (int d1 = 0; d1 <= 1; ++d1)
                        for (int d2 = 0; d2 <= 1; ++d2)
                        {
                            int x1 = j + dx[d1];
                            int x2 = k + dx[d2];
                            get_max(dp[i][x1][x2], dp[i - 1][j][k] + get(i, x1, x2));
                        }
        }
        int ans = dp[2 * n - 2][n - 1][n - 1];
        return max(ans, 0);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[0,1,-1],[1,0,-1],[1,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,1,-1],[1,-1,1],[-1,1,1]]\n
// @lcpr case=end

 */
