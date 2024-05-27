/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 * @lcpr version=30202
 *
 * [1738] 找出第 K 大的异或坐标值
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
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>ans(n + 1, vector<int>(m + 1));
        vector<int>res;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                res.push_back(ans[i][j] ^= ans[i - 1][j] ^ ans[i - 1][j - 1] ^ ans[i][j - 1] ^ matrix[i - 1][j - 1]);
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        return res[k - 1];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[5,2],[1,6]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n2\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n3\n
// @lcpr case=end

// @lcpr case=start
// [[5,2],[1,6]]\n4\n
// @lcpr case=end

 */

