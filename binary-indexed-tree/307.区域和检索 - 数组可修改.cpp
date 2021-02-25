/*
* @lc app=leetcode.cn id=307 lang=cpp
*
* [307] 区域和检索 - 数组可修改
*/

#include"head.h"
using namespace std;
// @lc code=start
class NumArray {
private:
    vector<int> f;
    int n;
    int lowbit(int index){return index&(-index);}
public:
    NumArray(vector<int>& nums) {
        n = nums.size()+1;
        f.resize(n,0);
        for(int i = 0;i<n-1;i++)
            update(i,nums[i]);
    }
    
    void update(int i, int val) {
        i+=1;
        int x = val - (query(i) - query(i-1));
        while(i<n){
            f[i]+=x;
            i += lowbit(i);
        }
    }
    int query(int i){
        int res = 0;
        while(i>0){
            res += f[i];
            i -= lowbit(i);
        }
        return res;
    }
    int sumRange(int i, int j) {
        return query(j+1) - query(i);
    }
};
// @lc code=end

