// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 * @lcpr version=30203
 *
 * [3040] 相同分数的最大操作数目 II
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
class Solution
{
public:
    int maxOperations(vector<int> &nums)
    {
        map<tuple<int, int, int>, int> mp;
        int n = nums.size();
        auto dfs = [&](auto self, int l, int r, int x) -> int
        {
            if (l + 1 > r)
                return 0;
            if (mp[{l, r, x}])
                return mp[{l, r, x}];
            int ans = 0;
            if (nums[l] + nums[l + 1] == x)
                ans = max(self(self, l + 2, r, x) + 1, ans);
            if (nums[r] + nums[r - 1] == x)
                ans = max(self(self, l, r - 2, x) + 1, ans);
            if (nums[l] + nums[r] == x)
                ans = max(self(self, l + 1, r - 1, x) + 1, ans);
            mp[{l, r, x}] = ans;
            return ans;
        };
        return 1 + max(dfs(dfs, 1, n - 2, nums[0] + nums[n - 1]), max(dfs(dfs, 2, n - 1, nums[0] + nums[1]), dfs(dfs, 0, n - 3, nums[n - 1] + nums[n - 2])));
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maxOperations
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// [3,2,1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,6,1,4]\n
// @lcpr case=end

 */
