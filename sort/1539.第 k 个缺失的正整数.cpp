/*
* @lc app=leetcode.cn id=1539 lang=cpp
*
* [1539] 第 k 个缺失的正整数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.empty())
            return k;
        arr.insert(arr.begin(), 0);
        int t = 0;
        int con = 0, pre;
        for (int i = 1; i < arr.size(); i++) {
            pre = con;
            con += arr[i] - arr[i - 1] - 1;
            if (con < k)
                continue;
            else if (con == k)
                return arr[i] - 1;
            else
                return arr[i - 1] + (k - pre);
        }
        return arr.back() + (k - con);
    }
}; 
// @lc code=end

