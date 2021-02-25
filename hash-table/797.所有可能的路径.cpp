/*
* @lc app=leetcode.cn id=797 lang=cpp
*
* [797] 所有可能的路径
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int n;
    vector<vector<int> >  res,edge;
    vector<int> path;
    vector<bool> visi;
    void dfs(int index){
        path.push_back(index);
        if(index==n-1){
            res.push_back(path);   
        }
        else{
        visi[index] = false;
        for(auto &i:edge[index])
            if(visi[i])
                dfs(i);
        visi[index] = true;
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        visi.resize(n,true);
        edge.swap(graph);
        dfs(0);
        return res;
    }
};
// @lc code=end

