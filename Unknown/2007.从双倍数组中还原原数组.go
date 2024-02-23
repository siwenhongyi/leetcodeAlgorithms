package main

/*
 * @lc app=leetcode.cn id=2007 lang=golang
 *
 * [2007] 从双倍数组中还原原数组
 */

// @lc code=start
func findOriginalArray(changed []int) []int {
	var res []int
	if len(changed)&1 != 0 {
		return []int{}
	}
	m := make(map[int]int)
	for _, v := range changed {
		m[v]++
	}
	sort.Slice(changed, func(i, j int) bool {
		return changed[i] < changed[j]
	})
	for _, v := range changed {
		if m[v] == 0 {
			continue
		}
		if v == 0 {
			if m[v] < 2 {
				return []int{}
			} else {
				res = append(res, 0)
				m[v] -= 2
			}
		} else {
			if m[v*2] > 0 {
				res = append(res, v)
				m[v]--
				m[v*2]--
			} else {
				return []int{}
			}
		}
	}
	if len(res)*2 == len(changed) {
		return res
	}
	return []int{}
}

// @lc code=end
