/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include "head.h"
using namesapce std;
// @lc code=start
class Solution {
private:
    int row, col, left, right, n;
    vector<vector<string>> res;
   unordered_set<int> used;

    bool  get_status(int x, int y) {
        return ((row & (1 << x)) || (col & (1 << y)) || (left & (1 << (y + x + 8))) || (right & (1 << (x - y + 8))));
    }
    void set_bit(const int& x, const  int& y, bool is_fill) {
        if (is_fill) {
            row |= (1 << x);
            col |= (1 << y);
            left |= (1 << (y + x + 8));
            right |= (1 << (x - y + 8));
        }
        else {
            row ^= (1 << x);
            col ^= (1 << y);
            left ^= (1 << (y + x + 8));
            right ^= (1 << (x - y + 8));

        }
    }
    void dfs(vector<string>& path, const int& x, const int& y, int cnt) {
        path[x][y] = 'Q';
        set_bit(x, y, true);
        cnt--;
        if (!cnt) {
            int uuid = 0, mod = 1;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (path[i][j] == 'Q') {
                        uuid += (j * mod);
                        mod *= 10;
                        break;
                    }
            if (!used.count(uuid)) {
                res.push_back(path);
                used.insert(uuid);
            }
            path[x][y] = '.';
            set_bit(x, y, false);
            return;
        }
        for (int i = x+1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (get_status(i, j)) continue;
                dfs(path, i, j, cnt);
            }
        }
        path[x][y] = '.';
        set_bit(x, y, false);
    }
public:
    Solution() :row(0), col(0), right(0), left(0) {}
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> path(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (used.count(i * n + j)) continue;
                dfs(path, i, j, n);
            }
        }
        return res;
    }
};
// @lc code=end

