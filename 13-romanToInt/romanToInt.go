package romanToint

import (
	"strings"
)

func romanToInt(s string) int {
	result := 0
	roman := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	intNum := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	for i, v := range roman {
		for strings.HasPrefix(s, v) {
			result += intNum[i]
			s = s[len(v):]
		}
	}
	return result
}
