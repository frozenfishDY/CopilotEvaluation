/**https://leetcode.com/problems/evaluate-reverse-polish-notation/ */
//You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//Evaluate the expression. Return an integer that represents the value of the expression.


int evalRPN(char ** tokens, int tokensSize){
    int* stack = (int*)calloc(tokensSize, sizeof(int));
    int top = -1;
    for(int i = 0; i < tokensSize; i++){
        if(strcmp(tokens[i], "+") == 0){
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = a + b;
        }
        else if(strcmp(tokens[i], "-") == 0){
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = b - a;
        }
        else if(strcmp(tokens[i], "*") == 0){
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = a * b;
        }
        else if(strcmp(tokens[i], "/") == 0){
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = b / a;
        }
        else{
            stack[++top] = atoi(tokens[i]);
        }
    }
    return stack[top];

}

    