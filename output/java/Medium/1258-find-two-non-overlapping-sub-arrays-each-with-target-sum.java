/**https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/ */
//You are given an array of integers arr and an integer target.
//You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
//Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.


class FindTwoNonOverlappingSubArraysEachWithTargetSum {
    public int minSumOfLengths(int[] arr, int target) {
        int[] dp = new int[arr.length];
        int sum = 0;
        int min = Integer.MAX_VALUE;
        int minIndex = -1;
        for(int i = 0; i < arr.length; i++){
            sum += arr[i];
            if(sum == target){
                dp[i] = i + 1;
                if(min > dp[i]){
                    min = dp[i];
                    minIndex = i;
                }
            }
            for(int j = i - 1; j >= 0; j--){
                if(sum - arr[j] == target){
                    dp[j] = i - j + 1;
                    if(min > dp[j]){
                        min = dp[j];
                        minIndex = j;
                    }
                }
                if(sum - arr[j] > target){
                    break;
                }
            }
        }
        int min2 = Integer.MAX_VALUE;
        for(int i = 0; i < arr.length; i++){
            if(i == minIndex){
                continue;
            }
            if(dp[i] != 0){
                min2 = Math.min(min2, dp[i]);
            }
        }
        if(min2 == Integer.MAX_VALUE){
            return -1;
        }
        return min + min2;
        
    }
}

    