/**https://leetcode.com/problems/powx-n/ */
//Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).


class PowxN {
    public double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }
        if(n < 0){
            return 1 / myPow(x, -n);
        }
        if(n % 2 == 0){
            return myPow(x * x, n / 2);
        }
        return x * myPow(x, n - 1);
        
    }
}

    