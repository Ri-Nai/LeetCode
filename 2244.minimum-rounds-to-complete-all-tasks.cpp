/*
 * @lc app=leetcode.cn id=2244 lang=cpp
 * @lcpr version=30201
 *
 * [2244] 完成所有任务需要的最少轮数
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
#include <map>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int>cnt;
        vector<int> ans(100005, 1e9);
        ans[0] = 0;
        for (int i = 2; i <= 100000;++i)
        {
            if (i >= 3)
                ans[i] = min(ans[i], ans[i - 3] + 1);
            ans[i] = min(ans[i], ans[i - 2] + 1);
        }
        for (auto x : tasks)
            ++cnt[x];

        int res = 0;
        for (auto [x, y] : cnt)
        {
            if(y == 1)
                return -1;
            res += ans[y];
        }
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,2,3,3,2,4,4,4,4,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,3]\n
// @lcpr case=end

 */

