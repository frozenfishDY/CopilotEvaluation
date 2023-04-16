/**https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression/ */
//You are given a valid boolean expression as a string expression consisting of the characters '1','0','&' (bitwise AND operator),'|' (bitwise OR operator),'(', and ')'.
//For example, "()1|1" and "(1)&()" are not valid while "1", "(((1))|(0))", and "1|(0&(1))" are valid expressions.
//Return the minimum cost to change the final value of the expression.
//For example, if expression = "1|1|(0&0)&1", its value is 1|1|(0&0)&1 = 1|1|0&1 = 1|0&1 = 1&1 = 1. We want to apply operations so that the new expression evaluates to 0.
//The cost of changing the final value of an expression is the number of operations performed on the expression. The types of operations are described as follows:
//Turn a '1' into a '0'.
//Turn a '0' into a '1'.
//Turn a '&' into a '|'.
//Turn a '|' into a '&'.
//Note: '&' does not take precedence over '|' in the order of calculation. Evaluate parentheses first, then in left-to-right order.


int minOperationsToFlip(char * expression){
    int i,j,k;
    int len = strlen(expression);
    int* arr = (int*)malloc(sizeof(int)*len);
    for(i=0;i<len;i++){
        arr[i] = 0;
    }
    for(i=0;i<len;i++){
        int num = 0;
        for(j=i;j<len;j++){
            num = num*10 + (expression[j]-'0');
            if(num<=100000){
                if(i==0){
                    arr[j] = 1;
                }
                else{
                    arr[j] = (arr[j] + arr2[i-1]) % 1000000007;
                }
            }
            else{
                break;
            }
        }
        for(j=0;j<len;j++){
            arr2[j] = arr[j];
        }
    }
    return arr[len-1];

}

    