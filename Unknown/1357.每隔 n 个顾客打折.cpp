/*
* @lc app=leetcode.cn id=1357 lang=cpp
*
* [1357] 每隔 n 个顾客打折
*/

#include"head.h"
using namespace std;
// @lc code=start
class Cashier {
public:
    int c, dis, x;
    vector<int> p;
    unordered_map<int, int> pp;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        c = n;
        dis = discount;
        p.swap(prices);
        for (int i = 0; i < products.size(); i++)
            pp[products[i]] = i;
        x = 0;
    }

    double getBill(vector<int> product, vector<int> amount) {
        x++;
        double res = 0;
        for (int i = 0; i < product.size();i++) {
            res += p[pp[product[i]]] * amount[i];
        }
        if (x == c) {
            res = res - res * double(dis) / 100.0;
            x = 0;
        }
            return res;
    }
};
// @lc code=end

