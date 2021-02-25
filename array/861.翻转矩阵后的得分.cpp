/*
* @lc app=leetcode.cn id=861 lang=cpp
*
* [861] 翻转矩阵后的得分
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution
{
private:
    void fun(vector<int> &t)
    {
        for (auto &it : t)
            it = !it;
    }

public:
    int matrixScore(vector<vector<int>> &A)
    {
        if (A.empty() || A[0].empty())
            return 0;
        int n = A.size(), m = A[0].size();
        for (auto &it : A)
            if (!it.front())
                fun(it);
        int cnt;
        for (int j = 1; j < m; j++)
        {
            cnt = 0;
            for (int i = 0; i < n; i++)
                if (A[i][j] == 0)
                    cnt++;
            if (cnt > n / 2)
                for (int k = 0; k < n; k++)
                    A[k][j] = !A[k][j];
        }
        vector<int> t(m);
        t[m - 1] = 1;
        for (int j = m - 2; j >= 0; j--)
            t[j] = t[j + 1] + t[j + 1];
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res += A[i][j] * t[j];
            }
        }
        return res;
    }
};
// @lc code=end

