/*
 * @lc app=leetcode.cn id=2341 lang=cpp
 *
 * [2341] 数组能形成多少数对 Easy (79.83%)
 */

#include "head.h"
using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& h) {
    unordered_map<int, int> pos;
    int x = 0, y = 0;
    for (auto& it : h) {
      if (++pos[it] % 2) {
        y++;
      } else {
        pos[it] = 0;
        y--;
        x++;
      }
    }
    return {x, y};
  }
};

int main() {
  int fx[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
  int target = 12;
  int l = 0, r = 9;
  while (l < r) {
    int mid = (l + r) / 2;
    if (fx[mid] == target) {
      printf("%d", mid);
      break;
    } else if (fx[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return 0;
}

// @lc code=end
