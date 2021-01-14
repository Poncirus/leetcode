/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (25.99%)
 * Likes:    945
 * Dislikes: 2585
 * Total Accepted:    162.7K
 * Total Submissions: 614.4K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer to its english words representation. Given
 * input is guaranteed to be less than 2^31 - 1.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * 
 * Example 3:
 * 
 * 
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        vector<string> places = {"", "Thousand", "Million", "Billion"};
        vector<vector<string>> toword = {
            {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"},
            {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}};
        string snum = to_string(num);
        int k = 3;
        vector<string> token;
        string curr;
        for (int i = snum.size() - 1; i >= 0; i--)
        {
            curr = snum[i] + curr;
            k--;
            if (k == 0)
            {
                k = 3;
                token.push_back(curr);
                curr = "";
            }
        }

        if (!curr.empty())
            token.push_back(curr);

        for (int i = 0; i < token.size(); i++)
        {
            cout << token[i] << endl;
        }
        string ans = "";

        for (int i = 0; i < token.size(); i++)
        {
            int N = stoi(token[i]);
            if (N > 0 && N < 20)
            {
                ans = toword[0][N] + " " + places[i] + " " + ans;
            }
            else if (N >= 20 && N < 100)
            {

                string t = toword[1][N / 10];

                if (N % 10)
                {
                    t += " " + toword[0][N % 10];
                }

                ans = t + " " + places[i] + " " + ans;
            }
            else if (N >= 100)
            {
                string t = toword[0][N / 100] + " " + "Hundred";
                N %= 100;
                if (N >= 20)
                {
                    t += " " + toword[1][(N % 100) / 10];
                }
                else if (N > 0 && N < 20)
                {
                    t += " " + toword[0][N];
                    ans = t + " " + places[i] + " " + ans;
                    continue;
                }

                if (N % 10)
                {
                    t += " " + toword[0][N % 10];
                }

                ans = t + " " + places[i] + " " + ans;
            }
        }

        while (ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};
// @lc code=end
