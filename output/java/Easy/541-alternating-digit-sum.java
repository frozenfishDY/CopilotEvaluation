/**https://leetcode.com/problems/alternating-digit-sum/ */
//You are given a positive integer n. Each digit of n has a sign according to the following rules:
//The most significant digit is assigned a positive sign.
//Each other digit has an opposite sign to its adjacent digits.
//Return the sum of all digits with their corresponding sign.


class AlternatingDigitSum {
    public int alternateDigitSum(int n) {
        int sum = 0;
        int sign = 1;
        while(n > 0){
            sum += sign * (n % 10);
            sign *= -1;
            n /= 10;
        }
        return sum;
        
        
    }
}

    