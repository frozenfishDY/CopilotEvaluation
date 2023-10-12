/**https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/ */
//You are given a string s that consists of lower case English letters and brackets.
//Reverse the strings in each pair of matching parentheses, starting from the innermost one.
//Your result should not contain any brackets.
// 
//Example 1:
//Input: s = "(abcd)"
//Output: "dcba"
//Example 2:
//Input: s = "(u(love)i)"
//Output: "iloveu"
//Explanation: The substring "love" is reversed first, then the whole string is reversed.
//Example 3:
//Input: s = "(ed(et(oc))el)"
//Output: "leetcode"
//Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.
// 
//Constraints:
//	1 <= s.length <= 2000
//	s only contains lower case English characters and parentheses.
//	It is guaranteed that all parentheses are balanced.
char * reverseParentheses(char * s){
int len = strlen(s);
    int *stack = (int *)malloc(sizeof(int) * len);
    memset(stack, 0, sizeof(int) * len);
    int top = 0;
    int *next = (int *)malloc(sizeof(int) * len);
    memset(next, 0, sizeof(int) * len);
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            stack[top++] = i;
        } else if (s[i] == ')') {
            next[i] = stack[top - 1];
            next[stack[top - 1]] = i;
            --top;
        }
    }
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    memset(res, 0, sizeof(char) * (len + 1));
    int pos = 0;
    int add = 1;
    for (int i = 0; i < len; i += add) {
        if (s[i] == '(' || s[i] == ')') {
            i = next[i];
            add = -add;
        } else {
            res[pos++] = s[i];
        }
    }
    return res;
}