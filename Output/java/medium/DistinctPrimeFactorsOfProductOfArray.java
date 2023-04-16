/**https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/ */
//Given an array of positive integers nums, return the number of distinct prime factors in the product of the elements of nums.
//Note that:
//A number greater than 1 is called prime if it is divisible by only 1 and itself.
//An integer val1 is a factor of another integer val2 if val2 / val1 is an integer.


class DistinctPrimeFactorsOfProductOfArray {
    public int distinctPrimeFactors(int[] nums) {
        int n = nums.length;
        int[] cnt = new int[100001];
        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 2; j * j <= num; j++){
                if(num % j == 0){
                    cnt[j]++;
                    while(num % j == 0){
                        num /= j;
                    }
                }
            }
            if(num > 1){
                cnt[num]++;
            }
        }
        int res = 0;
        for(int i = 0; i < 100001; i++){
            if(cnt[i] > 0){
                res++;
            }
        }
        return res;
        
    }
}

    