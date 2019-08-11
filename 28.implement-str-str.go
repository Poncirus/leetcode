/*
 * @lc app=leetcode id=28 lang=golang
 *
 * [28] Implement strStr()
 */
func strStr(haystack string, needle string) int {
	if haystack == needle {
		return 0
	}
	
	for i := 0; i < len(haystack) - len(needle) + 1; i++ {
		j := 0
		for ; j < len(needle); j++ {
			if haystack[i+j] != needle[j] {
				break
			}
		}
		if j == len(needle) {
			return i
		}
	}

	return -1
}

