/**https://leetcode.com/problems/number-of-segments-in-a-string/ */
//Given a string s, return the number of segments in the string.
//A segment is defined to be a contiguous sequence of non-space characters.


class NumberOfSegmentsInAString {
    public int countSegments(String s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) != ' ' && (i == 0 || s.charAt(i - 1) == ' ')){
                count++;
            }
        }
        return count;
        
    }
}

    