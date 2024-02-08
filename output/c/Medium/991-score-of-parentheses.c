/**https://leetcode.com/problems/score-of-parentheses/ */
//Given a balanced parentheses string s, return the score of the string.
//The score of a balanced parentheses string is based on the following rule:
//"()" has score 1.
//AB has score A + B, where A and B are balanced parentheses strings.
//(A) has score 2 * A, where A is a balanced parentheses string.


int scoreOfParentheses(char * s){
    int result = 0;
    int count = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '('){
            count++;
        }else{
            count--;
            if(s[i - 1] == '('){
                result += 1 << count;
            }
        }
    }
    return result;

}

    