/*
 * @lc app=leetcode.cn id=1103 lang=cpp
 * @lcpr version=30203
 *
 * [1103] 分糖果 II
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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        for (int i = 0; ; ++i)
        {
            int p = i % num_people;
            int t = i + 1;
            if (candies <= t)
            {
                ans[p] += candies;
                return ans;
            }
            ans[p] += t;
            candies -= t;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n4\n
// @lcpr case=end

// @lcpr case=start
// 10\n3\n
// @lcpr case=end

 */

