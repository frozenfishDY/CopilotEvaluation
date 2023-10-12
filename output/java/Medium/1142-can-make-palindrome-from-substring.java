/**https://leetcode.com/problems/can-make-palindrome-from-substring/ */
//You are given a string s and array queries where queries[i] = [lefti, righti, ki]. We may rearrange the substring s[lefti...righti] for each query and then choose up to ki of them to replace with any lowercase English letter.
//If the substring is possible to be a palindrome string after the operations above, the result of the query is true. Otherwise, the result is false.
//Return a boolean array answer where answer[i] is the result of the ith query queries[i].
//Note that each letter is counted individually for replacement, so if, for example s[lefti...righti] = "aaa", and ki = 2, we can only replace two of the letters. Also, note that no query modifies the initial string s.
// 
//Example :
//Input: s = "abcda", queries = [[3,3,0],[1,2,0],[0,3,1],[0,3,2],[0,4,1]]
//Output: [true,false,false,true,true]
//Explanation:
//queries[0]: substring = "d", is palidrome.
//queries[1]: substring = "bc", is not palidrome.
//queries[2]: substring = "abcd", is not palidrome after replacing only 1 character.
//queries[3]: substring = "abcd", could be changed to "abba" which is palidrome. Also this can be changed to "baab" first rearrange it "bacd" then replace "cd" with "ab".
//queries[4]: substring = "abcda", could be changed to "abcba" which is palidrome.
//Example 2:
//Input: s = "lyb", queries = [[0,1,0],[2,2,1]]
//Output: [false,true]
// 
//Constraints:
//	1 <= s.length, queries.length <= 105
//	0 <= lefti <= righti < s.length
//	0 <= ki <= s.length
//	s consists of lowercase English letters.
class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        // 1. create a 2d array to store the number of each character
        // 2. loop through the 2d array
        // 2.1 if the number of the current character is odd, increase the count by 1
        // 3. loop through the queries
        // 3.1 find the number of character in the substring
        // 3.2 if the number of character is odd, decrease the count by 1
        // 3.3 if the count is greater than k, set the result to false
        // 4. return the result
        List<Boolean> ans = new ArrayList<>();
        int[][] dp = new int[s.length()+1][26];
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            dp[i+1] = dp[i].clone();
            dp[i+1][c-'a']++;
        }
        for(int[] query: queries) {
            int left = query[0];
            int right = query[1];
            int k = query[2];
            int[] count = new int[26];
            for(int i = 0; i < 26; i++) {
                count[i] = dp[right+1][i] - dp[left][i];
            }
            int odd = 0;
            for(int i = 0; i < 26; i++) {
                if(count[i] % 2 == 1) {
                    odd++;
                }
            }
            ans.add(odd / 2 <= k);
        }
        return ans;
    }
}