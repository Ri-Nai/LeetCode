/*
 * @lc app=leetcode.cn id=2080 lang=rust
 * @lcpr version=30204
 *
 * [2080] 区间内查询数字的频率
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
struct RangeFreqQuery {
    has: std::collections::HashMap<i32, Vec<i32>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RangeFreqQuery {

    fn new(arr: Vec<i32>) -> Self {
        Self {
            has: {
                let mut has = std::collections::HashMap::new();
                for (i, &v) in arr.iter().enumerate() {
                    has.entry(v).or_insert(vec![]).push(i as i32);
                }
                has
            } 
        }
    }
    
    fn query(&self, left: i32, right: i32, value: i32) -> i32 {
        if let Some(v) = self.has.get(&value) {
            let l = v.binary_search(&left).unwrap_or_else(|x| x);
            let r = v.binary_search(&right).unwrap_or_else(|x| x - 1) + 1;
            (r - l) as i32
        } else {
            0
        }
    }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * let obj = RangeFreqQuery::new(arr);
 * let ret_1: i32 = obj.query(left, right, value);
 */
// @lc code=end



/*
// @lcpr case=start
// ["RangeFreqQuery", "query", "query"][[[12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56]], [1, 2, 4], [0, 11, 33]]\n
// @lcpr case=end

 */

