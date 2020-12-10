/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

#inlude "head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int c[2] = {0, 0};
        int t, cnt;
        for (auto &it : bills)
        {
            if (it != 20)
                c[it == 5 ? 0 : 1]++;
            t = it - 5;
            if (t > 5 && c[1] > 0)
            {
                cnt = min(c[1], t / 10);
                t -= cnt * 10, c[1] -= cnt;
            }
            if (t > 0 && c[0] > 0)
            {
                cnt = min(c[0], t / 5);
                t -= cnt * 5, c[0] -= cnt;
            }
            if (t)
                return false;
        }
        return true;
    }
};
// @lc code=end
