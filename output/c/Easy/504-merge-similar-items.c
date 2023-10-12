/**https://leetcode.com/problems/merge-similar-items/ */
//You are given two 2D integer arrays, items1 and items2, representing two sets of items. Each array items has the following properties:
//	items[i] = [valuei, weighti] where valuei represents the value and weighti represents the weight of the ith item.
//	The value of each item in items is unique.
//Return a 2D integer array ret where ret[i] = [valuei, weighti], with weighti being the sum of weights of all items with value valuei.
//Note: ret should be returned in ascending order by value.
// 
//Example 1:
//Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
//Output: [[1,6],[3,9],[4,5]]
//Explanation: 
//The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
//The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
//The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
//Therefore, we return [[1,6],[3,9],[4,5]].
//Example 2:
//Input: items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
//Output: [[1,4],[2,4],[3,4]]
//Explanation: 
//The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 3, total weight = 1 + 3 = 4.
//The item with value = 2 occurs in items1 with weight = 3 and in items2 with weight = 1, total weight = 3 + 1 = 4.
//The item with value = 3 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4.
//Therefore, we return [[1,4],[2,4],[3,4]].
//Example 3:
//Input: items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
//Output: [[1,7],[2,4],[7,1]]
//Explanation:
//The item with value = 1 occurs in items1 with weight = 3 and in items2 with weight = 4, total weight = 3 + 4 = 7. 
//The item with value = 2 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4. 
//The item with value = 7 occurs in items2 with weight = 1, total weight = 1.
//Therefore, we return [[1,7],[2,4],[7,1]].
// 
//Constraints:
//	1 <= items1.length, items2.length <= 1000
//	items1[i].length == items2[i].length == 2
//	1 <= valuei, weighti <= 1000
//	Each valuei in items1 is unique.
//	Each valuei in items2 is unique.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes){
int **res = NULL;
    int resSize = 0;
    int *hash = (int*)calloc(1000, sizeof(int));
    int i = 0, j = 0, k = 0;
    for (; i < items1Size; i++) {
        memset(hash, 0, 1000 * sizeof(int));
        for (j = 0; j < items1ColSize[i]; j++) {
            hash[items1[i][j] - 1]++;
            if (hash[items1[i][j] - 1] == items1Size) {
                int *tmp = (int*)realloc(res, sizeof(int) * (resSize + 1));
                if (NULL != tmp) {
                    res = tmp;
                    res[resSize++] = items1[i][j];
                }
            }
        }
    }
    *returnSize = resSize;
    return res;
}