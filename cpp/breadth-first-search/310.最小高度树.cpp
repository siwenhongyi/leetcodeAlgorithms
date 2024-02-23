/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

#include "head.h"
using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};
    vector<bool> tf(n, true);
    vector<int> pos(n, 0);
    int t = n;
    while (t > 2) {
      for (int i = 0; i < edges.size(); i++) {
        int x = edges[i][0], y = edges[i][1];
        if (!tf[x] || !tf[y]) continue;
        pos[x]++;
        pos[y]++;
      }
      //	int m = INT_MAX;
      //	for (int i = 0; i < n; i++)
      //		if (tf[i] && pos[i] < m)
      //			m = pos[i];
      int cou = 0;
      for (int i = 0; i < n; i++)
        if (tf[i] && pos[i] == 1) {
          cou++;
          tf[i] = false;
        }
      t -= cou;
      fill(pos.begin(), pos.end(), 0);
    }
    pos.clear();
    for (int i = 0; i < n; i++) {
      if (tf[i]) pos.push_back(i);
      if (pos.size() == 2) break;
    }
    return pos;
  }
  //	vector<int> res;
  //	for (int i = 0; i < n; i++)
  //		res.push_back(i);
  //	vector<bool> tf(n, true);
  //	vector<int> pos(n, 0);
  //	while (n>2)
  //	{
  //		for (int i = 0; i < n; i++) {
  //			if (!tf[i])
  //				continue;
  //			for (int j = 0; j < n; j++) {
  //				if (!tf[j] || !book[i][j])
  //					continue;
  //				pos[i]++;
  //			}
  //		}
  //		for (auto i : res)
  //			for (auto j : res)
  //				if (book[i][j])
  //					pos[i]++;
  //		int m = INT_MAX;
  //		auto it = res.begin();
  //		while (it != res.end()) {
  //			if (pos[*it] < m)
  //				m = pos[*it];
  //			it++;
  //		}
  //		it = res.begin();
  //		while (it != res.end())
  //			if (pos[*it] == m)
  //				tf[*it] = false;
  //			else
  //				it++;
  //	}
  //	return res;
  //}
};
// @lc code=end
