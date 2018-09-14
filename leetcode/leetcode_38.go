package leetcode

import (
	"fmt"
)

func Count_unique_letter(src string, index int) int {
	var result int = 1

	for i := index; i < len(src) - 1; i++ {
		if src[i] == src[i + 1]{
			result++
		}
	}

	return result
}



