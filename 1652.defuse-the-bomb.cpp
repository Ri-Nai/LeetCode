/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 * @lcpr version=30122
 *
 * [1652] 拆炸弹
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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans = code;
        for (int i = 0; i < n; ++i)
        {
            ans[i] = 0;
            if (k < 0)
            {
                for (int j = -1; j >= k; --j)
                    ans[i] += code[(i + j + n) % n];
            }
            else
                for (int j = 1; j <= k; ++j)
                    ans[i] += code[(i + j + n) % n];
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [5,7,1,4]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,4,9,3]\n-2\n
// @lcpr case=end

 */

