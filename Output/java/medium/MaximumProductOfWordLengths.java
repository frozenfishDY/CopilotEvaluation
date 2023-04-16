/**https://leetcode.com/problems/maximum-product-of-word-lengths/ */
//Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.


class MaximumProductOfWordLengths {
    public int maxProduct(String[] words) {
        int[] mask = new int[words.length];
        for(int i = 0; i < words.length; i++){
            for(char c : words[i].toCharArray()){
                mask[i] |= 1 << (c - 'a');
            }
        }
        int res = 0;
        for(int i = 0; i < words.length; i++){
            for(int j = i + 1; j < words.length; j++){
                if((mask[i] & mask[j]) == 0){
                    res = Math.max(res, words[i].length() * words[j].length());
                }
            }
        }
        return res;
        
    }
}

    