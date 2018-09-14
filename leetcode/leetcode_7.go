package leetcode

import "math"

func reverse(x int) int {
	var sign bool = false

	if x < 0 {
		sign = true
		x = -x
	}

	var result int64 = 0

	for x > 0 {
		reminder := x % 10
		x /= 10
		result = result*10 + int64(reminder)
		if result > math.MaxInt32 {
			return 0
		}

	}

	if sign {
		result = -result

		if result < math.MinInt32 {
			return 0
		}

	}

	return int(result)

}
