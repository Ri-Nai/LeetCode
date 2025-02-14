/*
 * @lc app=leetcode.cn id=1552 lang=rust
 * @lcpr version=30204
 *
 * [1552] 两球之间的磁力
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
impl Solution {
    pub fn max_distance(position: Vec<i32>, m: i32) -> i32 {
        // sort 
        let mut position = position.clone();
        position.sort_unstable();
        

        let n = position.len();
        let (mut l, mut r) = (1, position.iter().max().unwrap() - position.iter().min().unwrap());
        let mut ans = 1;
        let check = |limit| {
            let mut cnt = 1;
            let mut pre = position[0];
            for i in 1..n {
                if position[i] - pre >= limit {
                    cnt += 1;
                    pre = position[i];
                }
            }
            cnt >= m
        };
        
        while l <= r {
            let mid = (l + r) / 2;
            if check(mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans
    }
}
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,4,3,2,1,1000000000]\n2\n
// @lcpr case=end

 */

