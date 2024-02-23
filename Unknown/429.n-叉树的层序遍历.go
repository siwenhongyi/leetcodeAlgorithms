package main

/*
 * @lc app=leetcode.cn id=429 lang=golang
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

 func levelOrder(root *Node) [][]int {
	var res [][]int
	if root == nil {
		return res
	}
	f := []*Node{root}
	for len(f) > 0 {
		var s []*Node
		var v []int
		for _, r := range f {
			v = append(v, r.Val)
			for _, rs := range r.Children {
				s = append(s, rs)
			}
		}
		if len(v) > 0 {
			res = append(res, v)
		}
		f = s
	}
	return res
}
// @lc code=end

