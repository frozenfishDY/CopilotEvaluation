/**https://leetcode.com/problems/print-words-vertically/ */
//Given a string s. Return all the words vertically in the same order in which they appear in s.
//Words are returned as a list of strings, complete with spaces when is necessary. (Trailing spaces are not allowed).
//Each word would be put on only one column and that in one column there will be only one word.


class PrintWordsVertically {
    public List<String> printVertically(String s) {
        String[] words = s.split(" ");
        int max = 0;
        for(String word : words){
            max = Math.max(max, word.length());
        }
        List<String> res = new ArrayList<>();
        for(int i = 0; i < max; i++){
            StringBuilder sb = new StringBuilder();
            for(String word : words){
                if(i < word.length()){
                    sb.append(word.charAt(i));
                }else{
                    sb.append(" ");
                }
            }
            while(sb.charAt(sb.length() - 1) == ' '){
                sb.deleteCharAt(sb.length() - 1);
            }
            res.add(sb.toString());
        }
        return res;
        
        
    }
}

    