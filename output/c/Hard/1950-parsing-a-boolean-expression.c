/**https://leetcode.com/problems/parsing-a-boolean-expression/ */
//A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
//	't' that evaluates to true.
//	'f' that evaluates to false.
//	'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
//	'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
//	'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
//Given a string expression that represents a boolean expression, return the evaluation of that expression.
//It is guaranteed that the given expression is valid and follows the given rules.
// 
//Example 1:
//Input: expression = "&(|(f))"
//Output: false
//Explanation: 
//First, evaluate |(f) --> f. The expression is now "&(f)".
//Then, evaluate &(f) --> f. The expression is now "f".
//Finally, return false.
//Example 2:
//Input: expression = "|(f,f,f,t)"
//Output: true
//Explanation: The evaluation of (false OR false OR false OR true) is true.
//Example 3:
//Input: expression = "!(&(f,t))"
//Output: true
//Explanation: 
//First, evaluate &(f,t) --> (false AND true) --> false --> f. The expression is now "!(f)".
//Then, evaluate !(f) --> NOT false --> true. We return true.
// 
//Constraints:
//	1 <= expression.length <= 2 * 104
//	expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
bool parseBoolExpr(char * expression){
int len = strlen(expression);
    if (len == 1) return expression[0] == 't' ? true : false;
    if (expression[0] == '!') {
        int cnt = 0;
        for (int i = 2; i < len - 1; i++) {
            if (expression[i] == '(') cnt++;
            else if (expression[i] == ')') cnt--;
            if (cnt == 0 && expression[i] == ',') {
                if (expression[2] == 't') return false;
                else return true;
            }
        }
        return parseBoolExpr(expression + 2);
    } else if (expression[0] == '&') {
        int cnt = 0;
        bool res = true;
        for (int i = 2; i < len - 1; i++) {
            if (expression[i] == '(') cnt++;
            else if (expression[i] == ')') cnt--;
            if (cnt == 0 && expression[i] == ',') {
                if (expression[2] == 'f') return false;
                res &= parseBoolExpr(expression + 2);
                expression += (i - 1);
                len -= (i - 1);
                i = 1;
            }
        }
        return res;
    } else {
        int cnt = 0;
        bool res = false;
        for (int i = 2; i < len - 1; i++) {
            if (expression[i] == '(') cnt++;
            else if (expression[i] == ')') cnt--;
            if (cnt == 0 && expression[i] == ',') {
                if (expression[2] == 't') return true;
                res |= parseBoolExpr(expression + 2);
                expression += (i - 1);
                len -= (i - 1);
                i = 1;
            }
        }
        return res;
}