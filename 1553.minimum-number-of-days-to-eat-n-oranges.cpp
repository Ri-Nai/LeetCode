/*
 * @lc app=leetcode.cn id=1553 lang=cpp
 * @lcpr version=30201
 *
 * [1553] 吃掉 N 个橘子的最少天数
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
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    map<int, int>mark;
    int minDays(int n) {
        if(mark[n])
            return mark[n];
        if(n == 1)
            return 1;
        int ans = 1e9;
        if(n % 2 == 0)
            ans = min(ans, minDays(n / 2) + 1);
        if(n % 3 == 0)
            ans = min(ans, minDays(n / 3) + 1);
        if (n > 1 && ((n - 1) % 2 == 0 || (n - 1) % 3 == 0))
            ans = min(ans, minDays(n - 1) + 1);
        if (n > 2 && (n - 2) % 3 == 0)
            ans = min(ans, minDays(n - 2) + 2);
        mark[n] = ans;
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 56\n
// @lcpr case=end

 */

