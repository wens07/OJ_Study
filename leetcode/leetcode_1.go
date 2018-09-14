package leetcode

import (
	"fmt"
)

func twoSum(nums []int, target int) []int {
	var result [2]int
	memo := make(map[int]int)

	for key, value := range nums {

		memo[value] = key
	}

	for key, value := range nums {

		anotherval := target - value

		index, ok := memo[anotherval]

		if ok && key != index {
			result[0] = key
			result[1] = index
		}

	}

	return result[0:2]

}

func main() {

	test := []int{1, 3, 2, 7}

	result := twoSum(test, 6)

	fmt.Println(result[0], result[1])
}
