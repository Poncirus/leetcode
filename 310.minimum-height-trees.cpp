/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 *
 * https://leetcode.com/problems/minimum-height-trees/description/
 *
 * algorithms
 * Medium (31.48%)
 * Likes:    1728
 * Dislikes: 96
 * Total Accepted:    90.7K
 * Total Submissions: 285.1K
 * Testcase Example:  '4\n[[1,0],[1,2],[1,3]]'
 *
 * For an undirected graph with tree characteristics, we can choose any node as
 * the root. The result graph is then a rooted tree. Among all possible rooted
 * trees, those with minimum height are called minimum height trees (MHTs).
 * Given such a graph, write a function to find all the MHTs and return a list
 * of their root labels.
 * 
 * Format
 * The graph contains n nodes which are labeled from 0 to n - 1. You will be
 * given the number n and a list of undirected edges (each edge is a pair of
 * labels).
 * 
 * You can assume that no duplicate edges will appear in edges. Since all edges
 * are undirected, [0, 1] is the same as [1, 0] and thus will not appear
 * together in edges.
 * 
 * Example 1 :
 * 
 * 
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * 
 * ⁠       0
 * ⁠       |
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3 
 * 
 * Output: [1]
 * 
 * 
 * Example 2 :
 * 
 * 
 * Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
 * 
 * ⁠    0  1  2
 * ⁠     \ | /
 * ⁠       3
 * ⁠       |
 * ⁠       4
 * ⁠       |
 * ⁠       5 
 * 
 * Output: [3, 4]
 * 
 * Note:
 * 
 * 
 * According to the definition of tree on Wikipedia: “a tree is an undirected
 * graph in which any two vertices are connected by exactly one path. In other
 * words, any connected graph without simple cycles is a tree.”
 * The height of a rooted tree is the number of edges on the longest downward
 * path between the root and a leaf.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    struct Node
    {
        unordered_set<int> neighbor;
        bool isLeaf() const { return neighbor.size() == 1; }
    };

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        vector<int> buffer1;
        vector<int> buffer2;
        vector<int> *pB1 = &buffer1;
        vector<int> *pB2 = &buffer2;
        if (n == 1)
        {
            buffer1.push_back(0);
            return buffer1;
        }
        if (n == 2)
        {
            buffer1.push_back(0);
            buffer1.push_back(1);
            return buffer1;
        }

        // build the graph
        vector<Node> nodes(n);
        for (auto p : edges)
        {
            nodes[p[0]].neighbor.insert(p[1]);
            nodes[p[1]].neighbor.insert(p[0]);
        }

        // find all leaves
        for (int i = 0; i < n; ++i)
        {
            if (nodes[i].isLeaf())
                pB1->push_back(i);
        }

        // remove leaves layer-by-layer
        while (1)
        {
            for (int i : *pB1)
            {
                for (auto n : nodes[i].neighbor)
                {
                    nodes[n].neighbor.erase(i);
                    if (nodes[n].isLeaf())
                        pB2->push_back(n);
                }
            }
            if (pB2->empty())
            {
                return *pB1;
            }
            pB1->clear();
            swap(pB1, pB2);
        }
    }
};
// @lc code=end
