/**https://leetcode.com/problems/string-to-integer-atoi/ */
//Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).
//The algorithm for myAtoi(string s) is as follows:
//Read in and ignore any leading whitespace.
//Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
//Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
//Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
//If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
//Return the integer as the final result.
//Note:
//Only the space character ' ' is considered a whitespace character.
//Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.


int myAtoi(char * s){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(s);
    int flag = 0;
    int sign = 1;
    int result = 0;
    int temp = 0;
    for(i = 0; i < len; i++){
        if(s[i] == ' '){
            continue;
        }
        else if(s[i] == '-'){
            sign = -1;
            i++;
            break;
        }
        else if(s[i] == '+'){
            sign = 1;
            i++;
            break;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            break;
        }
        else{
            return 0;
        }
    }
    for(j = i; j < len; j++){
        if(s[j] >= '0' && s[j] <= '9'){
            temp = s[j] - '0';
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && temp > 7)){
                if(sign == 1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }
            result = result * 10 + temp;
        }
        else{
            break;
        }
    }
    return result * sign;

}

    