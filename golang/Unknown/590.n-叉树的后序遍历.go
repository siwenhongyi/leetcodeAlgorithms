package main

/*
 * @lc app=leetcode.cn id=590 lang=golang
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Children []*Node
 * }
 */

 var res590 []int

 func postorderdfs(root *Node) {
     if root == nil {
         return
     }
     for _,s := range root.Children {
         dfs(s)
     }
     res = append(res,root.Val)
 }

func postorder(root *Node) []int {
    res = make([]int, 0)
    postorderdfs(root)
    return res
}
// @lc code=end

