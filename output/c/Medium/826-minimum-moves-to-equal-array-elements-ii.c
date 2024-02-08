/**https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/ */
//Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//In one move, you can increment or decrement an element of the array by 1.
//Test cases are designed so that the answer will fit in a 32-bit integer.


int minMoves2(int* nums, int numsSize){
    int* numsCount = (int*)malloc(sizeof(int) * 100000);
    for(int i = 0; i < 100000; i++){
        numsCount[i] = 0;
    }
    for(int i = 0; i < numsSize; i++){
        numsCount[nums[i] + 50000]++;
    }
    int* numsCountSum = (int*)malloc(sizeof(int) * 100000);
    numsCountSum[0] = numsCount[0];
    for(int i = 1; i < 100000; i++){
        numsCountSum[i] = numsCountSum[i - 1] + numsCount[i];
    }
    int* numsCountSumReverse = (int*)malloc(sizeof(int) * 100000);
    numsCountSumReverse[99999] = numsCount[99999];
    for(int i = 99998; i >= 0; i--){
        numsCountSumReverse[i] = numsCountSumReverse[i + 1] + numsCount[i];
    }
    int min = numsCountSum[0];
    for(int i = 1; i < 100000; i++){
        if(numsCountSum[i] < min){
            min = numsCountSum[i];
        }
    }
    int minIndex = 0;
    for(int i = 0; i < 100000; i++){
        if(numsCountSum[i] == min){
            minIndex = i;
            break;
        }
    }
    int count = 0;
    for(int i = 0; i < minIndex; i++){
        count += numsCount[i] * (minIndex - i);
    }
    for(int i = minIndex + 1; i < 100000; i++){
        count += numsCount[i] * (i - minIndex);
    }
    return count;

}

    