/*
* @lc app=leetcode.cn id=1200 lang=cpp
*
* [1200] 最小绝对差
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int m=(1<<31)-1,n=arr.size();
        vector<vector<int> > v;
        unordered_map<int,int> pos;
        sort(arr.begin(),arr.end());
        for(int i = 0;i<n;i++){
            pos[arr[i]]++;
            if(i!=n-1&&abs(arr[i+1]-arr[i])<m)
                m=abs(arr[i+1]-arr[i]);
        }
        for(int i = 0;i<n;i++){
            if(pos[arr[i]+m])
                v.push_back({arr[i],arr[i]+m});
        }
        return v;
    }
};
// @lc code=end

