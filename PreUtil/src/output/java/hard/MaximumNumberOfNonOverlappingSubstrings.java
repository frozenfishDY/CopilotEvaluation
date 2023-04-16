/**https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/ */
//Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
//The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
//A substring that contains a certain character c must also contain all occurrences of c.
//Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
//Notice that you can return the substrings in any order.


class MaximumNumberOfNonOverlappingSubstrings {
    public List<String> maxNumOfSubstrings(String s) {
        int[] left = new int[26];
        int[] right = new int[26];
        Arrays.fill(left, Integer.MAX_VALUE);
        Arrays.fill(right, Integer.MIN_VALUE);
        for(int i = 0; i < s.length(); i++){
            int c = s.charAt(i) - 'a';
            left[c] = Math.min(left[c], i);
            right[c] = Math.max(right[c], i);
        }
        List<int[]> intervals = new ArrayList<>();
        for(int i = 0; i < 26; i++){
            if(left[i] == Integer.MAX_VALUE){
                continue;
            }
            int l = left[i];
            int r = right[i];
            for(int j = l; j <= r; j++){
                int c = s.charAt(j) - 'a';
                l = Math.min(l, left[c]);
                r = Math.max(r, right[c]);
            }
            intervals.add(new int[]{l, r});
        }
        Collections.sort(intervals, (a, b) -> a[0] - b[0]);
        List<String> res = new ArrayList<>();
        int prev = -1;
        for(int[] interval : intervals){
            if(interval[0] > prev){
                res.add(s.substring(interval[0], interval[1] + 1));
                prev = interval[1];
            }
        }
        return res;
        
    }
}
     
    