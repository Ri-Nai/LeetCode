// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1235 lang=cpp
 * @lcpr version=30122
 *
 * [1235] 规划兼职工作
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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<array<int, 3>> op;
        int n = startTime.size();
        vector<int>unq;
        for (int i = 0; i < n; ++i)
            unq.push_back(startTime[i]), unq.push_back(endTime[i]);
        sort(unq.begin(), unq.end());
        unq.erase(unique(unq.begin(), unq.end()), unq.end());
        auto get_uid = [&](int x) -> int
        {
            return lower_bound(unq.begin(), unq.end(), x) - unq.begin() + 1;
        };
        for (int i = 0; i < n; ++i)
            op.push_back({get_uid(startTime[i]), get_uid(endTime[i]), profit[i]});
        sort(op.begin(), op.end());
        int m = unq.size();
        vector<int>dp(m + 1);
        for (int i = 1, j = 0; i <= m; ++i)
        {
            dp[i] = max(dp[i], dp[i - 1]);
            while (j < op.size() && op[j][0] == i)
            {
                auto [l, r, x] = op[j];
                dp[r] = max(dp[r], dp[i] + x);
                ++j;
            }
        }
        return dp[m];
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=jobScheduling
// paramTypes= ["number[]","number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,3,3]\n[3,4,5,6]\n[50,10,40,70]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,6]\n[3,5,10,6,9]\n[20,20,100,70,60]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1]\n[2,3,4]\n[5,6,4]\n
// @lcpr case=end

 */

