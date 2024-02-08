/**https://leetcode.com/problems/interval-list-intersections/ */
//You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
//Return the intersection of these two interval lists.
//A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
//The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** intervalIntersection(int** firstList, int firstListSize, int* firstListColSize, int** secondList, int secondListSize, int* secondListColSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * firstListSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * firstListSize);
    for(int i = 0; i < firstListSize; i++){
        (*returnColumnSizes)[i] = 2;
    }
    int i = 0;
    int j = 0;
    while(i < firstListSize && j < secondListSize){
        int start = firstList[i][0] > secondList[j][0] ? firstList[i][0] : secondList[j][0];
        int end = firstList[i][1] < secondList[j][1] ? firstList[i][1] : secondList[j][1];
        if(start <= end){
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = start;
            result[*returnSize][1] = end;
            (*returnSize)++;
        }
        if(firstList[i][1] < secondList[j][1]){
            i++;
        }else{
            j++;
        }
    }
    return result;
}

    