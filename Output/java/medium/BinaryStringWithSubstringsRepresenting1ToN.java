/**https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/ */
//Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
//A substring is a contiguous sequence of characters within a string.


class BinaryStringWithSubstringsRepresenting1ToN {
    public boolean queryString(String s, int n) {
        for(int i = 1; i <= n; i++){
            if(!s.contains(Integer.toBinaryString(i))){
                return false;
            }
        }
        return true;
        
        
    }
}

    