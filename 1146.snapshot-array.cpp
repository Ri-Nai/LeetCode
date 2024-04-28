/*
 * @lc app=leetcode.cn id=1146 lang=cpp
 * @lcpr version=30122
 *
 * [1146] 快照数组
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
// @lc code=start
class SnapshotArray
{
public:
    SnapshotArray(int length)
    {
        change.resize(length);
        for (auto &v : change)
            v.emplace_back(0, 0);
        snap_id = 0;
    }

    void set(int index, int val)
    {
        if (!change[index].empty() && change[index].back().first == snap_id)
            change[index].pop_back();
        change[index].emplace_back(snap_id, val);
    }

    int snap()
    {
        return snap_id++;
    }

    int get(int index, int snap_id)
    {
        auto &V = change[index];
        auto it = upper_bound(V.begin(), V.end(), make_pair(snap_id + 1, -1));
        --it;
        return it->second;
    }

private:
    vector<vector<pair<int, int>>> change;
    int snap_id;
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=get
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end


/*
// @lcpr case=start
// ["SnapshotArray","set","snap","set","get"][[3],[0,5],[],[0,6],[0,0]]\n
// @lcpr case=end

 */
