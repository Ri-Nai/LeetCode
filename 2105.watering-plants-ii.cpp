/*
 * @lc app=leetcode.cn id=2105 lang=cpp
 * @lcpr version=30201
 *
 * [2105] 给植物浇水 II
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
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int nowA = capacityA;
        int nowB = capacityB;
        int ans = 0;
        auto check = [&](int &now, int plant, int capacity)
        {
            int res = 0;
            if (now < plant)
                now = capacity - plant, ++ans;
            else now -= plant;
            return res;
        };
        for (int i = 0, j = n - 1; i <= j; ++i, --j)
        {
            if (i != j)
            {
                ans += check(nowA, plants[i], capacityA);
                ans += check(nowB, plants[j], capacityB);
            }
            else
            {
                if (nowA >= nowB)
                    ans += check(nowA, plants[i], capacityA);
                else
                    ans += check(nowB, plants[j], capacityB);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,3]\n5\n5\n
// @lcpr case=end

// @lcpr case=start
// [2,2,3,3]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n10\n8\n
// @lcpr case=end

 */

