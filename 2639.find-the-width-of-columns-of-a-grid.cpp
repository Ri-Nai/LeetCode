/*
 * @lc app=leetcode.cn id=2639 lang=cpp
 * @lcpr version=30122
 *
 * [2639] 查询网格图中每一列的宽度
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
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        auto get_length = [&](int x)
        {
            int length = x < 0;
            if (x < 0)
                x = -x;
            if (x == 0)
                return 1;
            while (x)
                ++length, x /= 10;
            return length;
        };
        vector<int> ans(m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                ans[j] = max(ans[j], get_length(grid[i][j]));
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1],[22],[333]]\n
// @lcpr case=end

// @lcpr case=start
// [[-15,1,3],[15,7,12],[5,6,-2]]\n
// @lcpr case=end

 */
