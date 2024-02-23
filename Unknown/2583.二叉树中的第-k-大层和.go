/*
 * @lc app=leetcode.cn id=2583 lang=golang
 *
 * [2583] 二叉树中的第 K 大层和
 */
package main

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import (
	"github.com/emirpasic/gods/trees/binaryheap"
)

func kthLargestLevelSum(root *TreeNode, k int) int64 {
    heap := binaryheap.NewWithIntComparator()
    var q []*TreeNode
    q = append(q, root)
    for len(q) > 0 {
        sum := 0
        length := len(q)
        for i:= 0; i < length; i++{
            v := q[i]
            sum += v.Val
            if v.Left != nil {
                q = append(q, v.Left)
            }
            if v.Right != nil {
                q = append(q, v.Right)
            }
        }
        if heap.Size() < k {
            heap.Push(sum);
        } else {
            pk, _ := heap.Peek()
            if pk.(int) < sum {
                heap.Pop()
                heap.Push(sum)
            }
        }
        if len(q) > length {
            q = q[length:]
        } else {
            q = []*TreeNode{}
        }
    }
    if heap.Size() < k {
        return -1
    }
    res, _ := heap.Peek()
    return int64(res.(int))
}
// @lc code=end

