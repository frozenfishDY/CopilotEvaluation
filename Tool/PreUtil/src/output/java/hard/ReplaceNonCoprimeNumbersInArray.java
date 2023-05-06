/**https://leetcode.com/problems/replace-non-coprime-numbers-in-array/ */
//You are given an array of integers nums. Perform the following steps:
//Find any two adjacent numbers in nums that are non-coprime.
//If no such numbers are found, stop the process.
//Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
//Repeat this process as long as you keep finding two adjacent non-coprime numbers.
//Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.
//The test cases are generated such that the values in the final array are less than or equal to 108.
//Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.


class ReplaceNonCoprimeNumbersInArray {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        int n = nums.length;
        int[] primes = new int[100001];
        for (int i = 2; i < primes.length; i++) {
            if (primes[i] == 0) {
                for (int j = i; j < primes.length; j += i) {
                    primes[j] = i;
                }
            }
        }
        int[] next = new int[n];
        Arrays.fill(next, -1);
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            while (num > 1) {
                int prime = primes[num];
                if (next[prime] != -1) {
                    next[i] = next[prime];
                    break;
                }
                while (num % prime == 0) {
                    num /= prime;
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (next[i] == -1) {
                res.add(nums[i]);
            } else {
                int lcm = nums[i] * nums[next[i]] / primes[nums[i]];
                res.add(lcm);
                i = next[i];
            }
        }
        return res;
        
    }
}
     
    