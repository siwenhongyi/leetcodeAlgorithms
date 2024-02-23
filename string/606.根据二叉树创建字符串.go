/*
 * @lc app=leetcode.cn id=606 lang=golang
 *
 * [606] 根据二叉树创建字符串
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 var res string

func treeToStr(root *TreeNode) {
	if root == nil {
		res += "()"
		return
	}
	res += "(" + strconv.Itoa(root.Val)
	if root.Left == nil && root.Right == nil {
	} else if root.Left != nil && root.Right != nil {
		treeToStr(root.Left)
		treeToStr(root.Right)
	} else if root.Right == nil {
		treeToStr(root.Left)
	} else {
		res += "()"
		treeToStr(root.Right)
	}
	res += ")"
}

func tree2str(root *TreeNode) string {
	if root == nil {
		return "()"
	}
	res = ""
	treeToStr(root)
	return res[1 : len(res)-1]
}


// @lc code=end

