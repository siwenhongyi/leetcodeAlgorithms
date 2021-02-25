/*
* @lc app=leetcode.cn id=1598 lang=cpp
*
* [1598] 文件夹操作日志搜集器
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int deep = 0;
        for (auto& it : logs) {
            if (it == "../")
                deep = deep > 0 ? deep - 1 : 0;
            else if (it == "./")
                continue;
            else
                deep++;
        }
        return deep;
    }
};

// @lc code=end

