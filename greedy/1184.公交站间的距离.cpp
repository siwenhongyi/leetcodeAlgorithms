/*
* @lc app=leetcode.cn id=1184 lang=cpp
*
* [1184] 公交站间的距离
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int sum = 0, n = distance.size();
        for (auto &it : distance)
            sum += it;
        int t = 0, next, i = start;
        while (i != destination)
        {
            t += distance[i];
            i = (i + 1) % n;
        }
        return min(t, sum - t);
    }
};
// @lc code=end

