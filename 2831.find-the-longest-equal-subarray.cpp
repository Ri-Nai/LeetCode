/*
 * @lc app=leetcode.cn id=2831 lang=cpp
 * @lcpr version=30202
 *
 * [2831] 找出最长等值子数组
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
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = 1;
        vector<vector<int>>pos(n + 1);
        for (int i = 0; i < n; ++i)
            pos[nums[i]].push_back(i);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0, l = 0; j < pos[i].size(); ++j)
            {
                while (l <= j && (pos[i][j] - j) - (pos[i][l] - l)> k)
                    ++l;
                if (l > j)
                    continue;
                ans = max(ans, j - l + 1);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3,2,3,1,3]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,2,1,1]\n2\n
// @lcpr case=end

 */

