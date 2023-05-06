/**https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/ */
//There is a family tree rooted at 0 consisting of n nodes numbered 0 to n - 1. You are given a 0-indexed integer array parents, where parents[i] is the parent for node i. Since node 0 is the root, parents[0] == -1.
//There are 105 genetic values, each represented by an integer in the inclusive range [1, 105]. You are given a 0-indexed integer array nums, where nums[i] is a distinct genetic value for node i.
//Return an array ans of length n where ans[i] is the smallest genetic value that is missing from the subtree rooted at node i.
//The subtree rooted at a node x contains node x and all of its descendant nodes.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallestMissingValueSubtree(int* parents, int parentsSize, int* nums, int numsSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*parentsSize);
    for(i=0;i<parentsSize;i++){
        arr13[i] = 0;
    }

}

    