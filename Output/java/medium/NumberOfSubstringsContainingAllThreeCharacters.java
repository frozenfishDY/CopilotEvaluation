/**https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ */
//Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.


class NumberOfSubstringsContainingAllThreeCharacters {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int[] count = new int[3];
        int res = 0;
        int unique = 0;
        for(int i = 0; i < n; i++){
            if(count[s.charAt(i) - 'a']++ == 0){
                unique++;
            }
            while(unique == 3){
                res += n - i;
                if(--count[s.charAt(i - res + 1) - 'a'] == 0){
                    unique--;
                }
            }
        }
        return res;
        
        
    }
}

    