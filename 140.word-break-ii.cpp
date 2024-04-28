// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=140 lang=cpp
 * @lcpr version=30122
 *
 * [140] 单词拆分 II
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
class Solution
{
public:
    struct AC_Automaton
    {
        struct Trie
        {
            struct Node
            {
                vector<int> nxt;
                int fail, mark, len;
                Node(int _ = 0)
                {
                    nxt.resize(26);
                    fail = mark = 0;
                    len = _;
                }
            };
            vector<Node> Nodes;
            Trie() { Nodes.resize(1); }
            int Add_Node(int len)
            {
                int res = Nodes.size();
                Nodes.emplace_back(len + 1);
                return res;
            }
            void Add_String(string s,int id)
            {
                int now = 0;
                for (auto c : s)
                {
                    int &nxt = Nodes[now].nxt[c - 'a'];
                    if (!nxt)
                        nxt = Add_Node(Nodes[now].len);
                    now = nxt;
                }
                Nodes[now].mark = id;
            }
        } Tr;
        void Build()
        {
            queue<int> Q;
            for (int i = 0; i < 26; ++i)
                if (Tr.Nodes[0].nxt[i])
                    Q.push(Tr.Nodes[0].nxt[i]);
            while (!Q.empty())
            {
                int u = Q.front();
                Q.pop();
                auto &node = Tr.Nodes[u];
                for (int i = 0; i < 26; ++i)
                {
                    int &p = node.nxt[i];
                    int q = Tr.Nodes[node.fail].nxt[i];
                    if (p)
                    {
                        Tr.Nodes[p].fail = q;
                        Q.push(p);
                    }
                    else
                        p = q;
                }
            }
        }
        vector<vector<string>>ans;
        vector<int>mark;
        vector<int>now_id;
        void Get_Now_Id(string s)
        {
            now_id.resize(s.size() + 1);
            int now = 0;
            for(int i = 0;i < s.size(); ++i)
                now_id[i] = now, now = Tr.Nodes[now].nxt[s[i] - 'a'];
            now_id[s.size()] = now;
        }
        auto Query(string s,int index, const vector<string> &WD)
        {
            if (index == s.size())
                ans.resize(s.size() + 1),
                mark.resize(s.size() + 1);
            if (mark[index])
                return ans[index];
            mark[index] = 1;
            if (index == 0)
            {
                ans[0].push_back("");
                return ans[0];
            }
            int nxt = now_id[index];
            while (nxt)
            {
                auto node = Tr.Nodes[nxt];
                if (node.mark)
                {
                    int pre = index - node.len;
                    if (pre >= 0)
                    {
                        auto res = Query(s, pre, WD);
                        int id = node.mark;
                        for (auto t : res)
                        {
                            t += WD[id - 1];
                            if(index != s.size())
                                t += " ";
                            ans[index].push_back(t);
                        }
                    }
                }
                nxt = node.fail;
            }
            return ans[index];
        }
    } AC;
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int id = 0;
        for (auto t : wordDict)
            AC.Tr.Add_String(t, ++id);
        AC.Build();
        AC.Get_Now_Id(s);
        auto ans = AC.Query(s, s.size(), wordDict);
        return ans;
    }

};
// @lc code=end

/*
// @lcpr case=start
// "catsanddog"\n["cat","cats","and","sand","dog"]\n
// @lcpr case=end

// @lcpr case=start
// "pineapplepenapple"\n["apple","pen","applepen","pine","pineapple"]\n
// @lcpr case=end

// @lcpr case=start
// "catsandog"\n["cats","dog","sand","and","cat"]\n
// @lcpr case=end

 */
