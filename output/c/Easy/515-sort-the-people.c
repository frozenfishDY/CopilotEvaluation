/**https://leetcode.com/problems/sort-the-people/ */
//You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
//For each index i, names[i] and heights[i] denote the name and height of the ith person.
//Return names sorted in descending order by the people's heights.
// 
//Example 1:
//Input: names = ["Mary","John","Emma"], heights = [180,165,170]
//Output: ["Mary","Emma","John"]
//Explanation: Mary is the tallest, followed by Emma and John.
//Example 2:
//Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
//Output: ["Bob","Alice","Bob"]
//Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
// 
//Constraints:
//	n == names.length == heights.length
//	1 <= n <= 103
//	1 <= names[i].length <= 20
//	1 <= heights[i] <= 105
//	names[i] consists of lower and upper case English letters.
//	All the values of heights are distinct.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    char *t = NULL;
    char **a = (char**)malloc(sizeof(char*) * namesSize);
    for (i = 0; i < namesSize; i++) {
        a[i] = (char*)malloc(sizeof(char) * 21);
        strcpy(a[i], names[i]);
    }
    *returnSize = namesSize;
    for (i = 0; i < namesSize; i++) {
        for (j = i + 1; j < namesSize; j++) {
            if (heights[i] < heights[j]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
                k = heights[i];
                heights[i] = heights[j];
                heights[j] = k;
            }
        }
    }
    return a;
}