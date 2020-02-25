/*
 * @lc app=leetcode id=71 lang=golang
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (31.03%)
 * Likes:    624
 * Dislikes: 1554
 * Total Accepted:    186.2K
 * Total Submissions: 599.9K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

// @lc code=start
func simplifyPath(path string) string {
	var res string
	
	for i := 1; i < len(path); i++ {
		if path[i] == '/' {
			continue
		}

		if path[i] == '.' {
			if i + 1 == len(path) || path[i+1] == '/' {
				i += 1
				continue
			}

			if path[i+1] == '.' && (i + 2 == len(path) || path[i+2] == '/') {
				res = r(res)
				i += 2
				continue
			}
		}

		e := i + 1
		for e < len(path) && path[e] != '/' {
			e++
		}

		res += "/" + path[i:e]
		i = e
	}

	if len(res) == 0 {
		res = "/"
	}

	return res
}

func r(s string) string {
	if len(s) == 0 {
		return s
	}

	for i := len(s)-1; i >=0; i-- {
		if s[i] == '/' {
			return s[:i]
		}
	}

	return ""
}
// @lc code=end

