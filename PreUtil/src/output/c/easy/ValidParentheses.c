/**https://leetcode.com/problems/valid-parentheses/ */
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.

bool isValid(char * s){
    int len = strlen(s);
    if(len % 2 != 0){
        return false;
    }
    char *stack = (char *)malloc(len * sizeof(char));
    int top = -1;
    for(int i = 0; i < len; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            top++;
            stack[top] = s[i];
        }
        else if(s[i] == ')'){
            if(top == -1 || stack[top] != '('){
                return false;
            }
            top--;
        }
        else if(s[i] == ']'){
            if(top == -1 || stack[top] != '['){
                return false;
            }
            top--;
        }
        else if(s[i] == '}'){
            if(top == -1 || stack[top] != '{'){
                return false;
            }
            top--;
        }
    }
    if(top == -1){
        return true;
    }
    return false;
    

}
    