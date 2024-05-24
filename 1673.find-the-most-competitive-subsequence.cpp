/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 * @lcpr version=30202
 *
 * [1673] 找出最具竞争力的子序列
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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>S;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while (!S.empty() && n - i + S.size() > k && S.back() > nums[i])
                S.pop_back();
            if (S.size() < k)
                S.push_back(nums[i]);
        }
        return S;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,5,2,6]\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3,3,5,4,9,6]\n4\n
// @lcpr case=end

 */

