/*
 * @lc app=leetcode.cn id=2928 lang=cpp
 * @lcpr version=30203
 *
 * [2928] 给小朋友们分糖果 I
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
    int distributeCandies(int n, int limit) {
        int ans = 0;
        for (int i = 0; i <= limit; ++i)
            for (int j = 0; j <= limit; ++j)
                for (int k = 0; k <= limit; ++k)
                    if (i + k + j == n)
                        ++ans;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n2\n
// @lcpr case=end

// @lcpr case=start
// 3\n3\n
// @lcpr case=end

 */

