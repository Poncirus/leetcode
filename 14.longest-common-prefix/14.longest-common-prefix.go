/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 */
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	res := strs[0]

	for _, s := range strs {
		for i := 0; i < len(res); i++ {
			if i == len(s) || s[i] != res[i] {
				res = s[0:i]
				break
			}
		}
	}

	return res
}
