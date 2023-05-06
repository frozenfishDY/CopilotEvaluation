/**https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/ */
//You are given two positive integers n and target.
//An integer is considered beautiful if the sum of its digits is less than or equal to target.
//Return the minimum non-negative integer x such that n + x is beautiful. The input will be generated such that it is always possible to make n beautiful.


class MinimumAdditionToMakeIntegerBeautiful {
    public long makeIntegerBeautiful(long n, int target) {
        long sum = 0;
        long num = n;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        if(sum <= target){
            return 0;
        }
        long count = 0;
        long base = 1;
        while(sum > target){
            long digit = n / base % 10;
            long diff = 10 - digit;
            count += diff * base;
            sum -= digit;
            sum += 9;
            base *= 10;
        }
        return count;
        
    }
}
     
    