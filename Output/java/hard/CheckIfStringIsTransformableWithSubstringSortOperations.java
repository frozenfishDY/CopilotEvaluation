/**https://leetcode.com/problems/check-if-string-is-transformable-with-substring-sort-operations/ */
//Given two strings s and t, transform string s into string t using the following operation any number of times:
//Choose a non-empty substring in s and sort it in place so the characters are in ascending order.
//For example, applying the operation on the underlined substring in "14234" results in "12344".
//Return true if it is possible to transform s into t. Otherwise, return false.
//A substring is a contiguous sequence of characters within a string.


class CheckIfStringIsTransformableWithSubstringSortOperations {
    public boolean isTransformable(String s, String t) {
        int n = s.length();
        List<Integer>[] pos = new List[10];
        for(int i = 0; i < 10; i++){
            pos[i] = new ArrayList<>();
        }
        for(int i = 0; i < n; i++){
            int c = s.charAt(i) - '0';
            pos[c].add(i);
        }
        for(int i = 0; i < n; i++){
            int c = t.charAt(i) - '0';
            if(pos[c].isEmpty()){
                return false;
            }
            for(int j = 0; j < c; j++){
                if(!pos[j].isEmpty() && pos[j].get(0) < pos[c].get(0)){
                    return false;
                }
            }
            pos[c].remove(0);
        }
        return true;
        
    }
}
     
    