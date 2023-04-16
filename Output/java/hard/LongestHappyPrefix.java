/**https://leetcode.com/problems/longest-happy-prefix/ */
//A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
//Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.


class LongestHappyPrefix {
    public String longestPrefix(String s) {
        int n = s.length();
        int[] lps = new int[n];
        int i = 1;
        int j = 0;
        while(i < n){
            if(s.charAt(i) == s.charAt(j)){
                lps[i] = j + 1;
                i++;
                j++;
            }else{
                if(j != 0){
                    j = lps[j - 1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.substring(0, lps[n - 1]);
        
    }
}
     
    