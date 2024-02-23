/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include "head.h"
using namespace std;
// @lc code=start
// 动态开点 线段树
class SegTree {
 private:
  using ll = long long;
  static const ll N = INT32_MAX;
  struct SegNode {
    // 左右子树节点下标
    // 不存储具体的 区间起点结束点
    ll l, r;
    ll lazy, value;
    /* data */
    SegNode() : l(0), r(0), lazy(0), value(0) {}
    void check() {
      cout << l << ' ' << r << ' ' << lazy << ' ' << value << endl;
    }
  };
  vector<SegNode> nodes;
  ll cnt;
  // 除了根节点 不建树 使用的时候再建
  void push_up(ll i) {
    auto&& curr = nodes[i];
    curr.value = max(nodes[curr.l].value, nodes[curr.r].value);
  }
  // 节点i的修改向下传递，len为传递区间宽度
  void push_down(ll i, ll len) {
    if (!nodes[i].l) {
      nodes[i].l = cnt++;
      nodes.emplace_back(SegNode{});
    }
    if (!nodes[i].r) {
      nodes[i].r = cnt++;
      nodes.emplace_back(SegNode{});
    }
    auto& curr = nodes[i];
    if (!curr.lazy) return;
    nodes[curr.l].value = nodes[curr.r].value = curr.lazy;
    nodes[curr.l].lazy = nodes[curr.r].lazy = curr.lazy;
    curr.lazy = 0;
  }

 public:
  SegTree() : cnt(1), nodes(1) {}
  void check() {
    for (auto& it : nodes) it.check();
  }
  // 更新区间(L,R), 当前节点的线段区间是(l,r)
  void update(ll l, ll r, ll L, ll R, ll v, ll i = 0) {
    // //无交集
    // if (L > r || R < l) return;

    // 节点区间包含更新区间，直接更新
    if (l <= L && r >= R) {
      // lazy如果不能保证更新时和为0 应该变为+= 且做额外处理防止子节点多次更新
      nodes[i].value = nodes[i].lazy = v;
      return;
    }
    // 有交集
    ll mm = (L + R - 1) / 2;
    push_down(i, R - L + 1);
    if (mm >= l) update(l, r, L, mm, v, nodes[i].l);
    if (mm < r) update(l, r, mm + 1, R, v, nodes[i].r);
    push_up(i);
  }

  ll query(ll l, ll r, ll L, ll R, ll i = 0) {
    // //无交集
    // if (L > r || R < l) return 0;
    // 节点区间包含更新区间
    if (L >= l && R <= r) return nodes[i].value;
    // 先更新
    ll res = 0;
    ll mm = (L + R - 1) / 2;
    push_down(i, R - L + 1);
    if (mm >= l) res = max(res, query(l, r, L, mm, nodes[i].l));
    if (mm < r) res = max(res, query(l, r, mm + 1, R, nodes[i].r));
    return res;
  }
};

class Solution {
  const int N = INT32_MAX;

 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    auto&& cmp = [&](const vector<int>& s, const vector<int>& t) {
      return s[2] < t[2];
    };
    sort(buildings.begin(), buildings.end(), cmp);
    vector<vector<int>> res;
    vector points(0, 0);
    SegTree se;
    for (const auto& it : buildings) {
      int l = it[0], r = it[1], v = it[2];
      points.push_back(l);
      points.push_back(r);
      se.update(l, r - 1, 1, N, v);
    }
    // se.check();
    sort(points.begin(), points.end());
    points.erase(unique(begin(points), end(points)), end(points));
    auto&& n = points.size();
    for (int i = 1, j; i < n; i++) {
      int qa = se.query(points[i - 1], points[i] - 1, 1, N);
      j = i + 1;
      while (j < n && se.query(points[j - 1], points[j] - 1, 1, N) == qa) j++;
      res.push_back({points[i - 1], qa});
      i = j - 1;
    }
    res.push_back({points.back(), 0});
    return res;
  }
};

// @lc code=end
//测试
int main() {
  Solution s;
  vector<vector<int>> buildings = {
      {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  vector<vector<int>> res = s.getSkyline(buildings);
  cout << "res\n";
  for (const auto& it : res) {
    cout << it[0] << ' ' << it[1] << endl;
  }
  return 0;
}
