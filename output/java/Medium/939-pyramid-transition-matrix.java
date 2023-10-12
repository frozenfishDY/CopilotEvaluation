/**https://leetcode.com/problems/pyramid-transition-matrix/ */
//You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.
//To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.
//	For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
//You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.
//Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.
// 
//Example 1:
//Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
//Output: true
//Explanation: The allowed triangular patterns are shown on the right.
//Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
//There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
//Example 2:
//Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
//Output: false
//Explanation: The allowed triangular patterns are shown on the right.
//Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
// 
//Constraints:
//	2 <= bottom.length <= 6
//	0 <= allowed.length <= 216
//	allowed[i].length == 3
//	The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
//	All the values of allowed are unique.
class Solution {
    public boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, Set<Character>> map = new HashMap<>();
        for(String s: allowed) {
            String key = s.substring(0, 2);
            map.putIfAbsent(key, new HashSet<>());
            map.get(key).add(s.charAt(2));
        }
        return dfs(bottom, map);
    }
    private boolean dfs(String bottom, Map<String, Set<Character>> map) {
        if(bottom.length() == 1) {
            return true;
        }
        for(int i=0; i<bottom.length()-1; i++) {
            String key = bottom.substring(i, i+2);
            if(!map.containsKey(key)) {
                return false;
            }
        }
        List<String> nexts = getNexts(bottom, map);
        for(String next: nexts) {
            if(dfs(next, map)) {
                return true;
            }
        }
        return false;
    }
    private List<String> getNexts(String bottom, Map<String, Set<Character>> map) {
        List<String> nexts = new ArrayList<>();
        getNexts(bottom, 0, "", nexts, map);
        return nexts;
    }
    private void getNexts(String bottom, int index, String next, List<String> nexts, Map<String, Set<Character>> map) {
        if(index == bottom.length() - 1) {
            nexts.add(next);
            return;
        }
        String key = bottom.substring(index, index+2);
        for(char c: map.get(key)) {
            next += c;
            getNexts(bottom, index+1, next, nexts, map);
            next = next.substring(0, next.length()-1);
        }
    }
}
    
