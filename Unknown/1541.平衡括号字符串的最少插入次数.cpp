/*
* @lc app=leetcode.cn id=1541 lang=cpp
*
* [1541] 平衡括号字符串的最少插入次数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int cur = 0, cnt = 0;
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == '(')
            {
                if (cnt == 1)
                {
                    cnt = 0; ans++;
                    if (cur > 0) cur--;
                    else ans++;
                }
                cur++;
            }
            else if (s[i] == ')')
            {
                cnt++;
                if (cnt == 2)
                {
                    cnt = 0;
                    if (cur > 0) cur--;
                    else ans++;
                }
            }
        }
        if (cnt == 1)
        {
            cnt = 0; ans++;
            if (cur > 0) cur--;
            else ans++;
        }
        ans += cur * 2;
        return ans;
    }
}; 

// @lc code=end

