/*
* @lc app=leetcode.cn id=204 lang=cpp
*
* [204] 计数质数
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)return 0;
        vector<unsigned int> p(n / 32 + 1, 0xffffffff);
        int res = 0;
        int c, r;
        //string x;
        for (int i = 2; i < n; i++) {
            c = i / 32, r = i % 32;
            //x = bitset<32>(p[c]).to_string();
            if ((p[c] & (1 << r)) == 0)
                continue;
            res++;
            //cout << i << ' ';
            long long int j = (long long)i * i;
            while (j < n) {
                c = j / 32, r = j % 32;
                p[c] &= (0xffffffff ^ (1 << r));
                //x = bitset<32>(p[c]).to_string();
                j += i;
            }
        }
        return res;

    }
};
// @lc code=end

