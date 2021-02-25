/*
* @lc app=leetcode.cn id=996 lang=cpp
*
* [996] 正方形数组的数目
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
    vector<int> g[20], b;
int dp[15][5000];
int n;

public:
int dfs(int x,int y){
        if (y == (1 << n) - 1)return 1;
    if (dp[x][y] != -1)return dp[x][y];
    dp[x][y] = 0;
    unordered_set<int>s;
    for (auto i : g[x])
        if (((1 << i) & y) == 0 && !s.count(b[i])) {
            dp[x][y] += dfs(i, (1 << i) | y);
            s.insert(b[i]);
        }
    return dp[x][y];

}
    int numSquarefulPerms(vector<int>& a) {
    b = a;
    n = a.size();
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = i + 1; j < a.size(); j++) {
            int sum = a[i] + a[j];
            int sq = sqrt(sum);
            if (sq * sq == sum) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int ans = 0;
    unordered_set<int>s;
    for (int i = 0; i != n; i++) {
        if (!s.count(a[i]))ans += dfs(i, 1 << i);
        s.insert(a[i]);
    }
    return ans;

    }
};
// @lc code=end

