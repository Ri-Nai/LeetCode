/*
 * @lc app=leetcode.cn id=2391 lang=cpp
 * @lcpr version=30201
 *
 * [2391] 收集垃圾的最少总时间
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
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        auto get_ans = [&] (char c)
        {
            int now = 0;
            int res = 0;
            int mx = 0;
            auto count = [&](string s, char c)
            {
                int cnt = 0;
                for (auto c_ : s)
                    cnt += c_ == c;
                return cnt;
            };
            for (int i = 0; i < n; ++i)
            {
                if (i) now += travel[i - 1];
                int t = count(garbage[i], c);
                if (t) mx = now;
                res += t;
            }
            return mx + res;
        };
        return get_ans('M') + get_ans('G') + get_ans('P');
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["G","P","GP","GG"]\n[2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// ["MMM","PGM","GP"]\n[3,10]\n
// @lcpr case=end

 */

