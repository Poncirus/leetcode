import "strings"

/*
 * @lc app=leetcode id=13 lang=golang
 *
 * [13] Roman to Integer
 */
func romanToInt(s string) int {
	a := 0
	a += strings.Count(s, "I")
	a += strings.Count(s, "V") * 5
	a += strings.Count(s, "X") * 10
	a += strings.Count(s, "L") * 50
	a += strings.Count(s, "C") * 100
	a += strings.Count(s, "D") * 500
	a += strings.Count(s, "M") * 1000
	a += strings.Count(s, "IV") * -2
	a += strings.Count(s, "IX") * -2
	a += strings.Count(s, "XL") * -20
	a += strings.Count(s, "XC") * -20
	a += strings.Count(s, "CD") * -200
	a += strings.Count(s, "CM") * -200

	return a
}
