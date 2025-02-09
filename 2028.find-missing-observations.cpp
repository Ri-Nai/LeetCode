// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2028 lang=cpp
 * @lcpr version=30202
 *
 * [2028] 找出缺失的观测数据
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
#include <numeric>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int ans = (m + n) * mean - sum;
        int k = ans / n;
        int p = ans - k * n;
        vector<int> res;
        if (k > 6 || p && k >= 6 || k <= 0)
            return {};
        for (int i = 0; i < p; ++i)
            res.push_back(k + 1);
        for (int i = p; i < n; ++i)
            res.push_back(k);
        return res;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=missingRolls
// paramTypes= ["number[]","number","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [3,2,4,3]\n4\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,5,6]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n6\n4\n
// @lcpr case=end

// @lcpr case=start
// [1]\n3\n1\n
// @lcpr case=end

 */

