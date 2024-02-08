/**https://leetcode.com/problems/sort-characters-by-frequency/ */
//Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
//Return the sorted string. If there are multiple answers, return any of them.


class SortCharactersByFrequency {
    public String frequencySort(String s) {
        int n = s.length();
        int[] cnt = new int[256];
        for(int i = 0; i < n; i++){
            cnt[s.charAt(i)]++;
        }
        List<Character>[] bucket = new List[n + 1];
        for(int i = 0; i < 256; i++){
            if(cnt[i] > 0){
                if(bucket[cnt[i]] == null){
                    bucket[cnt[i]] = new ArrayList<>();
                }
                bucket[cnt[i]].add((char)i);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = n; i >= 0; i--){
            if(bucket[i] != null){
                for(char c : bucket[i]){
                    for(int j = 0; j < i; j++){
                        sb.append(c);
                    }
                }
            }
        }
        return sb.toString();
        
        
    }
}

    