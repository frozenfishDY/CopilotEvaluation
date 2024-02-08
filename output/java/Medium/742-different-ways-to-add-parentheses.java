/**https://leetcode.com/problems/different-ways-to-add-parentheses/ */
//Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
//The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.


class DifferentWaysToAddParentheses {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new ArrayList<>();
        for(int i = 0; i < expression.length(); i++){
            char c = expression.charAt(i);
            if(c == '+' || c == '-' || c == '*'){
                List<Integer> left = diffWaysToCompute(expression.substring(0, i));
                List<Integer> right = diffWaysToCompute(expression.substring(i + 1));
                for(int l : left){
                    for(int r : right){
                        if(c == '+'){
                            res.add(l + r);
                        }else if(c == '-'){
                            res.add(l - r);
                        }else{
                            res.add(l * r);
                        }
                    }
                }
            }
        }
        if(res.size() == 0){
            res.add(Integer.parseInt(expression));
        }
        return res;
        
        
    }
}

    