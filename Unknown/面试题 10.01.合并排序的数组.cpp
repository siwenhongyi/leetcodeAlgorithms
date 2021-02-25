/*
* @lc app=leetcode.cn id=面试题 10.01 lang=cpp
*
* [面试题 10.01] 合并排序的数组
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index = m+n-1;
        while(m>0&&n>0){
            auto t = A[m-1]>B[n-1]?A[m-- -1]:B[n-- -1];
            A[index--] = t;
        }
        if(n>0)
            for(int i = 0;i<n;i++)
            A[i] = B[i];
    }
};
// @lc code=end

