/*
 * @lc app=leetcode.cn id=2225 lang=cpp
 * @lcpr version=30202
 *
 * [2225] 找出输掉零场或一场比赛的玩家
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
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        const int N = 1e5 + 5;
        vector<int>cnt(N), mark(N);
        for (auto p : matches)
            ++cnt[p[1]], mark[p[0]] = mark[p[1]] = 1;
        for (int i = 1; i < N; ++i)
            if (mark[i] && cnt[i] < 2)
                ans[cnt[i]].push_back(i);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[2,3],[1,3],[5,4],[6,4]]\n
// @lcpr case=end

 */

