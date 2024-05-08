/*
 * @lc app=leetcode.cn id=2079 lang=cpp
 * @lcpr version=30201
 *
 * [2079] 给植物浇水
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
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int now = 0, ans = n;
        for (int i = 0; i < n; ++i)
        {
            now += plants[i];
            if (now > capacity)
                ans += 2 * i, now = plants[i];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,3]\n5\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,4,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7,7,7,7]\n8\n
// @lcpr case=end

 */

