/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (41.45%)
 * Likes:    2362
 * Dislikes: 44
 * Total Accepted:    190K
 * Total Submissions: 443.2K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * For example,
 * 
 * [2,3,4], the median is 3
 * 
 * [2,3], the median is (2 + 3) / 2 = 2.5
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * If all integer numbers from the stream are between 0 and 100, how would you
 * optimize it?
 * If 99% of all integer numbers from the stream are between 0 and 100, how
 * would you optimize it?
 * 
 * 
 */

// @lc code=start
class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (v.size() == 0)
        {
            v.push_back(num);
            return;
        }

        int lo = 0;
        int hi = v.size();

        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (v[mid] > num)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        vector<int>::iterator it = v.begin() + hi;
        v.insert(it, num);
    }

    double findMedian()
    {
        if (v.size() % 2 == 0)
        {
            return ((v[v.size() / 2] + v[v.size() / 2 - 1])) / 2.0;
        }
        return v[v.size() / 2];
    }

private:
    vector<int> v;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
