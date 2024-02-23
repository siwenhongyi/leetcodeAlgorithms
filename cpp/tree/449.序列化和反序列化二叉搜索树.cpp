/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */
#include "head.h"
using namespace std;
// @lc code=start
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) return "";
    string res;
    int size_t = 1;
    queue<TreeNode*> q;
    q.push(root);
    while (size_t) {
      size_t = q.size();
      while (size_t--) {
        auto qa = q.front();
        q.pop();
        if (qa) {
          res += to_string(qa->val) + '!';
          q.push(qa->left);
          q.push(qa->right);
        } else
          res += "#";
      }
      size_t = q.size();
    }
    // cout << res << endl;
    return res;
    // size_t = res.size();
    // char* ret = new char[size_t+1];
    // strcpy(ret, res.c_str());
    // return ret;
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string str) {
    if (str.empty() || str[0] == '#') return nullptr;
    int len = str.size();
    int i = 0, x = 0;
    queue<TreeNode*> q, p;
    while (i < len && str[i] != '!') x = x * 10 + str[i++] - '0';
    i++;
    auto res = new TreeNode(x);
    q.push(res);
    while (i < len) {
      while (q.size()) {
        auto& qa = q.front();
        for (int j = 0; j < 2; j++) {
          if (str[i] == '#') {
            i++;
          } else {
            x = 0;
            while (i < len && str[i] != '!') x = x * 10 + str[i++] - '0';
            auto xx = new TreeNode(x);
            if (j)
              qa->right = xx;
            else
              qa->left = xx;
            p.push(xx);
            i++;
          }
        }
        q.pop();
      }
      q.swap(p);
    }
    return res;
  }
};
// @lc code=end
