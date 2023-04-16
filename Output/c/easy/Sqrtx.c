/**https://leetcode.com/problems/sqrtx/ */
//Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
//You must not use any built-in exponent function or operator.
//For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

int mySqrt(int x){
    if(x == 0){
        return 0;
    }
    int left = 1;
    int right = x;
    while(left < right){
        int mid = left + (right - left) / 2;
        if(mid > x / mid){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left - 1;

}
    