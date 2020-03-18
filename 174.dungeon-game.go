/*
 * @lc app=leetcode id=174 lang=golang
 *
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (29.01%)
 * Likes:    1046
 * Dislikes: 28
 * Total Accepted:    80K
 * Total Submissions: 275.3K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * table.dungeon, .dungeon th, .dungeon td {
 * ⁠ border:3px solid black;
 * }
 * 
 * ⁠.dungeon th, .dungeon td {
 * ⁠   text-align: center;
 * ⁠   height: 70px;
 * ⁠   width: 70px;
 * }
 * 
 * The demons had captured the princess (P) and imprisoned her in the
 * bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
 * out in a 2D grid. Our valiant knight (K) was initially positioned in the
 * top-left room and must fight his way through the dungeon to rescue the
 * princess.
 * 
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately.
 * 
 * Some of the rooms are guarded by demons, so the knight loses health
 * (negative integers) upon entering these rooms; other rooms are either empty
 * (0's) or contain magic orbs that increase the knight's health (positive
 * integers).
 * 
 * In order to reach the princess as quickly as possible, the knight decides to
 * move only rightward or downward in each step.
 * 
 * 
 * 
 * Write a function to determine the knight's minimum initial health so that he
 * is able to rescue the princess.
 * 
 * For example, given the dungeon below, the initial health of the knight must
 * be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN ->
 * DOWN.
 * 
 * 
 * 
 * 
 * -2 (K)
 * -3
 * 3
 * 
 * 
 * -5
 * -10
 * 1
 * 
 * 
 * 10
 * 30
 * -5 (P)
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight
 * enters and the bottom-right room where the princess is imprisoned.
 * 
 * 
 */

// @lc code=start
func calculateMinimumHP(dungeon [][]int) int {
	r := len(dungeon)
	w := len(dungeon[0])

	if dungeon[r-1][w-1] > 0 {
		dungeon[r-1][w-1] = 0
	}

    for i := w - 2; i >= 0; i-- {
		dungeon[r-1][i] += dungeon[r-1][i+1]
		if dungeon[r-1][i] > 0 {
			dungeon[r-1][i] = 0
		}
	}

	for i:= r - 2; i >= 0; i-- {
		dungeon[i][w-1] += dungeon[i+1][w-1]
		if dungeon[i][w-1] > 0 {
			dungeon[i][w-1] = 0
		}
	}

	for i:= r - 2; i >= 0; i-- {
		for j := w - 2; j >= 0; j-- {
			if dungeon[i+1][j] > dungeon[i][j+1] {
				dungeon[i][j] += dungeon[i+1][j]
			} else {
				dungeon[i][j] += dungeon[i][j+1]
			}

			if dungeon[i][j] > 0 {
				dungeon[i][j] = 0
			}
		}
	}

	return dungeon[0][0] * -1 + 1
}
// @lc code=end

