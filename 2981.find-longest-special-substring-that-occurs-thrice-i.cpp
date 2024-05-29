// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 * @lcpr version=30202
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
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
    int maximumLength(string s) {
        int n = s.size();
        for (int len = n - 2; len >= 1; --len)
        {
            map<string, int>cnt;
            for (int i = 0; i + len <= n; ++i)
            {
                string tmp = s.substr(i, len);
                bool flag = 1;
                for (int j = 1; flag && j < len; ++j)
                    if (tmp[j - 1] != tmp[j])
                        flag = 0;
                if (flag && ++cnt[tmp] == 3)
                    return len;
            }
        }
        return -1;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumLength
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "aaaa"\n
// @lcpr case=end

// @lcpr case=start
// "abcdef"\n
// @lcpr case=end

// @lcpr case=start
// "abcaba"\n
// @lcpr case=end

 */

