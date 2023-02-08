/*
 * @lc app=leetcode.cn id=1233 lang=cpp
 *
 * [1233] 删除子文件夹
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
  // 在 trie文件夹下有字典树解法
 public:
  vector<string> removeSubfolders(vector<string>& f) {
    sort(f.begin(), f.end());
    int index = 0, n = f.size();
    vector<string> res(1, f.front());
    for (int i = 1; i < n; i++) {
      auto& curr = f[i];
      auto& pre = res.back();
      auto&& find_index = curr.find(pre);
      /*
      若为子文件夹 则 find_index == 0
      因此下面判断可以简化
      if (find_index == 0||curr[find_index + pre.size()]!='/')
      */
      // cout << find_index << endl;
      if (find_index == 0 && curr[pre.size()] == '/') continue;
      res.push_back(curr);
    }
    return res;
  }
};
// @lc code=end
