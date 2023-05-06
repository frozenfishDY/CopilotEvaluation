/**https://leetcode.com/problems/validate-stack-sequences/ */
//Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.


class ValidateStackSequences {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int n = pushed.length;
        int m = popped.length;
        if(n != m){
            return false;
        }
        Stack<Integer> stack = new Stack<>();
        int i = 0;
        int j = 0;
        while(i < n){
            stack.push(pushed[i]);
            while(!stack.isEmpty() && stack.peek() == popped[j]){
                stack.pop();
                j++;
            }
            i++;
        }
        return stack.isEmpty();
        
    }
}

    