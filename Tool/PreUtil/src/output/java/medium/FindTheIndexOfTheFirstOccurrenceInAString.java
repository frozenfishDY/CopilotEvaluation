/**https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ */
//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


class FindTheIndexOfTheFirstOccurrenceInAString {
    public int strStr(String haystack, String needle) {
        if(needle.length() == 0){
            return 0;
        }
        for(int i = 0; i < haystack.length(); i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                int j = 0;
                while(j < needle.length() && i + j < haystack.length() && haystack.charAt(i + j) == needle.charAt(j)){
                    j++;
                }
                if(j == needle.length()){
                    return i;
                }
            }
        }
        return -1;
        
    }
}

    