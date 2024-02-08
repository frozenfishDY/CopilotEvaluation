/**https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/ */
//Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
//In case of a tie, return the minimum such integer.
//Notice that the answer is not neccesarilly a number from arr.


int findBestValue(int* arr, int arrSize, int target){
    int left = 0;
    int right = 0;
    for(int i = 0; i < arrSize; i++){
        right = fmax(right, arr[i]);
    }
    while(left < right){
        int mid = left + (right - left) / 2;
        int sum = 0;
        for(int i = 0; i < arrSize; i++){
            sum += fmin(arr[i], mid);
        }
        if(sum < target){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < arrSize; i++){
        sum1 += fmin(arr[i], left);
        sum2 += fmin(arr[i], left - 1);
    }
    return fabs(sum1 - target) <= fabs(sum2 - target) ? left : left - 1;

}

    