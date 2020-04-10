package generateParenthesis

func generateParenthesis(n int) []string {
	if n == 0 {
		return []string{}
	}
	re := make([]string, 0, n*n)
	bytes := make([]byte, n*2)
	dfs(bytes, n, n, 0, &re)
	return re
}

func dfs(b []byte, left int, right int, index int, arr *[]string) {
	if left == 0 && right == 0 {
		*arr = append(*arr, string(b))
	}
	if left > 0 {
		b[index] = '('
		dfs(b, left-1, right, index+1, arr)
	}
	if right > 0 && right > left {
		b[index] = ')'
		dfs(b, left, right-1, index+1, arr)
	}
}
