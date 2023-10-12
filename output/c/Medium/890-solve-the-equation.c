/**https://leetcode.com/problems/solve-the-equation/ */
//Solve a given equation and return the value of 'x' in the form of a string "x=#value". The equation contains only '+', '-' operation, the variable 'x' and its coefficient. You should return "No solution" if there is no solution for the equation, or "Infinite solutions" if there are infinite solutions for the equation.
//If there is exactly one solution for the equation, we ensure that the value of 'x' is an integer.
// 
//Example 1:
//Input: equation = "x+5-3+x=6+x-2"
//Output: "x=2"
//Example 2:
//Input: equation = "x=x"
//Output: "Infinite solutions"
//Example 3:
//Input: equation = "2x=x"
//Output: "x=0"
// 
//Constraints:
//	3 <= equation.length <= 1000
//	equation has exactly one '='.
//	equation consists of integers with an absolute value in the range [0, 100] without any leading zeros, and the variable 'x'.
char * solveEquation(char * equation){  
 char* res = (char*)malloc(sizeof(char) * 100);
    int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0;
    int len = strlen(equation);
    int sign = 1;
    int a = 0, b = 0;
    int x = 0;
    while (j < len) {
        if (equation[j] == '=') {
            sign = -1;
            j++;
        } else if (equation[j] == 'x') {
            if (i == j || equation[j - 1] == '+') {
                a += sign;
            } else if (equation[j - 1] == '-') {
                a -= sign;
            } else {
                a += sign * atoi(equation + i);
            }
            i = ++j;
        } else if (equation[j] == '+' || equation[j] == '-') {
            if (i != j) {
                b += sign * atoi(equation + i);
            }
            i = j++;
        } else {
            j++;
        }
    }
    if (i != j) {
        b += sign * atoi(equation + i);
    }
    if (a == 0) {
        if (b == 0) {
            return "Infinite solutions";
        } else {
            return "No solution";
        }
    } else {
        sprintf(res, "x=%d", -b / a);
        return res;
    }
}