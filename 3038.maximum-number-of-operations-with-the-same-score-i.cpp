/*
 * @lc app=leetcode.cn id=3038 lang=cpp
 * @lcpr version=30203
 *
 * [3038] 相同分数的最大操作数目 I
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
    int maxOperations(vector<int>& nums) {
        int now = nums[0] + nums[1];
        int ans = 1;
        int n = nums.size();
        for (int i = 2; i + 1 < n; i += 2)
        {
            if (nums[i] + nums[i + 1] == now)
                ++ans;
            else break;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,2,1,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,6,1,4]\n
// @lcpr case=end

 */

