/**https://leetcode.com/problems/word-subsets/ */
//You are given two string arrays words1 and words2.
//A string b is a subset of string a if every letter in b occurs in a including multiplicity.
//For example, "wrr" is a subset of "warrior" but is not a subset of "world".
//A string a from words1 is universal if for every string b in words2, b is a subset of a.
//Return an array of all the universal strings in words1. You may return the answer in any order.


class WordSubsets {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] map = new int[26];
        for(String word : words2){
            int[] temp = new int[26];
            for(char c : word.toCharArray()){
                temp[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                map[i] = Math.max(map[i], temp[i]);
            }
        }
        List<String> res = new ArrayList<>();
        for(String word : words1){
            int[] temp = new int[26];
            for(char c : word.toCharArray()){
                temp[c - 'a']++;
            }
            boolean flag = true;
            for(int i = 0; i < 26; i++){
                if(temp[i] < map[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res.add(word);
            }
        }
        return res;
        
    }
}

    