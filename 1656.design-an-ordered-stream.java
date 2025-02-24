/*
 * @lc app=leetcode.cn id=1656 lang=java
 * @lcpr version=30204
 *
 * [1656] 设计有序流
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import java.util.List;
import java.util.ArrayList;

class OrderedStream {

    private int n;
    private int ptr;
    private String[] stream;

    public OrderedStream(int n) {
        this.n = n;
        this.ptr = 0;
        this.stream = new String[n];
    }

    public List<String> insert(int idKey, String value) {
        --idKey;
        stream[idKey] = value;
        List<String> res = new ArrayList<>();
        while (ptr < n && stream[ptr] != null) {
            res.add(stream[ptr]);
            ptr++;
        }
        return res;
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream obj = new OrderedStream(n);
 * List<String> param_1 = obj.insert(idKey,value);
 */
// @lc code=end


