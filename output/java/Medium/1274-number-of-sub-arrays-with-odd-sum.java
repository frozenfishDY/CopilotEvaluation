/**https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/ */
//Given an array of integers arr, return the number of subarrays with an odd sum.
//Since the answer can be very large, return it modulo 109 + 7.


class NumberOfSubArraysWithOddSum {
    public int numOfSubarrays(int[] arr) {
        int odd = 0;
        int even = 0;
        int sum = 0;
        int mod = 1000000007;
        for(int i = 0; i < arr.length; i++){
            sum += arr[i];
            if(sum % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }
        return (odd + even) % mod;
        
        
    }
}

    