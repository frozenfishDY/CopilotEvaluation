/**https://leetcode.com/problems/reorder-data-in-log-files/ */
//You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
//There are two types of logs:
//Letter-logs: All words (except the identifier) consist of lowercase English letters.
//Digit-logs: All words (except the identifier) consist of digits.
//Reorder these logs so that:
//The letter-logs come before all digit-logs.
//The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
//The digit-logs maintain their relative ordering.
//Return the final order of the logs.


class ReorderDataInLogFiles {
    public String[] reorderLogFiles(String[] logs) {
        Arrays.sort(logs, (a, b) -> {
            String[] s1 = a.split(" ", 2);
            String[] s2 = b.split(" ", 2);
            boolean isDigit1 = Character.isDigit(s1[1].charAt(0));
            boolean isDigit2 = Character.isDigit(s2[1].charAt(0));
            if(!isDigit1 && !isDigit2){
                int cmp = s1[1].compareTo(s2[1]);
                if(cmp != 0){
                    return cmp;
                }
                return s1[0].compareTo(s2[0]);
            }
            return isDigit1 ? (isDigit2 ? 0 : 1) : -1;
        });
        return logs;
        
    }
}

    