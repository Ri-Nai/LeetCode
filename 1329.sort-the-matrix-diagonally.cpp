/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30122
 *
 * [1329] 将矩阵按对角线排序
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>res(n + m - 1);
        for (int i = 0; i < n; ++i)
            for(int j = 0;j < m; ++j)
                res[i - j + m - 1].push_back(mat[i][j]);
        vector<vector<int>>ans = mat;
        for (int i = 0; i < n + m - 1; ++i)
        {
            sort(res[i].begin(), res[i].end());
            int diff = i - m + 1;
            for (int j = 0; j < res[i].size(); ++j)
            {
                if (diff < 0)
                    ans[0 + j][-diff + j] = res[i][j];
                else
                    ans[diff + j][0 + j] = res[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

