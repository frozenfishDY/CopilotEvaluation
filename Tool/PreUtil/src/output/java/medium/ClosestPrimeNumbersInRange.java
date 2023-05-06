/**https://leetcode.com/problems/closest-prime-numbers-in-range/ */
//Given two positive integers left and right, find the two integers num1 and num2 such that:
//left <= nums1 < nums2 <= right .
//nums1 and nums2 are both prime numbers.
//nums2 - nums1 is the minimum amongst all other pairs satisfying the above conditions.
//Return the positive integer array ans = [nums1, nums2]. If there are multiple pairs satisfying these conditions, return the one with the minimum nums1 value or [-1, -1] if such numbers do not exist.
//A number greater than 1 is called prime if it is only divisible by 1 and itself.


class ClosestPrimeNumbersInRange {
    public int[] closestPrimes(int left, int right) {
        int[] res = new int[2];
        int min = Integer.MAX_VALUE;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                if(i - 1 >= left && isPrime(i - 1) && i - 1 - left < min){
                    min = i - 1 - left;
                    res[0] = i - 1;
                    res[1] = i;
                }
                if(i + 1 <= right && isPrime(i + 1) && right - i < min){
                    min = right - i;
                    res[0] = i;
                    res[1] = i + 1;
                }
            }
        }
        return res[0] == 0 ? new int[]{-1, -1} : res;
        
    }
}

    