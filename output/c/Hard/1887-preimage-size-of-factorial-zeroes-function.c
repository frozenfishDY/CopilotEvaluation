/**https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/ */
//Let f(x) be the number of zeroes at the end of x!. Recall that x! = 1 * 2 * 3 * ... * x and by convention, 0! = 1.
//For example, f(3) = 0 because 3! = 6 has no zeroes at the end, while f(11) = 2 because 11! = 39916800 has two zeroes at the end.
//Given an integer k, return the number of non-negative integers x have the property that f(x) = k.


int preimageSizeFZF(int k){
    long long l = 0, r = 5LL * (k + 1);
    while (l < r) {
        long long m = l + (r - l) / 2;
        long long z = 0;
        for (long long i = m; i > 0; i /= 5) {
            z += i / 5;
        }
        if (z < k) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return r == 5LL * (k + 1) ? 0 : 5;

}

    