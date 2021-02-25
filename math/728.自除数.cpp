/*
* @lc app=leetcode.cn id=728 lang=cpp
*
* [728] 自除数
*/

#include"head.h"
using namespace std;
// @lc code=start

class Solution {
public:
     bool fun(int l)
       {
           int a=l,t;
          while(l)
          {
              t=l%10;
              l/=10;
              if (t==0)
                 return false ;
             
              if(a%t!=0)
                  return false;
              
          }return true;
         
       }
    vector<int> selfDividingNumbers(int left, int right) {
        int i;
        vector<int> res;
       for(i = left;i<=right;i++)
           if(fun(i))
               res.push_back(i);
        return res;
      
    }
};
// @lc code=end

