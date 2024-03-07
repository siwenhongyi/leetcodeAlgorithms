package main

/*
 * @lc app=leetcode.cn id=2598 lang=golang
 *
 * [2598] 执行操作后的最大 MEX
 * https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/description/
 *
 * algorithms
 * Medium (39.55%)
 * Likes:    20
 * Dislikes: 0
 * Total Accepted:    5.8K
 * Total Submissions: 14.7K
 * Testcase Example:  '[1,-10,7,13,6,8]\n5'
 */

// @lc code=start
func findSmallestInteger(nums []int, value int) int {
    if len(nums) == 0 {
        return 0
    }
    offsetTimes,rFirstIndex := make(map[int]int),make(map[int]int)
    var r int
    for idx,v := range nums {
        if v >= 0 {
            r = v%value
        } else {
            r = ((v%value) + value)%value
        }
        offsetTimes[r] += 1
        if _,ok:= rFirstIndex[r];!ok {
            rFirstIndex[r] = idx
        }
    }
    minTimes := 1 << 61
    var minTimesNum int
    for num:=0;num<value;num++ {
        times, ok := offsetTimes[num]
        if !ok {
            minTimes, minTimesNum =0, num
            break
        } else if times < minTimes {
            minTimes,minTimesNum = times,num
        }
    }
    return minTimes * value + minTimesNum
}
// @lc code=end


