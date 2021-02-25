/*
* @lc app=leetcode.cn id=1352 lang=cpp
*
* [1352] 最后 K 个数的乘积
*/

#include"head.h"
using namespace std;
// @lc code=start
typedef long long int ll;
class ProductOfNumbers {
    vector<ll> pr;
    int n, last;
public:
    ProductOfNumbers() {
        pr.push_back(1);
        n = 0;
        last = -1;
    }

    void add(int num) {
        if (!num) {
            pr.push_back(1);
            last = n;
        }
        else 
            pr.push_back(pr.back() * num);
        
        n++;
        
    }

    int getProduct(int k) {
        int first = n - k;
        if (first <= last)
            return 0;
        else {
            ll x = ll(pr.back()) / pr[first];
            return x;
        }
    }
};

// @lc code=end

