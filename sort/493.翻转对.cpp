/*
* @lc app=leetcode.cn id=493 lang=cpp
*
* [493] 翻转对
*/

#include"head.h"
using namespace std;
// @lc code=start
using ll = long long;
class Solution {
private:
    int res;
    int  merge_sort(int l, int r, vector<int>& pos) {
        if (l >= r) return  0;
        int mid = l + (r - l) / 2;
        int a = merge_sort(l, mid, pos) + merge_sort(mid + 1, r, pos);
        int s = l, b = mid + 1, index = 0;
        while (s <= mid && b <= r) {
            if ((ll)pos[s] > (ll)pos[b] + pos[b])
                a += mid - s + 1, b++;
            else
                s++;
        }
        vector<int> t(r - l + 1);
        s = l, b = mid + 1;
        while (l <= mid && b <= r) {
            if (pos[l] < pos[b]) t[index] = pos[l++];
            else t[index] = pos[b++];
            index++;
        }
        while (l <= mid)t[index++] = pos[l++];
        while (b <= r)t[index++] = pos[b++];
        index = 0;
        while (s <= r)pos[s++] = t[index++];
        return a;
    }
public:
    int reversePairs(vector<int>& pos) {
        if (pos.size() < 2)
            return  0;
        int n = pos.size();
        res = 0;
        return merge_sort(0, n - 1, pos);
    }
};
// @lc code=end

