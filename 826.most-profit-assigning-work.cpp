/*
 * @lc app=leetcode.cn id=826 lang=cpp
 * @lcpr version=30202
 *
 * [826] 安排工作以达到最大收益
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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int> >Pr;
        int n = difficulty.size(), m = worker.size();
        for (int i = 0; i < n; ++i)
            Pr.emplace_back(difficulty[i], profit[i]);
        sort(Pr.begin(), Pr.end());
        sort(worker.begin(), worker.end());
        int mx = 0, ans = 0;
        for (int i = 0, j = 0; i < m; ++i)
        {
            while (j < n && Pr[j].first <= worker[i])
                mx = max(mx, Pr[j++].second);
            ans += mx;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [85,47,57]\n[24,66,99]\n[40,25,25]\n
// @lcpr case=end

 */

