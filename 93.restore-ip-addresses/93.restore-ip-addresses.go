/*
 * @lc app=leetcode id=93 lang=golang
 *
 * [93] Restore IP Addresses
 *
 * https://leetcode.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (33.69%)
 * Likes:    970
 * Dislikes: 435
 * Total Accepted:    170.8K
 * Total Submissions: 506.2K
 * Testcase Example:  '"25525511135"'
 *
 * Given a string containing only digits, restore it by returning all possible
 * valid IP address combinations.
 * 
 * Example:
 * 
 * 
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 * 
 * 
 */

// @lc code=start
func restoreIpAddresses(s string) []string {
    return r(s, "", 0)
}

func r(s, tr string, n int) []string {
	if n == 4 {
		if s == "" {
			return []string{tr[:len(tr)-1]}
		}

		return []string{}
	}

	if len(s) == 0 {
		return []string{}
	}

	if s[0] == '0' {
		return r(s[1:], tr+s[:1]+".", n+1)
	}

	var res []string
	if len(s) >= 1 {
		res = append(res, r(s[1:], tr+s[:1]+".", n+1)...)
	}

	if len(s) >= 2 {
		res = append(res, r(s[2:], tr+s[:2]+".", n+1)...)
	}

	if len(s) >= 3 && (s[0] < '2' || (s[0] == '2' && (s[1] < '5' || (s[1] == '5' && s[2] < '6')))) {
		res = append(res, r(s[3:], tr+s[:3]+".", n+1)...)
	}

	return res
}
// @lc code=end

