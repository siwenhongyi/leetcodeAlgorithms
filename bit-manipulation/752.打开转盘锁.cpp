/*
* @lc app=leetcode.cn id=752 lang=cpp
*
* [752] 打开转盘锁
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		string a = "0000";
		string qa, t1, t2;
		queue<string> q;
		q.push(a);
		map<int, int> book;
		for (auto i : deadends) {
			if (i == "0000")
				return -1;
			book[atoi(i.c_str())] = -1;
		}
		book[0] = 1;
		while (q.size())
		{
			qa = q.front();
			q.pop();
			int len = book[atoi(qa.c_str())];
			for (int i = 0; i <4; i++) {
				t1 = t2 = qa;
				if (t1[i] != '9')
					t1[i]++;
				else
					t1[i] = '0';
				int x = atoi(t1.c_str());
				if (book[x]==0) {
					q.push(t1);
					book[x] = len + 1;
				}
				if (t2[i] != '0')
					t2[i]--;
				else
					t2[i] = '9';
				x = atoi(t2.c_str());
				if (book[x]==0) {
					q.push(t2);
					book[x] = len + 1;
				}
				if (t1 == target || t2 == target)
					break;
			}
		}
		return book[atoi(target.c_str())] - 1;
	}
}; 

// @lc code=end

