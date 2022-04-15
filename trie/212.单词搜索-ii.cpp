/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */
#include "head.h"
using namesapce std;
// @lc code=start

struct ChNode {
    bool en, rev;
    string word;
    ChNode* children[26];
    ChNode() :en(false), rev(false) { ios::sync_with_stdio(false); for (auto& it : children) it = nullptr; };
};
ChNode x;
class Trie {
private:
    ChNode* root;
public:
    Trie() {
        root = new ChNode();
    }

    void insert(const string& word, bool rev = false) {
        auto curr = root;
        for (auto& it : word) {
            auto&& nx = curr->children[it - 'a'];
            if (nx == nullptr) { nx = new ChNode(); nx->word = curr->word + it; }
            curr = nx;
        }
        curr->en = true;
        curr->rev = rev;
    }

    bool search(const string& word) {
        auto curr = root;
        for (const auto& it : word) {
            auto&& nx = curr->children[it - 'a'];
            if (nx == nullptr) return false;
            curr = nx;
        }
        return curr->en;
    }

    bool startsWith(const string& word) {
        auto curr = root;
        for (const auto& it : word) {
            auto&& nx = curr->children[it - 'a'];
            if (nx == nullptr) return false;
            curr = nx;
        }
        return curr;
    }
    inline ChNode* getRoot() { return root; }
};

class Solution {
private:
    Trie t;
    int n, m;
    static constexpr array fx{ 0,0,1,-1 }, fy{ -1,1,0,0 };
    vector<string> res;

    void dfs(vector<vector<char>>& board, ChNode* curr, int x, int y) {
        // if(curr->word == "ededa") {
        //     cout<<"here"<<x<< ' '<<y<<endl;
        // }
        if (curr->en) {
            if (curr->rev) reverse(curr->word.begin(), curr->word.end());
            res.push_back(curr->word);
            curr->en = false;
        }
        auto c = board[x][y];
        board[x][y] = '$';
        for (int i = 0; i < 4; ++i) {
            auto&& nx = x + fx[i], && ny = y + fy[i];
            if (nx < 0 || nx == n || ny < 0 || ny == m || board[nx][ny] == '$') continue;
            if (curr->children[board[nx][ny] - 'a']) {
                dfs(board, curr->children[board[nx][ny] - 'a'], nx, ny);
            }
        }
        board[x][y] = c;
    }
public:
    Solution() :t(Trie()) {
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_map<char, int> pos;
        for (auto& it : board) {
            for (auto& jt : it) {
                pos[jt]++;
            }
        }
        for (auto& it : words) {
            for (auto& ch : it) if (pos.count(ch) == 0)continue;
            bool&& rev = pos[it[it.size() - 1]] < pos[it[0]];
            if (rev) reverse(it.begin(), it.end());
            t.insert(it, rev);
        }
        n = board.size(), m = board[0].size();
        auto&& root = t.getRoot();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto&& it = board[i][j] - 'a';
                if (root->children[it] == nullptr) continue;
                dfs(board, root->children[it], i, j);
            }
        }
        return res;
    }
};




// @lc code=end

