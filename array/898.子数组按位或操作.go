package main

/*
 * @lc app=leetcode.cn id=898 lang=golang
 *
 * [898] 子数组按位或操作
 */

// @lc code=start
func subarrayBitwiseORs(arr []int) int {
    set := make(map[int]bool)
    // set[arr[0]] = true
    for i:=0;i<len(arr);i++ {
        temp := map[int]bool{arr[i]:true}
        x := arr[i]
        for j :=i-1;j>=0;j-- {
            if  x | arr[j] == arr[j] {
                break
            }
            arr[j] = x | arr[j]
            temp[arr[j]] = true;
        }
        for k,_ := range temp {
            set[k] = true
        }
    }
    return len(set)
    
}
// @lc code=end

