/*
 * @lc app=leetcode.cn id=851 lang=cpp
 *
 * [851] 喧闹和富有
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 private:
  struct Person {
    vector<Person*> biggers;
    int voice, id;
    Person(int val, int _id) : voice(val), id(_id), biggers({}){};
  };
  unordered_map<int, Person*> ch;
  Person* dfs(Person*& p) {
    auto&& id = p->id;
    if (ch.count(id)) return ch[id];
    auto res = p;
    // res = p->voice < res->voice ? p : res;
    for (auto&& bigger : p->biggers) {
      auto&& f = dfs(bigger);
      if (f->voice < res->voice) res = f;
    }
    ch[p->id] = res;
    return res;
  }

 public:
  vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size(), t, item;
    vector<Person*> persons;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
      persons.emplace_back(new Person(quiet[i], i));
    }
    for (auto& it : richer) {
      auto &&richer_id = it.front(), &&bigger_id = it.back();
      persons[bigger_id]->biggers.emplace_back(persons[richer_id]);
    }
    for (int i = 0; i < n; i++) {
      auto&& f = dfs(persons[i]);
      res[i] = f->id;
    }
    for (auto& it : persons) delete it;
    return res;
  }
};
// @lc code=end
