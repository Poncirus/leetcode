/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (45.45%)
 * Likes:    340
 * Dislikes: 86
 * Total Accepted:    34.4K
 * Total Submissions: 73.8K
 * Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n' +
  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an, ...,
 * summarize the numbers seen so far as a list of disjoint intervals.
 * 
 * For example, suppose the integers from the data stream are 1, 3, 7, 2, 6,
 * ..., then the summary will be:
 * 
 * 
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * What if there are lots of merges and the number of disjoint intervals are
 * small compared to the data stream's size?
 * 
 */

// @lc code=start
class SummaryRanges
{
protected:
    set<int> order;

public:
    /** Initialize your data structure here. */
    SummaryRanges()
    {
    }
    // O(log(N)) to add
    void addNum(int val)
    {
        order.insert(val);
    }
    // O(N) ot get interval
    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ret;
        if (order.empty())
            return ret;
        auto it = (order.begin());
        int start = *it;
        int expect = start + 1;
        it++;
        while (it != order.end())
        {
            if (*it != expect)
            {
                ret.push_back({start, expect - 1});
                start = *it;
                expect = start + 1;
            }
            else
                expect++;
            it++;
        }
        // dont forget to push the last one
        ret.push_back({start, expect - 1});
        return ret;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end
