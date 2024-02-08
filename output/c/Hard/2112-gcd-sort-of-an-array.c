/**https://leetcode.com/problems/gcd-sort-of-an-array/ */
//You are given an integer array nums, and you can perform the following operation any number of times on nums:
//Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
//Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.


bool gcdSort(int* nums, int numsSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*numsSize);
    for(i=0;i<numsSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<numsSize;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[numsSize-1];

}

    