/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (53.32%)
 * Likes:    1472
 * Dislikes: 71
 * Total Accepted:    96.7K
 * Total Submissions: 178.7K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string of numbers and operators, return all possible results from
 * computing all the different possible ways to group numbers and operators.
 * The valid operators are +, - and *.
 * 
 * Example 1:
 * 
 * 
 * Input: "2-1-1"
 * Output: [0, 2]
 * Explanation: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * Example 2:
 * 
 * 
 * Input: "2*3-4*5"
 * Output: [-34, -14, -10, -10, 10]
 * Explanation: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> res;

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '+' || input[i] == '*' || input[i] == '-')
            {
                vector<int> l = diffWaysToCompute(input.substr(0, i));
                vector<int> r = diffWaysToCompute(input.substr(i + 1));

                for (auto p = l.begin(); p < l.end(); p++)
                {
                    for (auto q = r.begin(); q < r.end(); q++)
                    {
                        res.push_back(comp(input[i], *p, *q));
                    }
                }
            }
        }

        if (res.size() == 0)
        {
            int r = 0;
            for (int i = 0; i < input.size(); i++)
            {
                r *= 10;
                r += input[i] - '0';
            }

            return vector<int>{r};
        }

        return res;
    }

    int comp(char op, int a, int b)
    {
        switch (op)
        {
        case '+':
            return a + b;
            break;
        case '*':
            return a * b;
            break;
        case '-':
            return a - b;
            break;

        default:
            break;
        }

        return 0;
    }
};
// @lc code=end
