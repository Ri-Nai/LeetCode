// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30122
 *
 * [23] 合并 K 个升序链表
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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head;
        ListNode *now = &head;
        while (1)
        {
            int cnt = 0;
            ListNode **nxt = nullptr;
            int mn = 1e9+7;
            for (auto &x : lists)
            {
                if (x == nullptr)
                {
                    ++cnt;
                    continue;
                }
                if (x -> val < mn)
                    mn = x -> val, nxt = &x;
            }
            if (cnt == lists.size())
                break;
            now -> next = *nxt;
            *nxt = (*nxt) -> next;
            now = now -> next;
        }
        return head.next;
    }
};

// @lc code=end



/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

