/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.


class FindTheLongestSubstringContainingVowelsInEvenCounts {
    public int findTheLongestSubstring(String s) {
        int n = s.length();
        int[] count = new int[26];
        int res = 0;
        int unique = 0;
        for(int i = 0; i < n; i++){
            if(count[s.charAt(i) - 'a']++ == 0){
                unique++;
            }
            if(i >= minSize && count[s.charAt(i - minSize) - 'a']-- == 1){
                unique--;
            }
            if(i >= minSize - 1 && unique <= maxLetters){
                res = Math.max(res, count(s, s.substring(i - minSize + 1, i + 1), minSize));
            }
        }
        return res;
        
        
    }
}

    