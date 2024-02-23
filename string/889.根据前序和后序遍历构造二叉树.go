package main

/*
 * @lc app=leetcode.cn id=889 lang=golang
 *
 * [889] 根据前序和后序遍历构造二叉树
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
func build(preorder []int, pl, pr int, postorder []int, sl, sr int, index map[int]int) *TreeNode {
	if pl >= pr {
		return nil
	}
	root := &TreeNode{
		Val: preorder[pl],
	}
	if pl+1 == pr {
		return root
	}
	nextRootVal := preorder[pl+1]
	nextRootIndex := index[nextRootVal]
	leftSize := nextRootIndex - sl + 1

	root.Left = build(preorder, pl+1, pl+leftSize+1, postorder, sl, nextRootIndex+1, index)
	root.Right = build(preorder, pl+leftSize+1, pr, postorder, nextRootIndex+1, pr-1, index)
	return root
}

// preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	index := make(map[int]int)
	for idx, v := range postorder {
		index[v] = idx
	}
	return build(preorder, 0, len(preorder), postorder, 0, len(postorder), index)
}

// @lc code=end
