/*
 * @lc app=leetcode.cn id=1600 lang=cpp
 *
 * [1600] 皇位继承顺序
 */
#include "head.h"
using namespace std;
// @lc code=start
class ThroneInheritance {
  string king;
  vector<string> res;
  unordered_map<string, vector<string>> fam;
  unordered_map<string, string> father;
  unordered_set<string> die;
  unordered_set<string> next;

 public:
  ThroneInheritance(string kingName) {
    res.push_back(kingName);
    king = kingName;
  }
  void birth(string parentName, string childName) {
    fam[parentName].push_back(childName);
    father[childName] = parentName;
  }
  void death(string name) { die.insert(name); }
  string getnext(string& name) {
    if (fam[name].empty()) {
      if (name == king || name == "")
        return "";
      else
        return getnext(father[name]);
    } else {
      for (auto& it : fam[name]) {
        if (next.count(it) == 0)
          if (die.count(it) == 0)
            return it;
          else {
            next.insert(it);
            return getnext(it);
          }
      }
      return getnext(father[name]);
    }
  }
  vector<string> getInheritanceOrder() {
    next = {king};
    res = {king};
    for (int i = 0; i < res.size(); i++) {
      auto t = getnext(res[i]);
      if (!t.empty()) {
        res.push_back(t);
        next.insert(t);
      }
    }
    if (die.count(king)) res.erase(res.begin());
    return res;
  }
};
// @lc code=end
