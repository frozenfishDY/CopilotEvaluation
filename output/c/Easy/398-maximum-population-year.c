/**https://leetcode.com/problems/maximum-population-year/ */
//You are given a 2D integer array logs where each logs[i] = [birthi, deathi] indicates the birth and death years of the ith person.
//The population of some year x is the number of people alive during that year. The ith person is counted in year x's population if x is in the inclusive range [birthi, deathi - 1]. Note that the person is not counted in the year that they die.
//Return the earliest year with the maximum population.
// 
//Example 1:
//Input: logs = [[1993,1999],[2000,2010]]
//Output: 1993
//Explanation: The maximum population is 1, and 1993 is the earliest year with this population.
//Example 2:
//Input: logs = [[1950,1961],[1960,1971],[1970,1981]]
//Output: 1960
//Explanation: 
//The maximum population is 2, and it had happened in years 1960 and 1970.
//The earlier year between them is 1960.
// 
//Constraints:
//	1 <= logs.length <= 100
//	1950 <= birthi < deathi <= 2050
int maximumPopulation(int** logs, int logsSize, int* logsColSize){
int i = 0, j = 0, k = 0, l = 0, max = 0, cnt = 0;
    int *p = (int *)calloc(101, sizeof(int));
    for(i = 0; i < logsSize; i++){
        for(j = logs[i][0]; j < logs[i][1]; j++){
            p[j - 1950]++;
        }
    }
    for(i = 0; i < 101; i++){
        if(p[i] > max){
            max = p[i];
            cnt = i;
        }
    }
    return cnt + 1950;
}