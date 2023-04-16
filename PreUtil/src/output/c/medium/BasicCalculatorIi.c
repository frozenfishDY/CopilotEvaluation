/**https://leetcode.com/problems/basic-calculator-ii/ */
//Given a string s which represents an expression, evaluate this expression and return its value. 
//The integer division should truncate toward zero.
//You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
//Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


int calculate(char * s){
    int len = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * len);
    int top = -1;
    int num = 0;
    char sign = '+';
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';
        }
        if((s[i] < '0' && s[i] != ' ') || i == len - 1){
            if(sign == '+'){
                stack[++top] = num;
            }
            else if(sign == '-'){
                stack[++top] = -num;
            }
            else if(sign == '*'){
                stack[top] = stack[top] * num;
            }
            else if(sign == '/'){
                stack[top] = stack[top] / num;
            }
            sign = s[i];
            num = 0;
        }
    }
    int result = 0;
    for(int i = 0; i <= top; i++){
        result += stack[i];
    }
    return result;

}

    