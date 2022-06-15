/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include "head.h"
using namespace std;
// @lc code=start
// 动态开点 线段树
struct Node {
  int v, lz, ls, rs;
  Node() : v(0), lz(0), ls(0), rs(0) {}
};
class SegTree {
  vector<Node> tr;
  // 最大右边界
  int cnt;
  void push_down(int p, int len) {
    if (!tr[p].ls) tr[p].ls = ++cnt, tr.emplace_back(Node{});
    if (!tr[p].rs) tr[p].rs = ++cnt, tr.emplace_back(Node{});
    if (!tr[p].lz) return;
    int lz = tr[p].lz;
    tr[tr[p].ls].v = lz;
    tr[tr[p].rs].v = lz;
    tr[tr[p].ls].lz = tr[tr[p].rs].lz = lz;
    tr[p].lz = 0;
  }
  void push_up(int p) { tr[p].v = max(tr[tr[p].ls].v, tr[tr[p].rs].v); }

 public:
  SegTree() : tr(1), cnt(0) {}

  // 树险段区间 更新区间 L,R
  void modify(int l, int r, int L, int R, int v, int p = 0) {
    // 树区间完全包含更新区间更新 结束
    if (l <= L && r >= R) {
      // lz=v 表示 子区间 下次需要更新
      tr[p].lz = v, tr[p].v = v;
      return;
    }
    int mid = (L + R - 1) / 2;
    push_down(p, R - L + 1);
    if (mid >= l) modify(l, r, L, mid, v, tr[p].ls);
    if (mid < r) modify(l, r, mid + 1, R, v, tr[p].rs);
    push_up(p);
  }

  int query(int l, int r, int L, int R, int p = 0) {
    if (l <= L && r >= R) return tr[p].v;
    int mid = (L + R - 1) / 2, ret = 0;
    push_down(p, R - L + 1);
    if (mid >= l) ret = max(ret, query(l, r, L, mid, tr[p].ls));
    if (mid < r) ret = max(ret, query(l, r, mid + 1, R, tr[p].rs));
    return ret;
  }
};

class Solution {
  const int N = INT32_MAX;

 public:
  vector<vector<int>> getSkyline(
      vector<vector<int>>& buildings) {  //动态开点线段树
    sort(begin(buildings), end(buildings),
         [&](const auto& a, const auto& b) { return a[2] < b[2]; });
    SegTree tr;
    vector<int> points;
    for (auto& building : buildings) {
      int l = building[0], r = building[1], v = building[2];
      points.push_back(l);
      points.push_back(r);
      tr.modify(l, r - 1, 1, N, v);
    }
    sort(begin(points), end(points));
    points.erase(unique(begin(points), end(points)), end(points));
    vector<vector<int>> ans;
    for (int i = 1; i < points.size(); i++) {
      int q = tr.query(points[i - 1], points[i] - 1, 1, N);
      int j = i + 1;
      while (j < points.size() &&
             tr.query(points[j - 1], points[j] - 1, 1, N) == q)
        j++;
      ans.push_back({points[i - 1], q});
      i = j - 1;
    }
    ans.push_back({points.back(), 0});
    return ans;
  }
};
// @lc code=end
