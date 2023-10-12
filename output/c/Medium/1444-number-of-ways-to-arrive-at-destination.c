/**https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/ */
//You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
//You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
//Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.
// 
//Example 1:
//Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
//Output: 4
//Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
//The four ways to get there in 7 minutes are:
//- 0 ➝ 6
//- 0 ➝ 4 ➝ 6
//- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
//- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
//Example 2:
//Input: n = 2, roads = [[1,0,10]]
//Output: 1
//Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
// 
//Constraints:
//	1 <= n <= 200
//	n - 1 <= roads.length <= n * (n - 1) / 2
//	roads[i].length == 3
//	0 <= ui, vi <= n - 1
//	1 <= timei <= 109
//	ui != vi
//	There is at most one road connecting any two intersections.
//	You can reach any intersection from any other intersection.
int countPaths(int n, int** roads, int roadsSize, int* roadsColSize){
int i,j;
    int **dp=(int**)malloc(sizeof(int*)*n);
    for(i=0;i<n;i++){
        dp[i]=(int*)malloc(sizeof(int)*2);
        dp[i][0]=0;
        dp[i][1]=0;
    }
    dp[0][0]=0;
    dp[0][1]=1;
    int min;
    int min_index;
    int count;
    int tmp;
    int index;
    for(i=0;i<n;i++){
        min=INT_MAX;
        min_index=-1;
        for(j=0;j<roadsSize;j++){
            if(roads[j][0]==i){
                if(dp[roads[j][1]][0]<min){
                    min=dp[roads[j][1]][0];
                    min_index=roads[j][1];
                }
            }
            if(roads[j][1]==i){
                if(dp[roads[j][0]][0]<min){
                    min=dp[roads[j][0]][0];
                    min_index=roads[j][0];
                }
            }
        }
        if(min_index==-1){
            continue;
        }
        dp[i][0]=min+1;
        count=0;
        for(j=0;j<roadsSize;j++){
            if(roads[j][0]==i){
                if(dp[roads[j][1]][0]==min){
                    count+=dp[roads[j][1]][1];
                }
            }
            if(roads[j][1]==i){
                if(dp[roads[j][0]][0]==min){
                    count+=dp[roads[j][0]][1];
                }
            }
        }
        dp[i][1]=count%1000000007;
    }
    return dp[n-1][1];
}