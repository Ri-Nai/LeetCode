/*
 * @lc app=leetcode.cn id=1206 lang=kotlin
 * @lcpr version=30204
 *
 * [1206] 设计跳表
 */


// @lcpr-template-start

// @lcpr-template-end
// @lc code=start

import kotlin.random.Random

class Skiplist() {

    class SkiplistNode {
        var num: Int
        var forward: Array<SkiplistNode?>

        constructor(num: Int, maxLevel: Int) {
            this.num = num
            this.forward = Array(maxLevel) { null }
        }
    }

    val MAX_LEVEL = 32
    val P_FACTOR = 0.25
    var head: SkiplistNode
    var level: Int
    var random: Random

    init {
        head = SkiplistNode(-1, MAX_LEVEL)
        level = 0
        random = Random.Default
    }

    private fun randomLevel(): Int {
        var lv = 1
        while (random.nextDouble() < P_FACTOR && lv < MAX_LEVEL) {
            lv++
        }
        return lv
    }

    fun search(target: Int): Boolean {
        var curr = head
        for (i in level - 1 downTo 0) {
            while (curr.forward[i] != null && curr.forward[i]!!.num < target) {
                curr = curr.forward[i]!!
            }
        }
        return curr.forward[0]?.let { it.num == target } ?: false
    }

    fun add(num: Int) {
        val update = Array<SkiplistNode?>(MAX_LEVEL) { head }
        var curr = head

        for (i in level - 1 downTo 0) {
            while (curr.forward[i] != null && curr.forward[i]!!.num < num) {
                curr = curr.forward[i]!!
            }
            update[i] = curr
        }
        val lv = randomLevel()
        level = max(level, lv)
        val newNode = SkiplistNode(num, lv)
        for (i in 0 until lv) {
            newNode.forward[i] = update[i]!!.forward[i]
            update[i]!!.forward[i] = newNode
        }
    }

    fun erase(num: Int): Boolean {
        val update = Array<SkiplistNode?>(MAX_LEVEL) { null }
        var curr = head
        for (i in level - 1 downTo 0) {
            while (curr.forward[i] != null && curr.forward[i]!!.num < num) {
                curr = curr.forward[i]!!
            }
            update[i] = curr
        }
        curr = curr.forward[0]?.let { it } ?: return false
        if (curr == null || curr.num != num) {
            return false
        }
        for (i in 0 until level) {
            if (update[i]!!.forward[i] != curr) {
                break
            }
            update[i]!!.forward[i] = curr.forward[i]
        }
        while (level > 1 && head.forward[level - 1] == null) {
            level--
        }
        return true
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * var obj = Skiplist()
 * var param_1 = obj.search(target)
 * obj.add(num)
 * var param_3 = obj.erase(num)
 */
// @lc code=end



