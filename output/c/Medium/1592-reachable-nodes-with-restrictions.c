/**https://leetcode.com/problems/reachable-nodes-with-restrictions/ */
//There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
//Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
//Note that node 0 will not be a restricted node.
// 
//Example 1:
//Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
//Output: 4
//Explanation: The diagram above shows the tree.
//We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.
//Example 2:
//Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
//Output: 3
//Explanation: The diagram above shows the tree.
//We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.
// 
//Constraints:
//	2 <= n <= 105
//	edges.length == n - 1
//	edges[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	edges represents a valid tree.
//	1 <= restricted.length < n
//	1 <= restricted[i] < n
//	All the values of restricted are unique.
int reachableNodes(int n, int** edges, int edgesSize, int* edgesColSize, int* restricted, int restrictedSize){
int i, j;
	int *cnt = (int *)malloc(sizeof(int) * n);
	memset(cnt, 0, sizeof(int) * n);
	int **g = (int **)malloc(sizeof(int *) * n);
	for (i = 0; i < n; ++i) {
		g[i] = (int *)malloc(sizeof(int) * n);
		memset(g[i], 0, sizeof(int) * n);
	}
	for (i = 0; i < edgesSize; ++i) {
		g[edges[i][0]][edges[i][1]] = 1;
		g[edges[i][1]][edges[i][0]] = 1;
	}
	for (i = 0; i < restrictedSize; ++i) {
		for (j = 0; j < n; ++j) {
			g[restricted[i]][j] = 0;
			g[j][restricted[i]] = 0;
		}
	}
	for (i = 0; i < n; ++i) {
		if (g[0][i] == 1) {
			cnt[0]++;
		}
	}
	for (i = 1; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (g[i][j] == 1) {
				cnt[i]++;
			}
		}
	}
	int res = 0;
	for (i = 0; i < n; ++i) {
		if (cnt[i] > 0) {
			res++;
		}
	}
	for (i = 0; i < edgesSize; ++i) {
		if (cnt[edges[i][0]] > 0 && cnt[edges[i][1]] > 0) {
			res += cnt[edges[i][0]] > cnt[edges[i][1]] ? cnt[edges[i][1]] : cnt[edges[i][0]];
		}
	}
	return res;
}