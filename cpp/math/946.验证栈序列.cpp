/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int n = pushed.size();
    if (n <= 1) return true;
    stack<int> st;
    int index = 0;
    for (auto& it : pushed) {
      st.push(it);
      while (st.size() && st.top() == popped[index]) {
        index++;
        st.pop();
      }
    }
    return index == n;
  }
};
// @lc code=end

int main() {
  /*
   * any test cases
   */
  return 0;
}
