/**https://leetcode.com/problems/number-of-operations-to-make-network-connected/ */
//There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
//You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
//Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.
// 
//Example 1:
//Input: n = 4, connections = [[0,1],[0,2],[1,2]]
//Output: 1
//Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
//Example 2:
//Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
//Output: 2
//Example 3:
//Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
//Output: -1
//Explanation: There are not enough cables.
// 
//Constraints:
//	1 <= n <= 105
//	1 <= connections.length <= min(n * (n - 1) / 2, 105)
//	connections[i].length == 2
//	0 <= ai, bi < n
//	ai != bi
//	There are no repeated connections.
//	No two computers are connected by more than one cable.
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
int *parent = (int *)malloc(sizeof(int) * (n));
    memset(parent, 0, sizeof(int) * (n));
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int res = 0;
    for (int i = 0; i < connectionsSize; ++i) {
        int px = find(parent, connections[i][0]);
        int py = find(parent, connections[i][1]);
        if (px != py) {
            parent[px] = py;
        } else {
            ++res;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (parent[i] == i) {
            ++count;
        }
    }
    return res >= count - 1 ? count - 1 : -1;
}
int find(int *parent, int index) {
    if (parent[index] != index) {
        parent[index] = find(parent, parent[index]);
    }
    return parent[index];
}