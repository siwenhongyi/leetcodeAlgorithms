/*
* @lc app=leetcode.cn id=36 lang=cpp
*
* [36] 有效的数独
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
private:
    vector<vector<int>> pos;
    unordered_set<int> cnt;
    bool row() {
        for (auto&it:pos) {
            cnt.clear();
            for (auto& iter : it)
                if (iter) {
                    if (cnt.count(iter))
                        return false;
                    cnt.insert(iter);
                }
        }
        return true;
    }
    bool col() {
        for (int i = 0; i < 9; i++) {
            cnt.clear();
            for (int j = 0; j < 9; j++) 
                if (pos[j][i]) {
                    if (cnt.count(pos[j][i]))
                        return false;
                    cnt.insert(pos[j][i]);
                }
        }
        return true;
    }
    bool sub() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cnt.clear();
                for (int x = j * 3; x < j * 3 + 3; x++) {
                    for (int y = i * 3; y < i * 3 + 3; y++) {
                        if (pos[x][y]) {
                            if (cnt.count(pos[x][y]))
                                return false;
                            cnt.insert(pos[x][y]);
                        }
                    }
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (auto& it : board) {
            vector<int> t;
            for (auto& iter : it)
                t.push_back(iter == '.' ? 0 : iter - '0');
            pos.push_back(t);
        }
        return row() && col() && sub();
    }
};
// @lc code=end

