func maxArea(height []int) int {
	var line_len int = len(height)

	var low int = 0
	var high int = line_len - 1
	var res int = 0

	for low < high {

		if height[low] < height[high] {

			if res < (height[high]-height[low])*(high-low) {
				res = (height[high] - height[low]) * (high - low)
			}

			low++
		} else {

			if res < (height[low]-height[high])*(high-low) {
				res = (height[low] - height[high]) * (high - low)
			}

			high++
		}

	}

	return res

}
