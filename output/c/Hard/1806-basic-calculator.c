/**https://leetcode.com/problems/basic-calculator/ */
//Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
//Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


int calculate(char * s){
    int len = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * len);
    int top = -1;
    int num = 0;
    int sign = 1;
    int res = 0;
    for(int i = 0; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num = num * 10 + s[i] - '0';
        }else if(s[i] == '+'){
            res += sign * num;
            num = 0;
            sign = 1;
        }else if(s[i] == '-'){
            res += sign * num;
            num = 0;
            sign = -1;
        }else if(s[i] == '('){
            stack[++top] = res;
            stack[++top] = sign;
            res = 0;
            sign = 1;
        }else if(s[i] == ')'){
            res += sign * num;
            num = 0;
            res *= stack[top--];
            res += stack[top--];
        }
    }
    if(num != 0) res += sign * num;
    return res;

}

    