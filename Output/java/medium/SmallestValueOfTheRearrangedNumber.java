/**https://leetcode.com/problems/smallest-value-of-the-rearranged-number/ */
//You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
//Return the rearranged number with minimal value.
//Note that the sign of the number does not change after rearranging the digits.


class SmallestValueOfTheRearrangedNumber {
    public long smallestNumber(long num) {
        long[] digits = new long[10];
        long n = num;
        while(n > 0){
            digits[(int)(n % 10)]++;
            n /= 10;
        }
        long res = 0;
        for(int i = 1; i < 10; i++){
            while(digits[i] > 0){
                res = res * 10 + i;
                digits[i]--;
            }
        }
        while(digits[0] > 0){
            res = res * 10;
            digits[0]--;
        }
        return res;
        
    }
}
     
    