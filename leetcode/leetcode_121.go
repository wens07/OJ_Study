package leetcode

import (
	"math"
)

/**
 * brute force method
 */
//func maxProfit(prices []int) int {
//
//	var maxprofit = math.MinInt32
//
//	for i := 0; i < len(prices); i++ {
//		for j := i + 1; j < len(prices); j++ {
//			tmp := prices[j] - prices[i]
//
//			if tmp > maxprofit {
//				maxprofit = tmp
//			}
//		}
//
//	}
//
//	if maxprofit < 0 {
//		maxprofit = 0
//	}
//
//	return  maxprofit
//}

/**
 * dp
 */
func maxProfit(prices []int) int {

	var minprice = math.MinInt32
	var maxprofit = 0

	for i := 0; i < len(prices); i++ {
		if prices[i] < minprice {
			minprice = prices[i]
		}

		if maxprofit < prices[i]-minprice {
			maxprofit = prices[i] - minprice
		}
	}

	return maxprofit

}
