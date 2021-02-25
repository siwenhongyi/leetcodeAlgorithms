/*
* @lc app=leetcode.cn id=1534 lang=cpp
*
* [1534] 统计好三元组
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        if (arr.size() <= 2)
            return 0;
        int res = 0;
        int i, j, k, n = arr.size();
        for(i = 0; i < n - 2; i++) {
            for (j = i + 1; j < n - 1; j++) {
                for (k = j + 1; k < n; k++) {
                    if (abs(arr[i] - arr[j])<= a &&
                        abs(arr[j] - arr[k]) <= b &&
                        abs(arr[i] - arr[k]) <= c) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

