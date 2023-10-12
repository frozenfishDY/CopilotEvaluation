/**https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/ */
//Given a string s of '(' , ')' and lowercase English characters.
//Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
//Formally, a parentheses string is valid if and only if:
//	It is the empty string, contains only lowercase characters, or
//	It can be written as AB (A concatenated with B), where A and B are valid strings, or
//	It can be written as (A), where A is a valid string.
// 
//Example 1:
//Input: s = "lee(t(c)o)de)"
//Output: "lee(t(c)o)de"
//Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
//Example 2:
//Input: s = "a)b(c)d"
//Output: "ab(c)d"
//Example 3:
//Input: s = "))(("
//Output: ""
//Explanation: An empty string is also valid.
// 
//Constraints:
//	1 <= s.length <= 105
//	s[i] is either'(' , ')', or lowercase English letter.
class Solution {
    public String minRemoveToMakeValid(String s) {
        // 1. create a stack to store the index of '('
		// 2. loop through the string
		// 2.1 if the current character is '(', push the index into the stack
		// 2.2 if the current character is ')', pop the index from the stack
		// 2.3 if the stack is empty, continue
		// 2.4 if the stack is not empty, update the character in the string to be '#'
		// 3. loop through the stack and update the character in the string to be '#'
		// 4. create a string builder to store the answer
		// 5. loop through the string
		// 5.1 if the current character is '#', continue
		// 5.2 otherwise, append the current character to the string builder
		// 6. return the string builder
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '(') {
                stack.push(i);
            }
            else if(c == ')') {
                if(stack.isEmpty()) {
                    s = s.substring(0, i) + "#" + s.substring(i+1);
                }
                else {
                    stack.pop();
                }
            }
        }
        while(!stack.isEmpty()) {
            int index = stack.pop();
            s = s.substring(0, index) + "#" + s.substring(index+1);
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c == '#') {
                continue;
            }
            sb.append(c);
        }
        return sb.toString();
    }
}