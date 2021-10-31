/*
 * @lc app=leetcode id=685 lang=java
 *
 * [685] Redundant Connection II
 *
 * https://leetcode.com/problems/redundant-connection-ii/description/
 *
 * algorithms
 * Hard (33.36%)
 * Likes:    1368
 * Dislikes: 259
 * Total Accepted:    47.6K
 * Total Submissions: 142.6K
 * Testcase Example:  '[[1,2],[1,3],[2,3]]'
 *
 * In this problem, a rooted tree is a directed graph such that, there is
 * exactly one node (the root) for which all other nodes are descendants of
 * this node, plus every node has exactly one parent, except for the root node
 * which has no parents.
 * 
 * The given input is a directed graph that started as a rooted tree with n
 * nodes (with distinct values from 1 to n), with one additional directed edge
 * added. The added edge has two different vertices chosen from 1 to n, and was
 * not an edge that already existed.
 * 
 * The resulting graph is given as a 2D-array of edges. Each element of edges
 * is a pair [ui, vi] that represents a directed edge connecting nodes ui and
 * vi, where ui is a parent of child vi.
 * 
 * Return an edge that can be removed so that the resulting graph is a rooted
 * tree of n nodes. If there are multiple answers, return the answer that
 * occurs last in the given 2D-array.
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
 * Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
 * Output: [4,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= ui, vi <= n
 * ui != vi
 * 
 * 
 */

// @lc code=start
class Solution {
    int[] anc;// 并查集
    int[] parent;// record the father of every node to find the one with 2
                 // fathers,记录每个点的父亲，为了找到双入度点

    public int[] findRedundantDirectedConnection(int[][] edges) {
        anc = new int[edges.length + 1];
        parent = new int[edges.length + 1];
        int[] edge1 = null;
        int[] edge2 = null;
        int[] lastEdgeCauseCircle = null;
        for (int[] pair : edges) {
            int u = pair[0];
            int v = pair[1];

            if (anc[u] == 0)
                anc[u] = u;
            if (anc[v] == 0)
                anc[v] = v;// init the union-find set 初始化并查集

            if (parent[v] != 0) {// node v already has a father, so we just skip the union of this edge and check
                                 // if there will be a circle ，跳过 edge2,并记下 edge1,edge2
                edge1 = new int[] { parent[v], v };
                edge2 = pair;
            } else {
                parent[v] = u;
                int ancU = find(u);
                int ancV = find(v);
                if (ancU != ancV) {
                    anc[ancV] = ancU;
                } else { // meet a circle , 碰到了环
                    lastEdgeCauseCircle = pair;
                }
            }
        }
        if (edge1 != null && edge2 != null)
            return lastEdgeCauseCircle == null ? edge2 : edge1; // 如果是情况2、3，则根据有没有碰到环返回 edge1 或 edge2
        else
            return lastEdgeCauseCircle; // 否则就是情况1，返回那个导致环的最后出现的边。
    }

    private int find(int node) {
        if (anc[node] == node)
            return node;
        anc[node] = find(anc[node]);
        return anc[node];
    }
}
// @lc code=end
