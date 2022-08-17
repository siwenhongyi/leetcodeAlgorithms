/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  int reachableNodes(int n, vector<vector<int>>& edges,
                     vector<int>& restricted) {
    queue<int> q;
    q.push(0);
    unordered_set<int> rest(restricted.begin(), restricted.end());
    rest.insert(0);
    int res = 0;
    vector<vector<int>> e(n);
    for (auto& it : edges) {
      e[it[0]].push_back(it[1]);
      e[it[1]].push_back(it[0]);
    }
    while (q.size()) {
      res++;
      auto qa = q.front();
      q.pop();
      for (auto& it : e[qa]) {
        if (!rest.count(it)) {
          q.push(it);
          rest.insert(it);
        }
      }
    }
    return res;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
