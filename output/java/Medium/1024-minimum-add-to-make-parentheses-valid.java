/**https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/ */
//A parentheses string is valid if and only if:
//It is the empty string,
//It can be written as AB (A concatenated with B), where A and B are valid strings, or
//It can be written as (A), where A is a valid string.
//You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
//For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
//Return the minimum number of moves required to make s valid.


class MinimumAddToMakeParenthesesValid {
    public int minAddToMakeValid(String s) {
        int res = 0;
        int cnt = 0;
        for(char c : s.toCharArray()){
            if(c == '('){
                cnt++;
            }else{
                if(cnt == 0){
                    res++;
                }else{
                    cnt--;
                }
            }
        }
        return res + cnt;
        
    }
}

    