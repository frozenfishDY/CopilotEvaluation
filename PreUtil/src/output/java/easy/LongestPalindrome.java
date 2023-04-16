/**https://leetcode.com/problems/longest-palindrome/ */
//Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//Letters are case sensitive, for example, "Aa" is not considered a palindrome here.


class LongestPalindrome {
    public int longestPalindrome(String s) {
        int[] count = new int[128];
        for(int i = 0; i < s.length(); i++){
            count[s.charAt(i)]++;
        }
        int result = 0;
        for(int i = 0; i < count.length; i++){
            result += count[i] / 2 * 2;
            if(result % 2 == 0 && count[i] % 2 == 1){
                result++;
            }
        }
        return result;
        
    }
}

    