/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> splitIntoFibonacci(string S) {
    int strSize = S.size();
    //题干要求F.length >= 3，则S串的长度必须不小于3，拆分出的元素数才可能大于3
    if (strSize < 3) {
      return {};
    }
    if (S[0] == '0') {
      //将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0
      //本身
      vector<int> tempRes;
      tempRes.push_back(0);  //当S[0] == ‘0’,则它只能当作为数列的第一个元素
      //然后在S[1, S.size() - 1]这一段切出第二个元素
      for (int lenTwo = 1; lenTwo < strSize - 1 && lenTwo < 11; ++lenTwo) {
        //注意0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32
        //位有符号整数类型），元素最大长度为10
        long long tempValTwo = stoll(S.substr(1, lenTwo));
        if (tempValTwo < INT_MAX) {
          tempRes.push_back((int)tempValTwo);  //放入第二个元素
          //递推求下面的元素
          if (helper(S, tempRes, lenTwo + 1)) {
            return tempRes;
          }
          tempRes.pop_back();
        }
      }
    } else {
      vector<int> tempRes;
      for (int lenOne = 1; lenOne < strSize - 1 && lenOne < 11; ++lenOne) {
        //穷举第一个元素
        long long tempValOne = stoll(S.substr(0, lenOne));
        if (tempValOne < INT_MAX) {
          tempRes.push_back((int)tempValOne);
          //下面寻找第二个元素
          if (S[lenOne] == '0') {
            //特殊情况，第二个元素只能是0
            tempRes.push_back(0);
            //递推求下面的元素
            if (helper(S, tempRes, lenOne + 1)) {
              return tempRes;
            }
            tempRes.pop_back();
          } else {
            for (int lenTwo = 1; lenTwo < strSize - lenOne && lenTwo < 11;
                 ++lenTwo) {
              //穷举切割第二个元素
              long long tempValTwo = stoll(S.substr(lenOne, lenTwo));
              if (tempValTwo < INT_MAX) {
                tempRes.push_back((int)tempValTwo);  //放入第二个元素
                //递推求下面的元素
                if (helper(S, tempRes, lenOne + lenTwo)) {
                  return tempRes;
                }
                tempRes.pop_back();
              }
            }
          }
          tempRes.pop_back();
        }
      }
    }
    return {};
  }
  //按照F[i] = F[i - 2] + F[i - 1]规则，求出下一个个元素
  bool helper(string &S, vector<int> &tempRes, int index) {
    if (index == S.size()) {
      return tempRes.size() > 2;  //题干要求F.length >= 3
    } else {
      //推测出的下一个元素
      int tempValthree = (long)tempRes.back() + tempRes[tempRes.size() - 2];
      tempRes.push_back(tempValthree);
      string nextStr = to_string(tempRes.back());
      // S[index, S.size() - 1]这一段必须以nextStr打头，才有必要继续往下搜索
      if (S.substr(index, nextStr.size()) == nextStr &&
          helper(S, tempRes, index + nextStr.size())) {
        return true;
      }
      tempRes.pop_back();
      return false;
    }
  }
};
// @lc code=end
