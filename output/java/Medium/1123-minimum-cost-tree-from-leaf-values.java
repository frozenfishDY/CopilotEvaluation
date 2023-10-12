/**https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/ */
//Given an array arr of positive integers, consider all binary trees such that:
//	Each node has either 0 or 2 children;
//	The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
//	The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
//Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
//A node is a leaf if and only if it has zero children.
// 
//Example 1:
//Input: arr = [6,2,4]
//Output: 32
//Explanation: There are two possible trees shown.
//The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
//Example 2:
//Input: arr = [4,11]
//Output: 44
// 
//Constraints:
//	2 <= arr.length <= 40
//	1 <= arr[i] <= 15
//	It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
class Solution {
    public int mctFromLeafValues(int[] arr) {
        // 1. create a variable to store the result
		// 2. create a stack to store the numbers
		// 3. loop the array
		// 3.1 while the stack is not empty and the current number is greater than the top of the stack
		// 3.1.1 pop the top of the stack
		// 3.1.2 add the product of the current number and the top of the stack to the result
		// 3.2 push the current number to the stack
		// 4. while the stack is not empty
		// 4.1 pop the top of the stack
		// 4.2 if the stack is not empty
		// 4.2.1 add the product of the top of the stack and the top of the stack to the result
		// 5. return the result
        int result = 0;
        Stack<Integer> stack = new Stack<>();
        for(int i = 0; i < arr.length; i++) {
            while(!stack.isEmpty() && arr[i] > stack.peek()) {
                int temp = stack.pop();
                if(!stack.isEmpty()) {
                    result += temp * Math.min(stack.peek(), arr[i]);
                }
                else {
                    result += temp * arr[i];
                }
            }
            stack.push(arr[i]);
        }
        while(!stack.isEmpty()) {
            int temp = stack.pop();
            if(!stack.isEmpty()) {
                result += temp * stack.peek();
            }
        }
        return result;
    }
}