/*
* @lc app=leetcode.cn id=572 lang=cpp
*
* [572] 另一个树的子树
*/

#include"head.h"
using namespace std;
// @lc code=start
class Solution {
public:
	bool same(TreeNode* s, TreeNode* t) {
		int b = (s != nullptr) + (t != nullptr);
		if (!b)
			return true;
		else if (b == 1)
			return false;
		else {
			return (s->val==t->val)&&same(s->left, t->left) && same(s->right, t->right);
		}
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		bool res = false;
		queue<TreeNode*> q;
		q.push(s);
		while (q.size())
		{
			auto qa = q.front();
			q.pop();
			res = res || same(qa, t);
            if(res)
                break;
			if (qa->left)
				q.push(qa->left);
			if (qa->right)
				q.push(qa->right);
		}
		return res;
	}
}; 

// @lc code=end

