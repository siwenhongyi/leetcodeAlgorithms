/*
* @lc app=leetcode.cn id=1166 lang=cpp
*
* [1166] 设计文件系统
*/

#include"head.h"
using namespace std;
// @lc code=start
class FileSystem {
public:
	unordered_map<string, int> pos;
	FileSystem() {
		pos[""] = 0;
	}

	bool create(string path, int value) {
		int j = path.find_last_of('/');
		if (pos.find(path.substr(0, j)) == pos.end())
			return false;
		else
			pos[path] = value;
		return true;
	}

	int get(string path) {
		if (pos.find(path) == pos.end())
			return -1;
		return pos[path];
	}
};

// @lc code=end

