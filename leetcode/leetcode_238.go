package leetcode

func productExceptSelf(nums []int) []int {

	var result []int = make([]int, len(nums))
	sum := 1
	result[0] = 1

	// get the sum from begin to i - 1
	for i := 1; i < len(nums); i++ {
		sum *= nums[i-1]
		result[i] = sum
	}

	// get the sum from i + 1 to end
	sum = 1

	for i := len(nums) - 2; i >= 0; i-- {
		sum *= nums[i+1]
		result[i] *= sum
	}

	return result

}
