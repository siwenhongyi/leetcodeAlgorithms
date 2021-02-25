/*
* @lc app=leetcode.cn id=434 lang=cpp
*
* [434] 字符串中的单词数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        if(s.empty())
            return 0;
        s.push_back(' ');
        int res = 0,i=0,n=s.size();
        while(i<n){
            if(s[i]==' '){
                i++;
                continue;
            }
            while(i<n&&s[i]!=' ')
                i++;
            res++;
        }
        return res;
    }
};
// @lc code=end

