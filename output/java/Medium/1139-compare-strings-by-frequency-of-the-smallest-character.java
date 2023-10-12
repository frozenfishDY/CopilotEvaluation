/**https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/ */
//Let the function f(s) be the frequency of the lexicographically smallest character in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the lexicographically smallest character is 'c', which has a frequency of 2.
//You are given an array of strings words and another array of query strings queries. For each query queries[i], count the number of words in words such that f(queries[i]) < f(W) for each W in words.
//Return an integer array answer, where each answer[i] is the answer to the ith query.
// 
//Example 1:
//Input: queries = ["cbd"], words = ["zaaaz"]
//Output: [1]
//Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").
//Example 2:
//Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
//Output: [1,2]
//Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
// 
//Constraints:
//	1 <= queries.length <= 2000
//	1 <= words.length <= 2000
//	1 <= queries[i].length, words[i].length <= 10
//	queries[i][j], words[i][j] consist of lowercase English letters.
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        // 1. create an array to store the answer
		// 2. create an array to store the frequency of the smallest character in the words
		// 3. loop through the words
		// 3.1 count the frequency of the smallest character
		// 3.2 update the frequency array
		// 4. sort the frequency array
		// 5. loop through the queries
		// 5.1 count the frequency of the smallest character
		// 5.2 find the first index in the frequency array that the frequency is greater than the current frequency
		// 5.3 update the answer array
		// 6. return the answer array
        int[] ans = new int[queries.length];
        int[] frequency = new int[words.length];
        for(int i = 0; i < words.length; i++) {
            frequency[i] = countFrequency(words[i]);
        }
        Arrays.sort(frequency);
        for(int i = 0; i < queries.length; i++) {
            int count = countFrequency(queries[i]);
            ans[i] = findIndex(frequency, count);
        }
        return ans;
    }
    private int countFrequency(String s) {
        int[] count = new int[26];
        for(char c: s.toCharArray()) {
            count[c-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                return count[i];
            }
        }
        return 0;
    }
    private int findIndex(int[] frequency, int count) {
        int left = 0, right = frequency.length-1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(frequency[mid] <= count) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return frequency.length-left;
    }
}