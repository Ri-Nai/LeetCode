/*
 * @lc app=leetcode.cn id=994 lang=cpp
 * @lcpr version=30201
 *
 * [994] 腐烂的橘子
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
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<tuple<int, int, int>>Q;
        int n = grid.size(), m = grid[0].size();
        int tot = 0, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 2) Q.push({i, j, 0});
                tot += !!grid[i][j];
            }
        }
        int ans = 0;
        while(!Q.empty())
        {
            auto [x, y, step] = Q.front();
            ans = step;
            ++cnt;
            Q.pop();
            const int dx[] = {1, 0, -1, 0};
            const int dy[] = {0, 1, 0, -1};
            auto check = [&](int x, int y)
            {
                return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1;
            };
            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (!check(nx, ny)) continue;
                grid[nx][ny] = 2;
                Q.push({nx, ny, step + 1});
            }
        }
        if (cnt < tot)
            return -1;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[2,1,1],[1,1,0],[0,1,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,1],[0,1,1],[1,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[0,2]]\n
// @lcpr case=end

 */

