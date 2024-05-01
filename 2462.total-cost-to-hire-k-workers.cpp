/*
 * @lc app=leetcode.cn id=2462 lang=cpp
 * @lcpr version=30122
 *
 * [2462] 雇佣 K 位工人的总代价
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
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        long long ans = 0;
        struct Pr
        {
            int id, val;
            Pr(int x, int y) : id(x), val(y) {}
            bool operator<(const Pr &_) const
            {
                if (val == _.val)
                    return id > _.id;
                return val > _.val;
            }
        };
        int n = costs.size();
        int m = candidates;
        priority_queue<Pr> Q1, Q2, Q;
        int t = n - m * 2;
        if (t <= 0)
            for (int i = 0; i < n; ++i)
                Q.push({i, costs[i]});
        else
        {
            for (int i = 0; i < m; ++i)
                Q1.push({i, costs[i]});
            for (int i = n - m; i < n; ++i)
                Q2.push({i, costs[i]});
            int l = m, r = n - m - 1;
            while (t > 0 && k > 0)
            {
                if (Q1.top() < Q2.top())
                {
                    ans += Q2.top().val;
                    Q2.pop();
                    Q2.push({r, costs[r]});
                    --r;
                }
                else
                {
                    ans += Q1.top().val;
                    Q1.pop();
                    Q1.push({l, costs[l]});
                    ++l;
                }
                --t, --k;
            }
            while (!Q1.empty())
                Q.push(Q1.top()), Q1.pop();
            while (!Q2.empty())
                Q.push(Q2.top()), Q2.pop();
        }
        while (k > 0)
        {
            ans += Q.top().val;
            Q.pop();
            --k;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [17,12,10,2,7,2,11,20,8]\n3\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,1]\n3\n3\n
// @lcpr case=end

 */
