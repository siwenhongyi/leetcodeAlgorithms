/*
* @lc app=leetcode.cn id=676 lang=cpp
*
* [676] 实现一个魔法字典
*/

#include"head.h"
using namespace std;
// @lc code=start
struct letter
{
    bool is_word;
    map<char, letter*> nexts;
    letter():is_word(false){}
};

class MagicDictionary {
private:
    letter* root;
    bool dfs(string& word, int index, bool t, letter* root) {
        if (index == word.size() && !t)
            return root->is_word;
        char ch = word[index];
        if (root->nexts.count(ch) && dfs(word, index + 1, t, root->nexts[ch]))
            return true;
        if (t) {
            for (auto iter : root->nexts) {
                if (iter.first == ch)
                    continue;
                if (dfs(word, index + 1, false, iter.second))
                    return true;
            }
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new letter;
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (auto& iter : dict) {
            auto p = root;
            for (char ch : iter) {
                if (!p->nexts.count(ch))
                    p->nexts[ch] = new letter;
                p = p->nexts[ch];
            }
            p->is_word = true;
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return dfs(word, 0, true, root);
    }
};

// @lc code=end

