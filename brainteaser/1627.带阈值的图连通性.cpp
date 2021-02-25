/*
* @lc app=leetcode.cn id=1627 lang=cpp
*
* [1627] 带阈值的图连通性
*/

#include"head.h"
using namespace std;
// @lc code=start
class UF
{
public:
    UF(int _n) :n(_n), f(_n), sz(_n) { iota(f.begin(), f.end(), 0); }
    ~UF() {}
public:
    int findset(int x) {
        return f[x] == x ? x : f[x] = findset(f[x]);
    }
    void unint(int x, int y) {
        x = findset(x), y = findset(y);
        if (x != y) {
            if (sz[x] < sz[y])
                swap(x, y);
            f[y] = x;
            sz[x] += sz[y];
        }
    }
    bool one(int x, int y) { return findset(x) == findset(y); }
private:
    vector<int> f, sz;
    int n;
};


class Solution {
public:
    vector<bool> areConnected(int n, int t, vector<vector<int>>& queries) {
        UF c(n + 1);
        for (int i = t + 1; i <= n; i++) {
            for (int p = i, q = i + i; q <= n; p += i, q += i)
                c.unint(p, q);
        }
        vector<bool> res;
        for (auto& it : queries) {
            res.push_back(c.one(it[0], it[1]));
        }
        return res;
    }
};
// @lc code=end

