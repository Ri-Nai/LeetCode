/*
 * @lc app=leetcode.cn id=575 lang=cpp
 * @lcpr version=30203
 *
 * [575] 分糖果
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
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        auto &C = candyType;
        sort(C.begin(), C.end());
        auto it = unique(C.begin(), C.end());
        return min(n / 2, int(it - C.begin()));
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,1,2,2,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [6,6,6,6]\n
// @lcpr case=end

 */

