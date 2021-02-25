/*
* @lc app=leetcode.cn id=551 lang=cpp
*
* [551] 学生出勤记录 I
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkRecord(string s)
    {
        int a = 0;
        int i = 0, n = s.size();
        while (a < 2 && i < n)
        {

            if (s[i] == 'A')
                a++;
            else if (s[i] == 'L' && i < n - 2 && s[i + 1] == 'L' && s[i + 2] == 'L')
                return false;
            i++;
        }
        return a < 2;
    }
};
// @lc code=end

