/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
#include "head.h"
using namesapce std;
// @lc code=start
class Solution {
public:
    string fractionToDecimal(int a, int b) {
        if(a == 0) return "0";
        string res((((a>0)^(b>0))?"-":""));
        a = abs(a);
        b = abs(b);
        long long r = a/b, x = a%b;
        res += to_string(r);
        if(x == 0) return res;
        res += ".";
        unordered_map<long long, int> pos;
        while(x) {
            if(pos.find(x) != pos.end() ) {
                res.insert(pos[x],"(");
                res += ")";
                break;
            } else {
                pos[x] = res.size();
                x *= 10;
                res += '0' + x/b;
                x=x%b;
            }
        }
        return res;
    }
};
// @lc code=end

