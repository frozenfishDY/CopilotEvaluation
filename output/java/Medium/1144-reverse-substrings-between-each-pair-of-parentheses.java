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
class Solution {
    public String reverseParentheses(String s) {
        // 1. create a stack to store the characters
		// 2. loop through the string
		// 2.1 if the character is not ')', push it into the stack
		// 2.2 if the character is ')', pop the characters until the '('
		// 2.3 reverse the substring and push it into the stack
		// 3. create a string builder to store the characters
		// 4. loop through the stack and append the characters to the string builder
		// 5. return the string
        Stack<Character> stack = new Stack<>();
        for(char c: s.toCharArray()) {
            if(c != ')') {
                stack.push(c);
            }
            else {
                Queue<Character> queue = new LinkedList<>();
                while(!stack.isEmpty() && stack.peek() != '(') {
                    queue.offer(stack.pop());
                }
                stack.pop();
                while(!queue.isEmpty()) {
                    stack.push(queue.poll());
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        return sb.reverse().toString();
    }
}