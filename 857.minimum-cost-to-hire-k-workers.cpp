/*
 * @lc app=leetcode.cn id=857 lang=cpp
 * @lcpr version=30122
 *
 * [857] 雇佣 K 名工人的最低成本
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
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<tuple<double, int, int>> Prop;
        for (int i = 0; i < quality.size(); ++i)
            Prop.emplace_back(1. * wage[i] / quality[i], quality[i], quality[i]);
        sort(Prop.begin(), Prop.end());
        double ans = 1e9;
        double now = 0;
        priority_queue<int> Q;
        for (int i = 0; i < Prop.size(); ++i)
        {
            auto [p, q, w] = Prop[i];
            if (i <= k - 1)
                now += q, Q.push(q);
            else
                if (q < Q.top())
                    now -= Q.top(), Q.pop(), Q.push(q), now += q;
            if (i >= k - 1)
            {
                ans = min(ans, now * p);
            }
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [10,20,5]\n[70,50,30]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,1,10,10,1]\n[4,8,2,2,7]\n3\n
// @lcpr case=end

 */

