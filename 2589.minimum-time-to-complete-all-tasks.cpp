// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2589 lang=cpp
 * @lcpr version=30202
 *
 * [2589] 完成所有任务的最少时间
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
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        auto cmp = [&](vector<int> a, vector<int> b)
        {
            return a[1] < b[1];
        };
        sort(tasks.begin(), tasks.end(), cmp);
        vector<int> mark(2005);
        vector<int> ans(n);
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int l = tasks[i][0];
            int r = tasks[i][1];
            int x = tasks[i][2];
            for (int j = r; ans[i] < x && j >= l; --j)
            {
                if (mark[j])
                    continue;
                mark[j] = 1;
                ++res;
                for (int k = 0; k < n; ++k)
                    if (tasks[k][0] <= j && tasks[k][1] >= j)
                        ++ans[k];
            }
        }
        return res;
    }
};
// @lc code=end

// @lcpr-div-debug-arg-start
// funName=findMinimumTime
// paramTypes= ["number[][]"]
// @lcpr-div-debug-arg-end

/*
// @lcpr case=start
// [[2,3,1],[4,5,1],[1,5,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3,2],[2,5,3],[5,6,2]]\n
// @lcpr case=end

 */
