/**https://leetcode.com/problems/longest-substring-without-repeating-characters/ */
//Given a string s, find the length of the longest substring without repeating characters.


class LongestSubstringWithoutRepeatingCharacters {
    public int lengthOfLongestSubstring(String s) {
        int[] map = new int[128];
        int left = 0;
        int right = 0;
        int max = 0;
        while(right < s.length()){
            char c = s.charAt(right);
            map[c]++;
            while(map[c] > 1){
                map[s.charAt(left)]--;
                left++;
            }
            max = Math.max(max, right - left + 1);
            right++;
        }
        return max;
        
    }
}

    