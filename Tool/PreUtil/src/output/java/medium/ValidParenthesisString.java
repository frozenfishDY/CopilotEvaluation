/**https://leetcode.com/problems/valid-parenthesis-string/ */
//Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
//The following rules define a valid string:
//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//Any right parenthesis ')' must have a corresponding left parenthesis '('.
//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".


class ValidParenthesisString {
    public boolean checkValidString(String s) {
        int n = s.length();
        int[] left = new int[n + 1];
        int[] right = new int[n + 1];
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == '('){
                left[i + 1] = left[i] + 1;
                right[i + 1] = right[i];
            }else if(s.charAt(i) == ')'){
                left[i + 1] = Math.max(left[i] - 1, 0);
                right[i + 1] = right[i] + 1;
            }else{
                left[i + 1] = Math.max(left[i] - 1, 0);
                right[i + 1] = right[i] + 1;
            }
        }
        for(int i = 0; i <= n; i++){
            if(left[i] == 0 && right[i] == 0){
                return true;
            }
        }
        return false;
        
    }
}

    