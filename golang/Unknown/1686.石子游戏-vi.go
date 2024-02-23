package main

import (
	"github.com/emirpasic/gods/trees/binaryheap"
	"github.com/emirpasic/gods/utils"
)

/*
 * @lc app=leetcode.cn id=1686 lang=golang
 *
 * [1686] 石子游戏 VI
 * https://leetcode.cn/problems/stone-game-vi/description/
 *
 * algorithms
 * Medium (65.58%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    18.7K
 * Total Submissions: 28.5K
 * Testcase Example:  '[1,3]\n[2,1]'
 */

// @lc code=start

type node struct {
	a int
	b int
	p int
}

func cmp(a, b interface{}) int {
	pa := a.(*node).p
	pb := b.(*node).p
	return -utils.IntComparator(pa, pb)
}

func stoneGameVI(aliceValues []int, bobValues []int) int {
	n := len(aliceValues)
	if n == 1 {
		return 1
	}
	a := binaryheap.NewWith(cmp)
	for i := 0; i < n; i++ {
		ap := &node{a: aliceValues[i], b: bobValues[i]}
		ap.p = ap.a + ap.b
		a.Push(ap)
	}
	as, bs := 0, 0
	for a.Size() > 1 {
		c, _ := a.Pop()
		as += c.(*node).a
		c, _ = a.Pop()
		bs += c.(*node).b
	}
	if a.Size() > 0 {
		c, _ := a.Pop()
		as += c.(*node).a
	}
	if as > bs {
		return 1
	}
	if as == bs {
		return 0
	}
	return -1
}


// @lc code=end


