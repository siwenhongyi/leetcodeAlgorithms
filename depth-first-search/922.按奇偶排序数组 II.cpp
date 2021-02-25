/*
* @lc app=leetcode.cn id=922 lang=cpp
*
* [922] 按奇偶排序数组 II
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        int id[2] = { 0 };
        vector<int>res(n, 0);
        int  r;
        for (int i = 0; i < n; i++) {
            r = i % 2;
            while (id[r] < n && A[id[r]] % 2 != r)
                id[r]++;
            res[i] = A[id[r]++];
        }
        return res;
    }
};
// @lc code=end

