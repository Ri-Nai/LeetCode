/*
 * @lc app=leetcode.cn id=3072 lang=cpp
 * @lcpr version=30203
 *
 * [3072] 将元素分配到两个数组中 II
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
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> uni = nums, to = nums;
        sort(uni.begin(), uni.end());
        auto it = unique(uni.begin(), uni.end());
        uni.erase(it, uni.end());
        for (int i = 0; i < n; ++i)
            to[i] = lower_bound(uni.begin(), uni.end(), to[i]) - uni.begin() + 1;
        int m = uni.size();
        struct BIT
        {
            vector<int> C;
            int len;
            BIT(int n) : C(n + 1), len(n) {}
            void Add(int x, int y)
            {
                while (x <= len)
                    C[x] += y, x += x & -x;
            }
            int Sum(int x)
            {
                int res = 0;
                while (x)
                    res += C[x], x -= x & -x;
                return res;
            }
            int Get_Cnt(int x)
            {
                return Sum(len) - Sum(x);
            }
        }X(m), Y(m);
        vector<int> A, B;
        auto Insert = [&](int p, int q)
        {
            if (p == 0)
                X.Add(to[q], 1), A.push_back(nums[q]);
            else
                Y.Add(to[q], 1), B.push_back(nums[q]);
        };
        Insert(0, 0);
        Insert(1, 1);
        auto check = [&] (int p) -> int
        {
            int C1 = X.Get_Cnt(p);
            int C2 = Y.Get_Cnt(p);
            if (C1 > C2)
                return 0;
            if (C2 > C1)
                return 1;
            return A.size() > B.size();
        };
        for (int i = 2; i < n; ++i)
            Insert(check(to[i]), i);
        auto result = A;
        result.insert(result.end(), B.begin(), B.end());
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,1,3,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,14,3,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,3,3,3]\n
// @lcpr case=end

 */
