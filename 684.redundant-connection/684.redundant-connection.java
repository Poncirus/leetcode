import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=684 lang=java
 *
 * [684] Redundant Connection
 *
 * https://leetcode.com/problems/redundant-connection/description/
 *
 * algorithms
 * Medium (60.33%)
 * Likes:    2993
 * Dislikes: 274
 * Total Accepted:    171.6K
 * Total Submissions: 283.8K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a tree is an undirected graph that is connected and has no
 * cycles.
 * 
 * You are given a graph that started as a tree with n nodes labeled from 1 to
 * n, with one additional edge added. The added edge has two different vertices
 * chosen from 1 to n, and was not an edge that already existed. The graph is
 * represented as an array edges of length n where edges[i] = [ai, bi]
 * indicates that there is an edge between nodes ai and bi in the graph.
 * 
 * Return an edge that can be removed so that the resulting graph is a tree of
 * n nodes. If there are multiple answers, return the answer that occurs last
 * in the input.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: edges = [[1,2],[1,3],[2,3]]
 * Output: [2,3]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
 * Output: [1,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ai < bi <= edges.length
 * ai != bi
 * There are no repeated edges.
 * The given graph is connected.
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        List<Integer> set = new ArrayList<>();
        for (int[] edge : edges) {
            for (int i = 0; i < 2; i++) {
                for (int size = set.size(); size <= edge[i]; size++) {
                    set.add(size);
                }
            }

            if (set.get(edge[0]) == set.get(edge[1])) {
                return edge;
            }

            int rep = set.get(edge[1]);
            for (int i = 0; i < set.size(); i++) {
                if (set.get(i) == rep) {
                    set.set(i, set.get(edge[0]));
                }
            }
        }

        return new int[2];
    }
}
// @lc code=end

