// @before-stub-for-debug-begin
#include <string>
#include <vector>

#include "commoncppproblem649.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  string predictPartyVictory(string pos) {
    queue<int> d, r;
    int n = pos.size();
    for (int i = 0; i < n; i++)
      if (pos[i] == 'D')
        d.push(i);
      else
        r.push(i);
    while (d.size() && r.size()) {
      auto qa = d.front(), qb = r.front();
      d.pop(), r.pop();
      if (qa < qb)
        d.push(qa + n);
      else
        r.push(qb + n);
    }
    return d.empty() ? "Radiant" : "Dire";
  }
};

// @lc code=end
