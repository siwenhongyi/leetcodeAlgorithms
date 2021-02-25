/*
* @lc app=leetcode.cn id=1652 lang=cpp
*
* [1652] 拆炸弹
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:

    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0)
            return vector<int>(code.size(), 0);
        int op = k > 0 ? 1 : -1, n = code.size();
        k = abs(k);
        vector<int> res(n,0);
        for (int i = 0; i < n; i++) {
            int cnt = 0, ans = 0, x;
            for (int j = i + op; cnt < k; j += op) {
                x = (j + n) % n;
                ans += code[x], cnt++;
            }
            res[i] = ans;
        }
        return res;
    }
};
// @lc code=end

