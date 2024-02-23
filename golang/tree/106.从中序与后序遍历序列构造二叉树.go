package main

/*
 * @lc app=leetcode.cn id=106 lang=golang
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
func build(preorder []int, pl, pr int, inorder []int, inl, inr int, index map[int]int) *TreeNode {
	if inl >= inr {
		return nil
	}
	rootVal := preorder[pr-1]
	rootIndex := index[rootVal]
	rightSize := inr - rootIndex - 1
	root := &TreeNode{
		Val:   rootVal,
		Left:  build(preorder, pl, pr-rightSize-1, inorder, inl, rootIndex, index),
		Right: build(preorder, pr-rightSize-1, pr-1, inorder, rootIndex+1, inr, index),
	}
	return root
}

func buildTree(inorder []int, postorder []int) *TreeNode {
	n := len(inorder)
	if n == 1 {
		return &TreeNode{
			Val: inorder[0],
		}
	}
	index := make(map[int]int)
	for idx, v := range inorder {
		index[v] = idx
	}
	return build(postorder, 0, n, inorder, 0, n, index)
}

// @lc code=end
