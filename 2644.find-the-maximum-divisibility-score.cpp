/*
 * @lc app=leetcode.cn id=2644 lang=cpp
 * @lcpr version=30202
 *
 * [2644] 找出可整除性得分最大的整数
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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(), divisors.end());
        int mx = -1, ans;
        for (auto x : divisors)
        {
            int cnt = 0;
            for (auto y : nums)
                cnt += y % x == 0;
            if (cnt > mx)
                mx = cnt, ans = x;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,7,9,3,9]\n[5,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [20,14,21,10]\n[5,7,5]\n
// @lcpr case=end

// @lcpr case=start
// [12]\n[10,16]\n
// @lcpr case=end

 */

