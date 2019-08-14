package letterCombinations

func letterCombinations(digits string) []string {
	if l := len(digits); l == 0 {
		return []string{}
	}
	digitMap := map[string][]string{
		"2": []string{"a", "b", "c"},
		"3": []string{"d", "e", "f"},
		"4": []string{"g", "h", "i"},
		"5": []string{"j", "k", "l"},
		"6": []string{"m", "n", "o"},
		"7": []string{"p", "q", "r", "s"},
		"8": []string{"t", "u", "v"},
		"9": []string{"w", "x", "y", "z"},
	}
	return binaryDivide(digits, digitMap)
}

func binaryDivide(digits string, digitMap map[string][]string) []string {
	var r []string
	if l := len(digits); l == 2 {
		r = mergeTwoSlice(digitMap[digits[:1]], digitMap[digits[1:]])
	} else if l == 1 {
		r = digitMap[digits]
	} else {
		m := l / 2
		r = mergeTwoSlice(binaryDivide(digits[:m], digitMap), binaryDivide(digits[m:], digitMap))
	}
	return r
}

func mergeTwoSlice(slice1 []string, slice2 []string) []string {
	var r []string
	for _, v1 := range slice1 {
		for _, v2 := range slice2 {
			r = append(r, v1+v2)
		}
	}
	return r
}
