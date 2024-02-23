package main

/*
 * @lc app=leetcode.cn id=589 lang=golang
 *
 * [589] N 叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */
var res []int

func dfs(root *Node) {
    if root == nil {
        return
    }
    res = append(res,root.Val)
    for _,s := range root.Children {
        dfs(s)
    }
}

func preorder(root *Node) []int {
    res = []int{}
    dfs(root)
    return res
}
// @lc code=end

