/**https://leetcode.com/problems/sum-of-number-and-its-reverse/ */
//Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.


class SumOfNumberAndItsReverse {
    public boolean sumOfNumberAndReverse(int num) {
        int sum = 0;
        int reverse = 0;
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            reverse = reverse * 10 + digit;
            temp /= 10;
        }
        sum = num + reverse;
        while (sum > 0) {
            int digit = sum % 10;
            if (digit % 2 == 1) {
                return false;
            }
            sum /= 10;
        }
        return true;
        
    }
}
     
    