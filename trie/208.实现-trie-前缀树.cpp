/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include "head.h"
using namesapce std;
// @lc code=start

struct ChNode {
    bool en;
    ChNode* children[26];
    ChNode():en(false) {ios::sync_with_stdio(false);for(auto&it:children) it = nullptr;};
};
ChNode x;
class Trie {
    private:
    ChNode*  root;
public:
    Trie() {
        root = new ChNode();
    }
    
    void insert(const string& word) {
        auto curr = root;
        for(auto&it:word) {
            auto&& nx = curr->children[it-'a'];
            if(nx == nullptr) nx = new ChNode();
            curr = nx;
        }
        curr->en = true;
    }
    
    bool search(const string& word) {
        auto curr = root;
        for(const auto&it:word) {
            auto&& nx = curr->children[it-'a'];
            if(nx == nullptr) return false;
            curr = nx;
        }
        return curr->en;
    }
    
    bool startsWith(const string& word) {
        auto curr = root;
        for(const auto&it:word) {
            auto&& nx = curr->children[it-'a'];
            if(nx == nullptr) return false;
            curr = nx;
        }
        return curr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

