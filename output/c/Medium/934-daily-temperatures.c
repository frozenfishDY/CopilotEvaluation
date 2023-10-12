/**https://leetcode.com/problems/daily-temperatures/ */
//Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// 
//Example 1:
//Input: temperatures = [73,74,75,71,69,72,76,73]
//Output: [1,1,4,2,1,1,0,0]
//Example 2:
//Input: temperatures = [30,40,50,60]
//Output: [1,1,1,0]
//Example 3:
//Input: temperatures = [30,60,90]
//Output: [1,1,0]
// 
//Constraints:
//	1 <= temperatures.length <= 105
//	30 <= temperatures[i] <= 100
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
int* res = (int*)malloc(sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    int stack[temperaturesSize][2];
    int top = -1;
    for (int i = 0; i < temperaturesSize; i++) {
        int cur = temperatures[i];
        while (top != -1 && cur > stack[top][1]) {
            int index = stack[top--][0];
            res[index] = i - index;
        }
        stack[++top][0] = i;
        stack[top][1] = cur;
    }
    while (top != -1) {
        res[stack[top--][0]] = 0;
    }
    return res;
}