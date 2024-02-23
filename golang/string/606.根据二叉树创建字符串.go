package main

import "strconv"

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

var res606 string

func treeToStr(root *TreeNode) {
	if root == nil {
		res606 += "()"
		return
	}
	res606 += "(" + strconv.Itoa(root.Val)
	if root.Left == nil && root.Right == nil {
	} else if root.Left != nil && root.Right != nil {
		treeToStr(root.Left)
		treeToStr(root.Right)
	} else if root.Right == nil {
		treeToStr(root.Left)
	} else {
		res606 += "()"
		treeToStr(root.Right)
	}
	res606 += ")"
}

func tree2str(root *TreeNode) string {
	if root == nil {
		return "()"
	}
	res606 = ""
	treeToStr(root)
	return res606[1 : len(res606)-1]
}
// @lc code=end
