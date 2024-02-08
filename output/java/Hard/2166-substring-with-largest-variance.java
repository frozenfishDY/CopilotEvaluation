/**https://leetcode.com/problems/substring-with-largest-variance/ */
//The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.
//Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.
//A substring is a contiguous sequence of characters within a string.


class SubstringWithLargestVariance {
    public int largestVariance(String s) {
        int n = s.length();
        int res = 0;
        int[] dp = new int[26];
        for (int i = 0; i < n; i++) {
            int[] temp = new int[26];
            for (int j = i; j < n; j++) {
                temp[s.charAt(j) - 'a']++;
                int max = 0;
                int min = n;
                for (int k = 0; k < 26; k++) {
                    if (temp[k] > 0) {
                        max = Math.max(max, temp[k]);
                        min = Math.min(min, temp[k]);
                    }
                }
                res = Math.max(res, max - min);
            }
        }
        return res;
        
    }
}
     
    