/**https://leetcode.com/problems/expression-add-operators/ */
//Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
//Note that operands in the returned expressions should not contain leading zeros.
// 
//Example 1:
//Input: num = "123", target = 6
//Output: ["1*2*3","1+2+3"]
//Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
//Example 2:
//Input: num = "232", target = 8
//Output: ["2*3+2","2+3*2"]
//Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
//Example 3:
//Input: num = "3456237490", target = 9191
//Output: []
//Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
// 
//Constraints:
//	1 <= num.length <= 10
//	num consists of only digits.
//	-231 <= target <= 231 - 1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** addOperators(char * num, int target, int* returnSize){
*returnSize = 0;
    int len = strlen(num);
    char **res = (char **)malloc(sizeof(char *) * 10000);
    for (int i = 0; i < 10000; i++) {
        res[i] = (char *)malloc(sizeof(char) * 1000);
    }
    char *p = res[0];
    long long n = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && n == 0) break;
        n = n * 10 + num[i] - '0';
        sprintf(p++, "%c", num[i]);
        dfs(num, target, len, i + 1, n, n, res, returnSize, p);
        if (n == 0) break;
    }
    return res;
}
void dfs(char *num, int target, int len, int start, long long sum, long long last, char **res, int *returnSize, char *p) {
    if (start == len) {
        if (sum == target) {
            *p = '\0';
            strcpy(res[*returnSize], res[0]);
            (*returnSize)++;
        }
        return;
    }
    int i = start;
    char *q = p;
    p += sprintf(p, "+%c", num[i]);
    dfs(num, target, len, i + 1, sum + num[i] - '0', num[i] - '0', res, returnSize, p);
    *q = '\0';
    p = q;
    p += sprintf(p, "-%c", num[i]);
    dfs(num, target, len, i + 1, sum - num[i] + '0', - (num[i] - '0'), res, returnSize, p);
    *q = '\0';
    p = q;
    p += sprintf(p, "*%c", num[i]);
    dfs(num, target, len, i + 1, sum - last + last * (num[i] - '0'), last * (num[i] - '0'), res, returnSize, p);
    *q = '\0';
    p = q;
    if (last != 0) {
        p += sprintf(p, "%c", num[i]);
        dfs(num, target, len, i + 1, sum - last + last * 10 + (num[i] - '0'), last * 10 + (num[i] - '0'), res, returnSize, p);
    }
    *q = '\0';
    p = q;
}