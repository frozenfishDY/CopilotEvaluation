/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".


class LongestDuplicateSubstring {
    public String longestDupSubstring(String s) {
        int left = 1;
        int right = s.length() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (search(s, mid) != -1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int start = search(s, right);
        return start != -1 ? s.substring(start, start + right) : "";
        
        
    }
}
     
    