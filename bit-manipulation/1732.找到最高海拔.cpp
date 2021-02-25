/*
* @lc app=leetcode.cn id=1732 lang=cpp
*
* [1732] 找到最高海拔
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int pr = 0;
        for (int i = 0; i < gain.size(); i++) {
            //cout<<pr<<endl;
            pr = pr + gain[i];
            res = max(res, pr);
        }
        return res;
    }
};

// @lc code=end

