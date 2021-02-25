/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string toGoatLatin(string S) {
    unordered_map<char, bool> book = {{'a', 1}, {'o', 1}, {'e', 1}, {'i', 1},
                                      {'u', 1}, {'A', 1}, {'O', 1}, {'E', 1},
                                      {'I', 1}, {'U', 1}};
    string res, item, t(1, 'a');
    stringstream ss(S);
    while (getline(ss, item, ' ')) {
      if (!book[item.front()]) item = item.substr(1) + item.front();
      // item.push_back(item.front());
      // item.erase(item.begin());

      res += item + "ma" + t + ' ';
      t.push_back('a');
    }
    res.pop_back();
    return res;
  }
};

// @lc code=end
