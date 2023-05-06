/**https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//It is ().
//It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//It can be written as (A), where A is a valid parentheses string.
//You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
//If locked[i] is '1', you cannot change s[i].
//But if locked[i] is '0', you can change s[i] to either '(' or ')'.
//Return true if you can make s a valid parentheses string. Otherwise, return false.


bool canBeValid(char * s, char * locked){
    int i;
    int count = 0;
    int lock = 0;
    for(i = 0; i < strlen(s); i++){
        if(locked[i] == '1'){
            lock++;
        }
        if(s[i] == '('){
            count++;
        }
        else{
            count--;
        }
        if(count < 0){
            return false;
        }
    }
    if(count == 0){
        return true;
    }
    else if(count == lock){
        return true;
    }
    else{
        return false;
    }

}

    