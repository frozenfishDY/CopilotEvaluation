/**https://leetcode.com/problems/number-of-atoms/ */
//Given a string formula representing a chemical formula, return the count of each atom.
//The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
//One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.
//	For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
//Two formulas are concatenated together to produce another formula.
//	For example, "H2O2He3Mg4" is also a formula.
//A formula placed in parentheses, and a count (optionally added) is also a formula.
//	For example, "(H2O2)" and "(H2O2)3" are formulas.
//Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.
//The test cases are generated so that all the values in the output fit in a 32-bit integer.
// 
//Example 1:
//Input: formula = "H2O"
//Output: "H2O"
//Explanation: The count of elements are {'H': 2, 'O': 1}.
//Example 2:
//Input: formula = "Mg(OH)2"
//Output: "H2MgO2"
//Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
//Example 3:
//Input: formula = "K4(ON(SO3)2)2"
//Output: "K4N2O14S4"
//Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
// 
//Constraints:
//	1 <= formula.length <= 1000
//	formula consists of English letters, digits, '(', and ')'.
//	formula is always valid.
char * countOfAtoms(char * formula){ 
  int len = strlen(formula);
    char *res = (char *)malloc(sizeof(char) * 10000);
    char *p = res;
    int i = 0;
    int *stack = (int *)malloc(sizeof(int) * len);
    int top = -1;
    while (i < len) {
        if (formula[i] == '(') {
            top++;
            stack[top] = i;
            i++;
        } else if (formula[i] == ')') {
            int j = i + 1;
            int num = 0;
            while (j < len && formula[j] >= '0' && formula[j] <= '9') {
                num = num * 10 + formula[j] - '0';
                j++;
            }
            if (num == 0) num = 1;
            int temp = top;
            while (stack[temp] != -1 && formula[stack[temp]] != '(') {
                stack[temp] = -1;
                temp--;
            }
            stack[temp] = -1;
            top = temp - 1;
            for (int k = 0; k < num; k++) {
                temp++;
                stack[temp] = -2;
            }
            i = j;
        } else if (formula[i] >= 'A' && formula[i] <= 'Z') {
            int j = i + 1;
            while (j < len && formula[j] >= 'a' && formula[j] <= 'z') {
                j++;
            }
            int num = 0;
            while (j < len && formula[j] >= '0' && formula[j] <= '9') {
                num = num * 10 + formula[j] - '0';
                j++;
            }
            if (num == 0) num = 1;
            for (int k = 0; k < num; k++) {
                top++;
                stack[top] = i;
            }
            i = j;
        }
    }
    int *count = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        count[i] = 0;
    }
    for (int i = 0; i <= top; i++) {
        if (stack[i] == -1) continue;
        int j = stack[i] + 1;
        if (formula[j] >= 'a' && formula[j] <= 'z') j++;
        int num = 0;
        while (j < len && formula[j] >= '0' && formula[j] <= '9') {
            num = num * 10 + formula[j] - '0';
            j++;
        }
        if (num == 0) num = 1;
        count[stack[i]] += num;
    }
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (count[i] == 0) continue;
        sprintf(p, "%c", formula[i]);
        p++;
        if (count[i] > 1) {
            sprintf(p, "%d", count[i]);
            p += strlen(p);
        }
    }
    *p = '\0';
    return res;
}
