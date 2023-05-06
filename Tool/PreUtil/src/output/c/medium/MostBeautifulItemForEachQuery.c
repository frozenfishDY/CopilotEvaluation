/**https://leetcode.com/problems/most-beautiful-item-for-each-query/ */
//You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
//You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.
//Return an array answer of the same length as queries where answer[j] is the answer to the jth query.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maximumBeauty(int** items, int itemsSize, int* itemsColSize, int* queries, int queriesSize, int* returnSize){
    int* arr = malloc(queriesSize * sizeof(int));
    int i, j, k, max;
    for(i = 0; i < queriesSize; i++){
        max = 0;
        for(j = 0; j < itemsSize; j++){
            if(items[j][0] <= queries[i]){
                if(items[j][1] > max){
                    max = items[j][1];
                }
            }
        }
        arr[i] = max;
    }
    *returnSize = queriesSize;
    return arr;

}

    