/*
 * @lc app=leetcode.cn id=3001 lang=cpp
 * @lcpr version=30204
 *
 * [3001] 捕获黑皇后需要的最少移动次数
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
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
    {
        auto sameRow = [&](int a, int b, int c, int d, int e, int f)
        {
            return a == e && (c != a || d <= min(b, f) || d >= max(b, f));
        };

        auto sameColumn = [&](int a, int b, int c, int d, int e, int f)
        {
            return b == f && (d != b || c <= min(a, e) || c >= max(a, e));
        };

        auto sameDiagonal = [&](int a, int b, int c, int d, int e, int f)
        {
            return abs(c - e) == abs(d - f) && ((c - e) * (b - f) != (a - e) * (d - f) || a < min(c, e) || a > max(c, e));
        };

        if (sameRow(a, b, c, d, e, f))
            return 1;

        if (sameColumn(a, b, c, d, e, f))
            return 1;

        if (sameDiagonal(a, b, c, d, e, f))
            return 1;
        return 2;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 1\n1\n8\n8\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 5\n3\n3\n4\n5\n2\n
// @lcpr case=end

 */
