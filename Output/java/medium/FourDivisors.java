/**https://leetcode.com/problems/four-divisors/ */
//Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.


class FourDivisors {
    public int sumFourDivisors(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            int count = 0;
            int divisors = 0;
            for(int j = 1; j <= nums[i]; j++){
                if(nums[i] % j == 0){
                    count++;
                    divisors += j;
                }
            }
            if(count == 4){
                sum += divisors;
            }
        }
        return sum;
        
        
    }
}

    