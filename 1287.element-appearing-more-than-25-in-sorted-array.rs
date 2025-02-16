/*
 * @lc app=leetcode.cn id=1287 lang=rust
 * @lcpr version=30204
 *
 * [1287] 有序数组中出现次数超过25%的元素
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn find_special_integer(arr: Vec<i32>) -> i32 {
        arr.iter()
            .fold((-1, 0, 0, 0), |(pre, cnt, max, res), &x| {
                if x == pre {
                    if cnt + 1 > max {
                        (x, cnt + 1, cnt + 1, x)
                    } else {
                        (x, cnt + 1, max, res)
                    }
                } else {
                    if 1 > max {
                        (x, 1, 1, x)
                    } else {
                        (x, 1, max, res)
                    }
                }
            })
            .3
    }
}
// @lc code=end

/*
// @lcpr case=start
// [1,2,2,6,6,6,6,7,10]\n
// @lcpr case=end

 */
