/**https://leetcode.com/problems/count-binary-substrings/ */
//Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
//Substrings that occur multiple times are counted the number of times they occur.


class CountBinarySubstrings {
    public int countBinarySubstrings(String s) {
        int prev = 0;
        int curr = 1;
        int count = 0;
        for(int i = 1; i < s.length(); i++){
            if(s.charAt(i) == s.charAt(i - 1)){
                curr++;
            }else{
                prev = curr;
                curr = 1;
            }
            if(prev >= curr){
                count++;
            }
        }
        return count;
        
        
    }
}

    