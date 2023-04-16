/**https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/ */
//Let's define a function countUniqueChars(s) that returns the number of unique characters on s.
//For example, calling countUniqueChars(s) if s = "LEETCODE" then "L", "T", "C", "O", "D" are the unique characters since they appear only once in s, therefore countUniqueChars(s) = 5.
//Given a string s, return the sum of countUniqueChars(t) where t is a substring of s. The test cases are generated such that the answer fits in a 32-bit integer.
//Notice that some substrings can be repeated so in this case you have to count the repeated ones too.


class CountUniqueCharactersOfAllSubstringsOfAGivenString {
    public int uniqueLetterString(String s) {
        int n = s.length();
        int[] last = new int[26];
        int[] next = new int[26];
        Arrays.fill(last, -1);
        Arrays.fill(next, n);
        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'A';
            last[c] = i;
        }
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int c = s.charAt(i) - 'A';
            next[c] = i;
            int left = i - last[c];
            int right = next[c] - i;
            res += left * right;
            last[c] = i;
        }
        return res;
        
    }
}
     
    