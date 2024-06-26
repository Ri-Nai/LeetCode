/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 * @lcpr version=30202
 *
 * [1535] 找出数组游戏的赢家
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
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n - 1)
            return *max_element(arr.begin(), arr.end());
        int now = 0, cnt = 0;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[now] > arr[i])
            {
                if (++cnt == k)
                    return arr[now];
            }
            else if (arr[now] == arr[i])
                return arr[now];
            else
            {
                arr.push_back(arr[now]);
                now = i;
                if ((cnt = 1) == k)
                    return arr[now];
            }
        }
        return arr[now];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3,5,4,6,7]\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1]\n10\n
// @lcpr case=end

// @lcpr case=start
// [1,9,8,2,3,7,6,4,5]\n7\n
// @lcpr case=end

// @lcpr case=start
// [1,11,22,33,44,55,66,77,88,99]\n1000000000\n
// @lcpr case=end

 */

