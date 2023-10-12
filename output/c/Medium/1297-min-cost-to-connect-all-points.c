/**https://leetcode.com/problems/min-cost-to-connect-all-points/ */
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
// 
//Example 1:
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation: 
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//Example 2:
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
// 
//Constraints:
//	1 <= points.length <= 1000
//	-106 <= xi, yi <= 106
//	All pairs (xi, yi) are distinct.
int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
int i, j, k;
    int min = 0;
    int count = 0;
    int* distance = (int*)malloc(sizeof(int) * pointsSize);
    int* visited = (int*)malloc(sizeof(int) * pointsSize);
    memset(visited, 0, sizeof(int) * pointsSize);
    memset(distance, 0, sizeof(int) * pointsSize);
    for (i = 0; i < pointsSize; i++)
    {
        distance[i] = abs(points[0][0] - points[i][0]) + abs(points[0][1] - points[i][1]);
    }
    visited[0] = 1;
    count++;
    while (count < pointsSize)
    {
        min = INT_MAX;
        for (i = 0; i < pointsSize; i++)
        {
            if (!visited[i] && distance[i] < min)
            {
                min = distance[i];
                k = i;
            }
        }
        visited[k] = 1;
        count++;
        for (j = 0; j < pointsSize; j++)
        {
            if (!visited[j] && (abs(points[k][0] - points[j][0]) + abs(points[k][1] - points[j][1])) < distance[j])
            {
                distance[j] = abs(points[k][0] - points[j][0]) + abs(points[k][1] - points[j][1]);
            }
        }
    }
    count = 0;
    for (i = 0; i < pointsSize; i++)
    {
        count += distance[i];
    }
    free(distance);
    free(visited);
    return count;
}