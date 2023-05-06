/**https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/ */
//You are given a string s (0-indexed) you are asked to perform the following operation on s until you get a sorted string:
//Find the largest index i such that 1 <= i < s.length and s[i] < s[i - 1].
//Find the largest index j such that i <= j < s.length and s[k] < s[i - 1] for all the possible values of k in the range [i, j] inclusive.
//Swap the two characters at indices i - 1 and j.
//Reverse the suffix starting at index i.
//Return the number of operations needed to make the string sorted. Since the answer can be too large, return it modulo 10^9 + 7.


class MinimumNumberOfOperationsToMakeStringSorted {
    public int makeStringSorted(String s) {
        int n = s.length();
        int[] fact = new int[n + 1];
        fact[0] = 1;
        for(int i = 1; i <= n; i++){
            fact[i] = (int)((long)fact[i - 1] * i % 1000000007);
        }
        int[] count = new int[26];
        int res = 0;
        for(int i = n - 1; i >= 0; i--){
            int c = s.charAt(i) - 'a';
            for(int j = 0; j < c; j++){
                res = (res + count[j]) % 1000000007;
            }
            count[c]++;
        }
        for(int i = 0; i < n; i++){
            int c = s.charAt(i) - 'a';
            res = (int)((long)res * fact[n - i - 1] % 1000000007);
            for(int j = 0; j < c; j++){
                count[j]--;
            }
        }
        return res;
        
    }
}
     
    