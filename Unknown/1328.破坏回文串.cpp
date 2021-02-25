/*
* @lc app=leetcode.cn id=1328 lang=cpp
*
* [1328] 破坏回文串
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.size();
        if(n<=1)
            return "";
        bool b = false;
        int i=0,j = n-1;
        while(i<j){
            if(p[i]!='a'){
                p[i] = 'a';
                b = true;
                break;
            }
            i++;
            j--;
        }
        if(!b){
           p[n-1] = 'b';
            b = true;
        }
        
        return b?p:"";
    }
};
// @lc code=end

