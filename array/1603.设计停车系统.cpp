/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

#include "head.h"
using namespace std;
// @lc code=start
class ParkingSystem {
  int a, b, c;

 public:
  ParkingSystem(int big, int medium, int small) {
    a = big;
    b = medium;
    c = small;
  }
  bool addCar(int carType) {
    if (carType == 1) {
      if (a)
        a--;
      else
        return false;
    } else if (carType == 2) {
      if (b)
        b--;
      else
        return false;
    } else {
      if (c)
        c--;
      else
        return false;
    }
    return true;
  }
};

// @lc code=end
