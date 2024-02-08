/**https://leetcode.com/problems/evaluate-reverse-polish-notation/ */
//You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//Evaluate the expression. Return an integer that represents the value of the expression.


class EvaluateReversePolishNotation {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for(String s : tokens){
            if(s.equals("+")){
                int a = stack.pop();
                int b = stack.pop();
                stack.push(a + b);
            }else if(s.equals("-")){
                int a = stack.pop();
                int b = stack.pop();
                stack.push(b - a);
            }else if(s.equals("*")){
                int a = stack.pop();
                int b = stack.pop();
                stack.push(a * b);
            }else if(s.equals("/")){
                int a = stack.pop();
                int b = stack.pop();
                stack.push(b / a);
            }else{
                stack.push(Integer.parseInt(s));
            }
        }
        return stack.pop();
        
        
        
    }
}

    