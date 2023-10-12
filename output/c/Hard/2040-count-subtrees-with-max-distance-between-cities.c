/**https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/ */
//There are n cities numbered from 1 to n. You are given an array edges of size n-1, where edges[i] = [ui, vi] represents a bidirectional edge between cities ui and vi. There exists a unique path between each pair of cities. In other words, the cities form a tree._x000D_
//_x000D_
//A subtree is a subset of cities where every city is reachable from every other city in the subset, where the path between each pair passes through only the cities from the subset. Two subtrees are different if there is a city in one subtree that is not present in the other._x000D_
//_x000D_
//For each d from 1 to n-1, find the number of subtrees in which the maximum distance between any two cities in the subtree is equal to d._x000D_
//_x000D_
//Return an array of size n-1 where the dth element (1-indexed) is the number of subtrees in which the maximum distance between any two cities is equal to d._x000D_
//_x000D_
//Notice that the distance between the two cities is the number of edges in the path between them._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: n = 4, edges = [[1,2],[2,3],[2,4]]_x000D_
//Output: [3,4,0]_x000D_
//Explanation:_x000D_
//The subtrees with subsets {1,2}, {2,3} and {2,4} have a max distance of 1._x000D_
//The subtrees with subsets {1,2,3}, {1,2,4}, {2,3,4} and {1,2,3,4} have a max distance of 2._x000D_
//No subtree has two nodes where the max distance between them is 3._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: n = 2, edges = [[1,2]]_x000D_
//Output: [1]_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: n = 3, edges = [[1,2],[2,3]]_x000D_
//Output: [2,1]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	2 <= n <= 15_x000D_
//	edges.length == n-1_x000D_
//	edges[i].length == 2_x000D_
//	1 <= ui, vi <= n_x000D_
//	All pairs (ui, vi) are distinct._x000D_


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSubgraphsForEachDiameter(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){

}