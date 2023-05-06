/**https://leetcode.com/problems/valid-parenthesis-string/ */
//Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//The following rules define a valid string:
//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//Any right parenthesis ')' must have a corresponding left parenthesis '('.
//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


bool checkValidString(char * s){
    int left = 0;
    int right = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            left++;
        }else{
            left--;
        }
        if(s[len - i - 1] == ')'){
            right++;
        }else{
            right--;
        }
        if(left < 0 || right < 0){
            return false;
        }
    }
    return true;


}

    