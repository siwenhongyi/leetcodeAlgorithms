/*
 * @lc app=leetcode.cn id=179 lang=golang
 *
 * [179] 最大数
 */

// @lc code=start
func largestNumber(nums []int) string {
	var num []string
	var res string
	for _, v := range nums {
		num = append(num, strconv.Itoa(v))
	}
	sort.Slice(num, func(i, j int) bool {
		return num[i]+num[j] > num[j]+num[i]
	})
	for _, v := range num {
		res += v
	}
    res = strings.TrimLeft(res, "0")
	if res == "" {
        res = "0"
    }
    return res
}

// @lc code=end
