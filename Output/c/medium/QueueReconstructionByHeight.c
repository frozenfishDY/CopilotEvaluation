/**https://leetcode.com/problems/queue-reconstruction-by-height/ */
//You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
//Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * peopleSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * peopleSize);
    for(int i = 0; i < peopleSize; i++){
        result[i] = (int*)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    int* height = (int*)malloc(sizeof(int) * 1001);
    for(int i = 0; i < 1001; i++){
        height[i] = 0;
    }
    for(int i = 0; i < peopleSize; i++){
        height[people[i][0]]++;
    }
    int* heightIndex = (int*)malloc(sizeof(int) * 1001);
    for(int i = 0; i < 1001; i++){
        heightIndex[i] = 0;
    }
    for(int i = 0; i < peopleSize; i++){
        int count = 0;
        for(int j = 0; j < people[i][0]; j++){
            count += height[j];
        }
        int index = count + people[i][1];
        while(heightIndex[people[i][0]] < index){
            heightIndex[people[i][0]]++;
            while(height[people[i][0]] == 0){
                people[i][0]++;
            }
        }
        result[index][0] = people[i][0];
        result[index][1] = people[i][1];
        height[people[i][0]]--;
    }
    *returnSize = peopleSize;
    return result;

}

    