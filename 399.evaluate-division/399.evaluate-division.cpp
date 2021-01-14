/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 *
 * https://leetcode.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (50.03%)
 * Likes:    2158
 * Dislikes: 162
 * Total Accepted:    125.2K
 * Total Submissions: 245.6K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * Equations are given in the format A / B = k, where A and B are variables
 * represented as strings, and k is a real number (floating point number).
 * Given some queries, return the answers. If the answer does not exist, return
 * -1.0.
 * 
 * Example:
 * Given  a / b = 2.0, b / c = 3.0.
 * queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
 * return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
 * 
 * The input is:  vector<pair<string, string>> equations, vector<double>&
 * values, vector<pair<string, string>> queries , where equations.size() ==
 * values.size(), and the values are positive. This represents the equations.
 * Return  vector<double>.
 * 
 * According to the example above:
 * 
 * 
 * equations = [ ["a", "b"], ["b", "c"] ],
 * values = [2.0, 3.0],
 * queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]
 * ]. 
 * 
 * 
 * 
 * The input is always valid. You may assume that evaluating the queries will
 * result in no division by zero and there is no contradiction.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        vector<double> result(queries.size());
        unordered_map<string, unordered_map<string, double>> adjmat; //Adjacency matrix
        for (int i = 0; i < equations.size(); i++)
        {
            adjmat[equations[i][0]][equations[i][1]] = values[i];
            adjmat[equations[i][1]][equations[i][0]] = 1.0 / values[i];
            adjmat[equations[i][0]][equations[i][0]] = 1.0; //For types a/a=1 and so on..
            adjmat[equations[i][1]][equations[i][1]] = 1.0;
        }
        for (auto k = adjmat.begin(); k != adjmat.end(); k++)
            for (auto i = adjmat.begin(); i != adjmat.end(); i++)
                for (auto j = adjmat.begin(); j != adjmat.end(); j++)
                    i->second[j->first] = max(i->second[j->first], i->second[k->first] * k->second[j->first]);
        //By Floyd Warshall dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]) IF i/j cannot be reached via k then dp[i][k]*dp[k][j] will be 0.

        for (int i = 0; i < queries.size(); i++)
        {
            if (!adjmat[queries[i][0]][queries[i][1]])
                result[i] = -1.0;
            else
                result[i] = adjmat[queries[i][0]][queries[i][1]];
        }
        return result;
    }
};
// @lc code=end
