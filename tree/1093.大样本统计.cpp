/*
* @lc app=leetcode.cn id=1093 lang=cpp
*
* [1093] 大样本统计
*/

#include"head.h"
using namespace std;
// @lc code=start
#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		long long int  sum = 0, cou = 0;
		int max_num, min, max_count;
		double avg, mid;
		max_num = max_count = mid = 0;
        min = -1;
		vector<double> res;

		for (int i = 0; i < count.size(); i++) {
			if (count[i] == 0)
				continue;

			cou += count[i];
			if (min == -1 && count[i] != 0)
				min = i;
			if (i > max_num)
				max_num = i;
			if (count[i] > count[max_count])
				max_count = i;
			sum += count[i] * i;
			
		}
		avg = sum / double(cou);
		bool t = cou % 2 == 0;
		cou /= 2;
		for (int i = 0; i < count.size(); i++) {
			if (count[i] == 0)
				continue;

			cou -= count[i];
			if (cou <= 0) {
				mid = i;
				if (!t || cou < 0)
					break;		
				for (i++; ; i++) {
					if (count[i] == 0)
						continue;
					else {
						mid += i;
						mid /= 2;
						break;
					}
				}

			}
		}
		res.push_back(min);
		res.push_back(max_num);
		res.push_back(avg);
		res.push_back(mid);
		res.push_back(max_count);
		return res;
	}
};

// @lc code=end

