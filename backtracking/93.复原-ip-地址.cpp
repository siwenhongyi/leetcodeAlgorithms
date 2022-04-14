/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include "head.h"
using namesapce std;
// @lc code=start
#include <algorithm>

class Solution {
private:
    using ull = unsigned long long;
    int n;
    vector<int> path;
    vector<string> res;
    void dfs(const string& s, int index) {
        auto&& l = path.size();
        if (l == 4 || index == n) {
            if (path.size() == 4 && index == n) {
                auto flag = false;
                string s;
                for (auto& it : path) {
                    if (flag) s += '.';
                    s += to_string(it);
                }
                res.emplace_back(s);
            }
        }
        auto&& has_length = 4 - l;
        if (l == 3) {
            if (has_length > 3 || (has_length > 1 && s[index] == '0')) return;
            auto&& en = stoi(s.substr(index));
            if (en > 255) return;
            path.push_back(en);
            dfs(s, n);
            path.pop_back();
            return;
        }
        if (s[index] == '0') {
            path.push_back(0);
            dfs(s, index + 1);
            path.pop_back();
        }
        else {
            auto&& min_length = max(1, int((n - index) - (has_length - 1) * 3)), && max_length = min(3, int((n - index) - (has_length - 1)));
            int temp = 0;
            for (int i = index; i <= max_length; i++) {
                temp = temp * 10 + s[i] - '0';
                if (i < min_length) continue;
                path.push_back(temp);
                dfs(s, i+1);
                path.pop_back();
            }
        }
    }
public:
    // 复原去重ip地址
    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        if (n < 4 || n>12) return {};
        dfs(s, 0);
        return res;
    }
};

// @lc code=end

