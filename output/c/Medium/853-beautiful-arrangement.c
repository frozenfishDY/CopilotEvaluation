/**https://leetcode.com/problems/beautiful-arrangement/ */
//Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
//	perm[i] is divisible by i.
//	i is divisible by perm[i].
//Given an integer n, return the number of the beautiful arrangements that you can construct.
// 
//Example 1:
//Input: n = 2
//Output: 2
//Explanation: 
//The first beautiful arrangement is [1,2]:
//    - perm[1] = 1 is divisible by i = 1
//    - perm[2] = 2 is divisible by i = 2
//The second beautiful arrangement is [2,1]:
//    - perm[1] = 2 is divisible by i = 1
//    - i = 2 is divisible by perm[2] = 1
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//	1 <= n <= 15
int countArrangement(int n){ 
int res = 0;
	int* visited = (int*)malloc(sizeof(int) * (n + 1));
	memset(visited, 0, sizeof(int) * (n + 1));
	dfs(n, 1, visited, &res);
	free(visited);
	return res;
}
void dfs(int n, int index, int* visited, int* res) {
	if (index > n) {
		(*res)++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i] && (i % index == 0 || index % i == 0)) {
			visited[i] = 1;
			dfs(n, index + 1, visited, res);
			visited[i] = 0;
		}
	}
}