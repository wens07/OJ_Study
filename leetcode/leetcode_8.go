func myAtoi(str string) int {

	if len(str) == 0 {
		return 0
	}

	//skip start whitespace
	var i int = 0
	for i < len(str) && str[i] == ' ' {
		i++
	}

	// set the sign
	var sign bool = false
	if str[i] == '-' {
		sign = true
		i++
	} else if str[i] == '+' {
		i++
	}

	var res int64 = 0
	for ; i < len(str); i++ {
		if str[i] >= '0' && str[i] <= '9' {
			res = res*10 + (int64(str[i]) - int64('0'))

			if res > math.MaxInt32+1 {
				break
			}

		} else {
			break
		}
	}

	if sign {
		res = -res
	}

	if res < math.MinInt32 {
		res = math.MinInt32
	}
	if res > math.MaxInt32 {
		res = math.MaxInt32
	}

	return int(res)

}
