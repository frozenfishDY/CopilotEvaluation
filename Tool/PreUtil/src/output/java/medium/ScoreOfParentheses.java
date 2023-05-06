/**https://leetcode.com/problems/score-of-parentheses/ */
//Given a balanced parentheses string s, return the score of the string.
//The score of a balanced parentheses string is based on the following rule:
//"()" has score 1.
//AB has score A + B, where A and B are balanced parentheses strings.
//(A) has score 2 * A, where A is a balanced parentheses string.


class ScoreOfParentheses {
    public int scoreOfParentheses(String s) {
        int res = 0;
        int bal = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '('){
                bal++;
            }else{
                bal--;
                if(s.charAt(i - 1) == '('){
                    res += 1 << bal;
                }
            }
        }
        return res;
        
        
    }
}

    