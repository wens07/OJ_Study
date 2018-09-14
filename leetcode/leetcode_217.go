package leetcode


func containsDuplicate(nums []int) bool {
	valueMap := make(map[int]int)

	for _, v := range nums {
		if valueMap[v] > 1 {
			return true
		}

		valueMap[v]++
	}

	return false

}
