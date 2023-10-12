/**https://leetcode.com/problems/smallest-string-with-swaps/ */
//You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
//You can swap the characters at any pair of indices in the given pairs any number of times.
//Return the lexicographically smallest string that s can be changed to after using the swaps.
// 
//Example 1:
//Input: s = "dcab", pairs = [[0,3],[1,2]]
//Output: "bacd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[1] and s[2], s = "bacd"
//Example 2:
//Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
//Output: "abcd"
//Explaination: 
//Swap s[0] and s[3], s = "bcad"
//Swap s[0] and s[2], s = "acbd"
//Swap s[1] and s[2], s = "abcd"
//Example 3:
//Input: s = "cba", pairs = [[0,1],[1,2]]
//Output: "abc"
//Explaination: 
//Swap s[0] and s[1], s = "bca"
//Swap s[1] and s[2], s = "bac"
//Swap s[0] and s[1], s = "abc"
// 
//Constraints:
//	1 <= s.length <= 10^5
//	0 <= pairs.length <= 10^5
//	0 <= pairs[i][0], pairs[i][1] < s.length
//	s only contains lower case English letters.
class Solution {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        // 1. create a map to store the index list of each char
		// 2. create a visited array to store the visited index
		// 3. create a dfs function to recursively swap the chars
		// 3.1 if the current index is visited, return
		// 3.2 mark the current index as visited
		// 3.3 add the current index to the list
		// 3.4 recursively call the dfs function for the next index
		// 4. create a list to store the index list of each char
		// 5. create a char array to store the chars
		// 6. sort the index list of each char
		// 7. sort the chars
		// 8. loop through the index list of each char
		// 8.1 get the index of the char
		// 8.2 get the char from the char array
		// 8.3 add the char to the string
		// 9. return the string
        Map<Character, List<Integer>> map = new HashMap<>();
        boolean[] visited = new boolean[s.length()];
        for(List<Integer> pair: pairs) {
            int i = pair.get(0);
            int j = pair.get(1);
            map.putIfAbsent(s.charAt(i), new ArrayList<>());
            map.get(s.charAt(i)).add(j);
            map.putIfAbsent(s.charAt(j), new ArrayList<>());
            map.get(s.charAt(j)).add(i);
        }
        List<List<Integer>> list = new ArrayList<>();
        char[] chars = s.toCharArray();
        for(char c: map.keySet()) {
            List<Integer> indexList = map.get(c);
            Collections.sort(indexList);
            list.add(indexList);
        }
        Arrays.sort(chars);
        StringBuilder sb = new StringBuilder();
        for(List<Integer> indexList: list) {
            for(int index: indexList) {
                sb.append(chars[index]);
            }
        }
        return sb.toString();
    }
}