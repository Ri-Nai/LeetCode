/*
 * @lc app=leetcode.cn id=1472 lang=java
 * @lcpr version=30204
 *
 * [1472] 设计浏览器历史记录
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import java.util.ArrayList;
import java.util.List;

class BrowserHistory {
    private List<String> history;
    private int cur;

    public BrowserHistory(String homepage) {
        history = new ArrayList<>();
        history.add(homepage);
        cur = 0;
    }
    
    public void visit(String url) {
        while (history.size() > cur + 1) {
            history.remove(history.size() - 1);
        }
        history.add(url);
        cur++;
    }
    
    public String back(int steps) {
        cur = Math.max(0, cur - steps);
        return history.get(cur);
    }
    
    public String forward(int steps) {
        cur = Math.min(history.size() - 1, cur + steps);
        return history.get(cur);
    }
}

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory obj = new BrowserHistory(homepage);
 * obj.visit(url);
 * String param_2 = obj.back(steps);
 * String param_3 = obj.forward(steps);
 */
// @lc code=end



/*
// @lcpr case=start
// ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"][["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]\n
// @lcpr case=end

 */

