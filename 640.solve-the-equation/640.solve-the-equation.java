import java.util.ArrayList;

/*
 * @lc app=leetcode id=640 lang=java
 *
 * [640] Solve the Equation
 *
 * https://leetcode.com/problems/solve-the-equation/description/
 *
 * algorithms
 * Medium (43.14%)
 * Likes:    322
 * Dislikes: 645
 * Total Accepted:    30.1K
 * Total Submissions: 69.6K
 * Testcase Example:  '"x+5-3+x=6+x-2"'
 *
 * Solve a given equation and return the value of 'x' in the form of a string
 * "x=#value". The equation contains only '+', '-' operation, the variable 'x'
 * and its coefficient. You should return "No solution" if there is no solution
 * for the equation, or "Infinite solutions" if there are infinite solutions
 * for the equation.
 * 
 * If there is exactly one solution for the equation, we ensure that the value
 * of 'x' is an integer.
 * 
 * 
 * Example 1:
 * Input: equation = "x+5-3+x=6+x-2"
 * Output: "x=2"
 * Example 2:
 * Input: equation = "x=x"
 * Output: "Infinite solutions"
 * Example 3:
 * Input: equation = "2x=x"
 * Output: "x=0"
 * Example 4:
 * Input: equation = "2x+3x-6x=x+2"
 * Output: "x=-1"
 * Example 5:
 * Input: equation = "x=x+2"
 * Output: "No solution"
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= equation.length <= 1000
 * equation has exactly one '='.
 * equation consists of integers with an absolute value in the range [0, 100]
 * without any leading zeros, and the variable 'x'.
 * 
 * 
 */

// @lc code=start
class Solution {
    public String solveEquation(String equation) {
        int[] res = evaluateExpression(equation.split("=")[0]), res2 = evaluateExpression(equation.split("=")[1]);
        res[0] -= res2[0];
        res[1] = res2[1] - res[1];
        if (res[0] == 0 && res[1] == 0)
            return "Infinite solutions";
        if (res[0] == 0)
            return "No solution";
        return "x=" + res[1] / res[0];
    }

    public int[] evaluateExpression(String exp) {
        String[] tokens = exp.split("(?=[-+])");
        int[] res = new int[2];
        for (String token : tokens) {
            if (token.equals("+x") || token.equals("x"))
                res[0] += 1;
            else if (token.equals("-x"))
                res[0] -= 1;
            else if (token.contains("x"))
                res[0] += Integer.parseInt(token.substring(0, token.indexOf("x")));
            else
                res[1] += Integer.parseInt(token);
        }
        return res;
    }
}
// @lc code=end
