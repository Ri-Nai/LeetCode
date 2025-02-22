/*
 * @lc app=leetcode.cn id=2506 lang=kotlin
 * @lcpr version=30204
 *
 * [2506] 统计相似字符串对的数目
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
class Solution {
    fun similarPairs(words: Array<String>): Int {
        return words.map {
            var res = 0
            it.forEach {
                res = res or (1 shl (it - 'a'))
            }
            res
        }.groupBy { it }
        .map { it.value.size }
        .sumBy { it * (it - 1) / 2 }
    }
}
// @lc code=end



/*
// @lcpr case=start
// ["aba","aabb","abcd","bac","aabc"]\n
// @lcpr case=end

// @lcpr case=start
// ["aabb","ab","ba"]\n
// @lcpr case=end

// @lcpr case=start
// ["nba","cba","dba"]\n
// @lcpr case=end

 */

