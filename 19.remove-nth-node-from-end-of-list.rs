/*
 * @lc app=leetcode.cn id=19 lang=rust
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn remove_nth_from_end(head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        let mut len = 1;
        let mut curr = head.unwrap().as_ref();
        // 计算链表长度
        while curr.next.is_some() {
            len += 1;
            curr = curr.next.as_ref().unwrap();
        }
        // 计算目标位置（前驱节点）
        let target = len - n as usize;
        if target == 0 {
            head.unwrap().next
        } else {
            let mut curr = head.unwrap().as_mut();
            for _ in 1..target {
                curr = curr.next.as_mut().unwrap();
            }
            curr.next = curr.next.as_mut().unwrap().next.take();
            head
        }
    }
}

// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
