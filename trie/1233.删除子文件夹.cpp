/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

#include "head.h"
using namespace std;

// @lc code=start

struct filder {
  bool is_last;
  unordered_map<string, filder*> sons;
  filder() : is_last(false), sons() {}
  bool insert(int index, const vector<string>& tree) {
    if (is_last) return false;
    if (index == tree.size()) {
      is_last = true;
      return true;
    }
    auto next_f_name = tree[index++];
    filder* next_f_node = nullptr;
    if (sons.count(next_f_name)) {
      next_f_node = sons[next_f_name];
    } else {
      next_f_node = new filder();
      sons[next_f_name] = next_f_node;
    }
    return next_f_node->insert(index, tree);
  }
};

class Solution {
  filder dict;
  void get_tree(const string& tree_string, vector<string>& res) {
    stringstream ss;
    string s;
    char d = '/';
    ss.str(tree_string.substr(1));
    while (getline(ss, s, d)) {
      res.push_back(s);
    }
  }

 public:
  vector<string> removeSubfolders(vector<string>& f) {
    auto&& cmp = [&](const string& s, const string& t) {
      auto &&l = s.size(), &&r = t.size();
      if (l != r) return l < r;
      return s < t;
    };
    sort(f.begin(), f.end(), cmp);
    vector<string> res, temp;
    for (const auto& it : f) {
      temp.clear();
      get_tree(it, temp);
      if (dict.insert(0, temp)) res.push_back(it);
    }
    return res;
  }
};
// @lc code=end
