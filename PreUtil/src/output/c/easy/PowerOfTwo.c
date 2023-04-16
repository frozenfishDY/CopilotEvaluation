/**https://leetcode.com/problems/power-of-two/ */
//Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.


bool isPowerOfTwo(int n){
    if(n <= 0){
        return false;
    }
    while(n != 1){
        if(n % 2 != 0){
            return false;
        }
        n = n / 2;
    }
    return true;

}

    