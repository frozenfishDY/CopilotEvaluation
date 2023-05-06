/**https://leetcode.com/problems/length-of-last-word/ */
//Given a string s consisting of words and spaces, return the length of the last word in the string.
//A word is a maximal substring consisting of non-space characters only.


class LengthOfLastWord {
    public int lengthOfLastWord(String s) {
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == ' '){
                if(count == 0){
                    continue;
                }else{
                    break;
                }
            }
            count++;
        }
        return count;
        
    }
}

    