/**https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/ */
//You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
//The score of a path between two cities is defined as the minimum distance of a road in this path.
//Return the minimum possible score of a path between cities 1 and n.
//Note:
//A path is a sequence of roads between two cities.
//It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
//The test cases are generated such that there is at least one path between 1 and n.


int minScore(int n, int** roads, int roadsSize, int* roadsColSize){
    int** dp = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        dp[i] = (int*)malloc(sizeof(int) * n);
        for(int j = 0; j < n; j++){
            dp[i][j] = 1000000;
        }
    }
    for(int i = 0; i < roadsSize; i++){
        dp[roads[i][0] - 1][roads[i][1] - 1] = roads[i][2];
        dp[roads[i][1] - 1][roads[i][0] - 1] = roads[i][2];
    }
    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] > fmin(dp[i][k], dp[k][j])){
                    dp[i][j] = fmin(dp[i][k], dp[k][j]);
                }
            }
        }
    }
    return dp[0][n - 1];

}

    