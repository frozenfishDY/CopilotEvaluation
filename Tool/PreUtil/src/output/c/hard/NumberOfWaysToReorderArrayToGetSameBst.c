/**https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/ */
//Given an array nums that represents a permutation of integers from 1 to n. We are going to construct a binary search tree (BST) by inserting the elements of nums in order into an initially empty BST. Find the number of different ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.
//For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] yields a different BST.
//Return the number of ways to reorder nums such that the BST formed is identical to the original BST formed from nums.
//Since the answer may be very large, return it modulo 10^9 + 7.


int numOfWays(int* nums, int numsSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<numsSize;i++){
        arr[i] = arr[i-1] * i;
    }
    int sum = 0;
    for(i=0;i<numsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    