/**https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/ */
//Given an array of integers arr, return the number of subarrays with an odd sum.
//Since the answer can be very large, return it modulo 109 + 7.


int numOfSubarrays(int* arr, int arrSize){
    int odd = 0;
    int even = 0;
    int sum = 0;
    int count = 0;
    for(int i = 0; i < arrSize; i++){
        sum += arr[i];
        if(sum % 2 == 0){
            count += odd;
            even++;
        }else{
            count += even;
            odd++;
        }
    }
    return count % 1000000007;


}

    