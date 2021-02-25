/*
* @lc app=leetcode.cn id=703 lang=cpp
*
* [703] 数据流中的第 K 大元素
*/

#include"head.h"
using namespace std;
// @lc code=start
#include<list>
#include<queue>
#include<unordered_map>
#include<string>
#include<unordered_set>
#include<iomanip>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

class KthLargest {
	int k, pre;
	vector<int> num;
public:
	KthLargest(int k, vector<int>& nums) {
		num.insert(num.end(),nums.begin(), nums.end());
		this->k = k;
		pre = -1;
	}

	int add(int val) {
		if (pre == -1) {
			num.push_back(val);
			sort(num.begin(), num.end());
			return num[pre = num.size() - k];
		}
		else if(val <= num[pre])
			return num[pre];
		else {
			auto it = num.begin() + pre;
			while (it!=num.end()&&*it<val)
				it++;
			num.insert(it, val);
			return num[++pre];
		}
	}
};

// @lc code=end

