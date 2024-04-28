/*
 * @lc app=leetcode.cn id=25 lang=cpp
 * @lcpr version=30122
 *
 * [25] K 个一组翻转链表
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
    auto reverseKGroup(ListNode* head, int k) -> ListNode* {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto groupPrev = dummy;
        while (true) {
            auto kth = getKth(groupPrev, k);
            if (kth == nullptr) break;
            auto groupNext = kth->next;
            auto reversed = reverse(groupPrev->next, groupNext);
            groupPrev->next = reversed.first;
            reversed.second->next = groupNext;
            groupPrev = reversed.second;
        }
        return dummy->next;
    }

private:
    auto getKth(ListNode* start, int k) -> ListNode* {
        auto ptr = start;
        for (auto i = 0; i < k; ++i) {
            if (ptr == nullptr) return nullptr;
            ptr = ptr->next;
        }
        return ptr;
    }

    auto reverse(ListNode* start, ListNode* end) -> pair<ListNode*, ListNode*> {
        auto prev = end;
        auto curr = start;
        while (curr != end) {
            auto nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return {prev, start};
    }
};

// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

 */

