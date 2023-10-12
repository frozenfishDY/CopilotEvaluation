/**https://leetcode.com/problems/remove-invalid-parentheses/ */
//Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
//Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.
// 
//Example 1:
//Input: s = "()())()"
//Output: ["(())()","()()()"]
//Example 2:
//Input: s = "(a)())()"
//Output: ["(a())()","(a)()()"]
//Example 3:
//Input: s = ")("
//Output: [""]
// 
//Constraints:
//	1 <= s.length <= 25
//	s consists of lowercase English letters and parentheses '(' and ')'.
//	There will be at most 20 parentheses in s.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeInvalidParentheses(char * s, int* returnSize){
*returnSize = 0;
    char **res = (char **)malloc(sizeof(char *) * 10000);
    for (int i = 0; i < 10000; i++) {
        res[i] = (char *)malloc(sizeof(char) * 1000);
    }
    char *p = res[0];
    int len = strlen(s);
    int left = 0, right = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') left++;
        if (s[i] == ')') {
            if (left > 0) left--;
            else right++;
        }
    }
    dfs(s, len, 0, left, right, 0, 0, res, returnSize, p);
    return res;
}
void dfs(char *s, int len, int start, int left, int right, int l, int r, char **res, int *returnSize, char *p) {
    if (start == len) {
        if (left == 0 && right == 0) {
            *p = '\0';
            strcpy(res[*returnSize], res[0]);
            (*returnSize)++;
        }
        return;
    }
    if (s[start] == '(') {
        if (left > 0) {
            dfs(s, len, start + 1, left - 1, right, l, r, res, returnSize, p);
        }
        p += sprintf(p, "(");
        dfs(s, len, start + 1, left, right, l + 1, r, res, returnSize, p);
    } else if (s[start] == ')') {
        if (right > 0) {
            dfs(s, len, start + 1, left, right - 1, l, r, res, returnSize, p);
        }
        if (l > r) {
            p += sprintf(p, ")");
            dfs(s, len, start + 1, left, right, l, r + 1, res, returnSize, p);
        }
    } else {
        p += sprintf(p, "%c", s[start]);
        dfs(s, len, start + 1, left, right, l, r, res, returnSize, p);
    }
    *p = '\0';
    p--;
}