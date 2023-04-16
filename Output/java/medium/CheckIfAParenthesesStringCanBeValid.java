/**https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/ */
//A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
//It is ().
//It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
//It can be written as (A), where A is a valid parentheses string.
//You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
//If locked[i] is '1', you cannot change s[i].
//But if locked[i] is '0', you can change s[i] to either '(' or ')'.
//Return true if you can make s a valid parentheses string. Otherwise, return false.


class CheckIfAParenthesesStringCanBeValid {
    public boolean canBeValid(String s, String locked) {
        int[] count = new int[2];
        for(int i = 0; i < s.length(); i++){
            if(locked.charAt(i) == '0'){
                if(s.charAt(i) == '('){
                    count[0]++;
                }else{
                    count[1]++;
                }
            }
        }
        return count[0] == count[1];
        
    }
}
     
    