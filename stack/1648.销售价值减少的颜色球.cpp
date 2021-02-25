/*
* @lc app=leetcode.cn id=1648 lang=cpp
*
* [1648] 销售价值减少的颜色球
*/

#include"head.h"
using namespace std;
// @lc code=start
using ll = long long;
ll mod = 1e9 + 7;
class Solution {
public:
    int maxProfit(vector<int> inv, int ord) {
        ll res = 0;
        int n = inv.size();
        inv.push_back(0);//插入0 以免循环中 做边界处理
        sort(inv.begin(), inv.end(), greater<int>());//递减排序
        for (int i = 0; i < n && ord > 0; i++) {
            ll tm = i + 1; //表示这次可以一次卖几个同等价值的
            ll next = inv[i] - inv[i + 1]; //表示 最大数量和第二大数量差多少
            ll count = min(ord / tm, next);
            // 假如此时一批卖3个  则卖的批数就是 总量/一批数量 和 数量差的较小值
            //前者较小表示 这几批可以卖不到和下一个一样多就够了  后者较小表示 卖到一样多还不够
            ll cost = (ll)(inv[i] + inv[i] - count + 1) * count / (ll)2 * tm;
            // (inv[i] + inv[i] - count + 1) / (ll)2 等差数列求和  *tm 有这么多个等差同时求和
            ord -= tm * count; //去掉卖了的
            if (count < next) {
                // 表示 count取了前者  也就是卖不到就够了 把剩下的部分一次性卖完
                cost += (ll)(inv[i] - count) * ord;
                ord = 0;
            }
            res += cost;
            //res %= mod;
        }
        return res % mod;
    }
};

// @lc code=end

