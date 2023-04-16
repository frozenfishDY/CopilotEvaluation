/**https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/ */
//Given a string s, determine if it is valid.
//A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:
//Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
//Return true if s is a valid string, otherwise, return false.


class CheckIfWordIsValidAfterSubstitutions {
    public boolean isValid(String s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'a'){
                count++;
            }else if(s.charAt(i) == 'b'){
                count--;
            }else{
                count--;
                if(count < 0){
                    return false;
                }
            }
        }
        return count == 0;
        
    }
}

    