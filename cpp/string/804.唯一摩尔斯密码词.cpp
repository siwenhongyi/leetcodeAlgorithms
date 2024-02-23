/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  vector<string> book;

 public:
  int uniqueMorseRepresentations(vector<string> &words) {
    if (words.size() < 2) return words.size();
    book = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
            "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
            "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
            "...-", ".--",  "-..-", "-.--", "--.."};
    set<string> res;
    string t;
    for (auto &i : words) {
      for (auto &j : i) {
        t += book[j - 'a'];
      }
      res.insert(t);
      t.clear();
    }
    return res.size();
  }
};

// @lc code=end
