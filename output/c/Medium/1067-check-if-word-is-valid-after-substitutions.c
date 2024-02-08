/**https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/ */
//Given a string s, determine if it is valid.
//A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
//Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
//Return true if s is a valid string, otherwise, return false.


bool isValid(char * s){
    int len = strlen(s);
    if(len % 3 != 0){
        return false;
    }
    char stack[len];
    int top = -1;
    for(int i = 0; i < len; i++){
        if(s[i] == 'a'){
            stack[++top] = s[i];
        }
        else if(s[i] == 'b'){
            if(top == -1 || stack[top] != 'a'){
                return false;
            }
            stack[++top] = s[i];
        }
        else{
            if(top == -1 || stack[top] != 'b'){
                return false;
            }
            top--;
            if(top == -1 || stack[top] != 'a'){
                return false;
            }
            top--;
        }
    }
    return top == -1;

}

    