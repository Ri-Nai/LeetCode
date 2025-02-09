// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30204
 *
 * [80] 删除有序数组中的重复项 II
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
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int now = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int cnt = 0, first = nums[i];
            while (i < nums.size() && nums[i] == first)
            {
                ++cnt;
                if (cnt <= 2)
                    nums[now++] = nums[i];
                ++i;
            }
            --i;
        }
        // while (nums.size() > now)
        //     nums.pop_back();
        return now;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */
