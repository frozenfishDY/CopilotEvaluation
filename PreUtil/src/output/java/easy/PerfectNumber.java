/**https://leetcode.com/problems/perfect-number/ */
//A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
//Given an integer n, return true if n is a perfect number, otherwise return false.


class PerfectNumber {
    public boolean checkPerfectNumber(int num) {
        if(num == 1) return false;
        int sum = 1;
        for(int i = 2; i <= Math.sqrt(num); i++){
            if(num % i == 0){
                sum += i;
                if(i != num / i){
                    sum += num / i;
                }
            }
        }
        return sum == num;
        
    }
}

    