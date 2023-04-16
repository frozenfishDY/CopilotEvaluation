/**https://leetcode.com/problems/bitwise-ors-of-subarrays/ */
//Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
//The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
//A subarray is a contiguous non-empty sequence of elements within an array.


int subarrayBitwiseORs(int* arr, int arrSize){
    int* hash = (int*)malloc(sizeof(int) * 100000);
    for(int i = 0; i < 100000; i++){
        hash[i] = 0;
    }
    int result = 0;
    for(int i = 0; i < arrSize; i++){
        int temp = arr[i];
        for(int j = i; j < arrSize; j++){
            temp = temp | arr[j];
            if(hash[temp] == 0){
                hash[temp] = 1;
                result++;
            }
        }
    }
    return result;

}

    