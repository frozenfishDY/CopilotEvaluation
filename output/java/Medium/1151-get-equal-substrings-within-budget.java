/**https://leetcode.com/problems/get-equal-substrings-within-budget/ */
//You are given two strings s and t of the same length and an integer maxCost.
//You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).
//Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.
// 
//Example 1:
//Input: s = "abcd", t = "bcdf", maxCost = 3
//Output: 3
//Explanation: "abc" of s can change to "bcd".
//That costs 3, so the maximum length is 3.
//Example 2:
//Input: s = "abcd", t = "cdef", maxCost = 3
//Output: 1
//Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
//Example 3:
//Input: s = "abcd", t = "acde", maxCost = 0
//Output: 1
//Explanation: You cannot make any change, so the maximum length is 1.
// 
//Constraints:
//	1 <= s.length <= 105
//	t.length == s.length
//	0 <= maxCost <= 106
//	s and t consist of only lowercase English letters.
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        // 1. create a list to store the cost
		// 2. loop through the strings
		// 2.1 calculate the cost
		// 2.2 add the cost to the list
		// 3. loop through the list
		// 3.1 if the current cost is greater than the max cost, remove the first element in the list
		// 3.2 if the current cost is less than or equal to the max cost, update the max length
		// 4. return the max length
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < s.length(); i++) {
            int cost = Math.abs(s.charAt(i)-t.charAt(i));
            list.add(cost);
        }
        int maxLength = 0;
        int sum = 0;
        for(int i = 0; i < list.size(); i++) {
            sum += list.get(i);
            if(sum > maxCost) {
                sum -= list.get(0);
                list.remove(0);
            }
            else {
                maxLength = Math.max(maxLength, list.size());
            }
        }
        return maxLength;
    }
}