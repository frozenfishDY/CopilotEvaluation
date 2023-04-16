/**https://leetcode.com/problems/unique-substrings-in-wraparound-string/ */
//We define the string base to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so base will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//Given a string s, return the number of unique non-empty substrings of s are present in base.


class UniqueSubstringsInWraparoundString {
    public int findSubstringInWraproundString(String s) {
        int n = s.length();
        int[] cnt = new int[26];
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            if(i > 0 && (s.charAt(i) - s.charAt(i - 1) == 1 || s.charAt(i - 1) - s.charAt(i) == 25)){
                maxLen++;
            }else{
                maxLen = 1;
            }
            int index = s.charAt(i) - 'a';
            cnt[index] = Math.max(cnt[index], maxLen);
        }
        int res = 0;
        for(int i = 0; i < 26; i++){
            res += cnt[i];
        }
        return res;
        
        
    }
}

    