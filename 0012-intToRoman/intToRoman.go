package intToRoman

import (
	"strings"
)

func intToRoman(num int) string {
	result := ""
	roman := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
	intNum := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
	for i, v := range roman {
		if num >= intNum[i] {
			result += strings.Repeat(v, num/intNum[i])
			num = num % intNum[i]
		}
	}
	return result
}

// func intToRoman(num int) string {
// 	var buf bytes.Buffer
// 	roman := []string{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}
// 	intNum := []int{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}
// 	for i, v := range roman {
// 		if num >= intNum[i] {
// 			buf.WriteString(strings.Repeat(v, num/intNum[i]))
// 		}
// 		num = num % intNum[i]
// 	}
// 	return buf.String()
// }
