/**https://leetcode.com/problems/custom-sort-string/ */
//You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//Return any permutation of s that satisfies this property.


class CustomSortString {
    public String customSortString(String order, String s) {
        int[] count = new int[26];
        for(char c : s.toCharArray()){
            count[c - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for(char c : order.toCharArray()){
            while(count[c - 'a'] > 0){
                sb.append(c);
                count[c - 'a']--;
            }
        }
        for(int i = 0; i < 26; i++){
            while(count[i] > 0){
                sb.append((char)(i + 'a'));
                count[i]--;
            }
        }
        return sb.toString();
        
    }
}

    