/*
 * @lc app=leetcode.cn id=2965 lang=cpp
 * @lcpr version=30203
 *
 * [2965] 找出缺失和重复的数字
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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>cnt(n * n + 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                ++cnt[grid[i][j]];
        vector<int>ans(2);
        for (int i = 1; i <= n * n; ++i)
            if (!cnt[i]) ans[1] = i;
            else if (cnt[i] == 2) ans[0] = i;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[9,1,7],[8,9,2],[3,4,6]]\n
// @lcpr case=end

 */

