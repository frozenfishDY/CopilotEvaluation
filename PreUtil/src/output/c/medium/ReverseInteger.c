/**https://leetcode.com/problems/reverse-integer/ */
//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


int reverse(int x){
    int result = 0;
    int temp = 0;
    while(x != 0){
        temp = x % 10;
        x = x / 10;
        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > 7)){
            return 0;
        }
        if(result < INT_MIN / 10 || (result == INT_MIN / 10 && temp < -8)){
            return 0;
        }
        result = result * 10 + temp;
    }
    return result;

}

    