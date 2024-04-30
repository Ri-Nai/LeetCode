/*
 * @lc app=leetcode.cn id=2798 lang=cpp
 * @lcpr version=30122
 *
 * [2798] 满足目标工作时长的员工数目
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
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (auto x : hours)
            ans += x >= target;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,1,2,3,4]\n2\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,2,2]\n6\n
// @lcpr case=end

 */

