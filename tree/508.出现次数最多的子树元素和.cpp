/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

#include "head.h"
using namespace std;
// @lc code=start
typedef pair<int, int> pp;

class Solution {
  map<int, int> p;

 public:
  int dfs(TreeNode* root) {
    if (!root) return 0;
    int r = dfs(root->right);
    int l = dfs(root->left);
    r += l + root->val;
    p[r]++;
    return r;
  }
  vector<int> findFrequentTreeSum(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    p[root->val + dfs(root->left) + dfs(root->right)]++;
    int m = 0;
    for (auto& i : p)
      if (i.second > m) m = i.second;
    for (auto& i : p)
      if (i.second == m) res.push_back(i.first);
    return res;
    //优先队列 40ms 48% 上面的两个遍历24ms 94.81%
    // priority_queue<pp, vector<pp>, less<pp>> q;
    // for (auto& i : p) {
    //	q.push(make_pair(i.second, i.first));
    //}
    // int key = q.top().first;
    // res.push_back(q.top().second);
    // q.pop();
    // while (true) {
    //	if (q.top().first != key)
    //		break;
    //	res.push_back(q.top().second);
    //	q.pop();
    //}
  }
};
// @lc code=end
