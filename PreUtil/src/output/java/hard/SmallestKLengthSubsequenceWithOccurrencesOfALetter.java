/**https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter/ */
//You are given a string s, an integer k, a letter letter, and an integer repetition.
//Return the lexicographically smallest subsequence of s of length k that has the letter letter appear at least repetition times. The test cases are generated so that the letter appears in s at least repetition times.
//A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b.


class SmallestKLengthSubsequenceWithOccurrencesOfALetter {
    public String smallestSubsequence(String s, int k, char letter, int repetition) {
        int n = s.length();
        int[] count = new int[26];
        for(int i = 0; i < n; i++){
            count[s.charAt(i) - 'a']++;
        }
        int[] dp = new int[n + 1];
        for(int i = 1; i <= n; i++){
            if(s.charAt(i - 1) == letter){
                dp[i] = dp[i - 1] + 1;
            }else{
                dp[i] = dp[i - 1];
            }
        }
        int len = dp[n];
        char[] res = new char[len];
        int i = n, j = n;
        while(i > 0 && j > 0){
            if(s.charAt(i - 1) == letter){
                res[len - 1] = s.charAt(i - 1);
                i--;
                j--;
                len--;
            }else if(dp[i - 1] > dp[j - 1]){
                i--;
            }else{
                j--;
            }
        }
        String str = new String(res);
        int count = 0;
        for(i = 0; i < n; i++){
            if(s.startsWith(str, i)){
                count++;
            }
        }
        return count == k ? str : "";
        
    }
}
     
    