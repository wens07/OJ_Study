func longestCommonPrefix(strs []string) string {

	var str_arr_len int = len(strs)
	if str_arr_len == 0 {
		return ""
	}
	if str_arr_len == 1 {
		return strs[0]
	}

	var min_len int = math.MaxInt32
	for i := 0; i < str_arr_len; i++ {
		if min_len > len(strs[i]) {
			min_len = len(strs[i])
		}
	}

	var res bytes.Buffer
	for i := 0; i < min_len; i++ {
		sign := true
		target := strs[0][i]

		for j := 1; j < str_arr_len; j++ {
			if strs[j][i] != target {
				sign = false
				break
			}
		}

		if sign {
			res.WriteString(string(target))
		} else {
			break
		}
	}

	return res.String()

}
