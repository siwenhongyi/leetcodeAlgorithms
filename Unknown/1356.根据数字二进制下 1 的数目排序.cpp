/*
* @lc app=leetcode.cn id=1356 lang=cpp
*
* [1356] 根据数字二进制下 1 的数目排序
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        if (arr.size() <= 1)
            return arr;
        int n = arr.size();
        vector<int> pos(n,0);
        for (int i = 0; i < n; i++)
            pos[i] = bitset<31>(arr[i]).count();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (pos[j] > pos[j + 1] || (pos[j] == pos[j + 1] && arr[j] > arr[j + 1])) {
                    swap(pos[j], pos[j + 1]);
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        return arr;
    }
};
// @lc code=end

