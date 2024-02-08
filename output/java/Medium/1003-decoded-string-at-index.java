/**https://leetcode.com/problems/decoded-string-at-index/ */
//You are given an encoded string s. To decode the string to a tape, the encoded string is read one character at a time and the following steps are taken:
//If the character read is a letter, that letter is written onto the tape.
//If the character read is a digit d, the entire current tape is repeatedly written d - 1 more times in total.
//Given an integer k, return the kth letter (1-indexed) in the decoded string.


class DecodedStringAtIndex {
    public String decodeAtIndex(String s, int k) {
        long size = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)){
                size *= c - '0';
            }else{
                size++;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            char c = s.charAt(i);
            k %= size;
            if(k == 0 && Character.isLetter(c)){
                return Character.toString(c);
            }
            if(Character.isDigit(c)){
                size /= c - '0';
            }else{
                size--;
            }
        }
        return null;
        
        
        
    }
}

    