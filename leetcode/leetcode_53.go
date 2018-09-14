package leetcode

func maxSubArray(nums []int) int {

	dp := [len(nums)][len(nums)]int{}

	//init
	dp[0][0] = nums[0]

	for i := 1; i < len(nums); i++ {
		dp[i][0] = 0
	}

	max := dp[0][0]
	//indexi := 0
	//indexj := 0
	for i := 0; i < len(nums); i++ {
		for j := 1; j < len(nums); j++ {
			dp[i][j] = dp[i][j - 1] + nums[j]
			if dp[i][j] > max {
				max = dp[i][j]
			}

		}
	}

	return max


}