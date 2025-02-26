/*
 * @lc app=leetcode.cn id=2502 lang=java
 * @lcpr version=30204
 *
 * [2502] 设计内存分配器
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Allocator {
    int[] memory;
    public Allocator(int n) {
        memory = new int[n];
        for (int i = 0; i < n; i++) {
            memory[i] = 0;
        }
    }
    public int allocate(int size, int mID) {
        int cnt = 0;
        for (int i = 0; i < memory.length; i++) {
            if (memory[i] == 0) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == size) {
                Arrays.fill(memory, i - size + 1, i + 1, mID);
                return i - size + 1;
            }
        }
        return -1;
    }
    public int freeMemory(int mID) {
        int cnt = 0;
        for (int i = 0; i < memory.length; i++) {
            if (memory[i] == mID) {
                cnt++;
                memory[i] = 0;
            }
        }
        return cnt;
    }
}
/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator obj = new Allocator(n);
 * int param_1 = obj.allocate(size,mID);
 * int param_2 = obj.freeMemory(mID);
 */
// @lc code=end



