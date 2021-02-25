/*
* @lc app=leetcode.cn id=67 lang=cpp
*
* [67] 二进制求和
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a=="0"||b=="0")
            return a=="0"?b:a;
        int n = a.size(),m=b.size();
        int i = n-1,j=m-1,r=0;
        string res;
        while(i>=0||j>=0){
            if(i>=0)r+=a[i--]-'0';
            if(j>=0)r+=b[j--]-'0';
            res.push_back('0'+r%2);
            r/=2;
        }
        while(r){
            res.push_back('0'+r%2);
            r/=2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

