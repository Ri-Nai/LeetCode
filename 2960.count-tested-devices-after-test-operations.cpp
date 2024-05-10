/*
 * @lc app=leetcode.cn id=2960 lang=cpp
 * @lcpr version=30201
 *
 * [2960] 统计已测试设备
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
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        int n = batteryPercentages.size();
        for (int i = 0; i < n; ++i)
            if (batteryPercentages[i] - ans > 0)
                ++ans;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,2]\n
// @lcpr case=end

 */

