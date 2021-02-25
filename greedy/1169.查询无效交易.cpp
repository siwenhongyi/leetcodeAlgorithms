/*
 * @lc app=leetcode.cn id=1169 lang=cpp
 *
 * [1169] 查询无效交易
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  struct MyStruct {
    string name, city, all;
    int time, money;
  };
  vector<string> invalidTransactions(vector<string>& transactions) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int size = transactions.size();
    vector<struct MyStruct> tmp(size);
    vector<bool> flag(size, true);
    vector<string> res;

    for (int i = 0; i < size; ++i) {
      vector<string> data(5);
      stringstream ss(transactions[i]);
      int j = 0;
      while (getline(ss, data[j++], ','))
        ;
      tmp[i].name = data[0];
      tmp[i].time = stoi(data[1]);
      tmp[i].money = stoi(data[2]);
      tmp[i].city = data[3];
      tmp[i].all = transactions[i];
    }

    sort(tmp.begin(), tmp.end(),
         [](struct MyStruct& a, struct MyStruct& b) -> bool {
           if (a.name == b.name) {
             if (a.city == b.city) return a.time < b.time;
             return a.city < b.city;
           }
           return a.name < b.name;
         });

    for (int i = 0; i < size; ++i) {
      if (tmp[i].money > 1000) flag[i] = false;
      int j = i + 1;
      while (j < size && tmp[i].name == tmp[j].name) {
        if (tmp[j].money > 1000) flag[j] = false;
        if (tmp[j].city != tmp[i].city && abs(tmp[j].time - tmp[i].time) <= 60)
          flag[j] = flag[i] = false;
        ++j;
      }
      if (flag[i]) continue;
      res.push_back(tmp[i].all);
    }
    return res;
  }
};
// @lc code=end
