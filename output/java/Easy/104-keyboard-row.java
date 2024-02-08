/**https://leetcode.com/problems/keyboard-row/ */
//Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
//In the American keyboard:
//the first row consists of the characters "qwertyuiop",
//the second row consists of the characters "asdfghjkl", and
//the third row consists of the characters "zxcvbnm".


class KeyboardRow {
    public String[] findWords(String[] words) {
        String[] rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        List<String> ans = new ArrayList<>();
        for(String word : words){
            int row = 0;
            for(int i = 0; i < rows.length; i++){
                if(rows[i].indexOf(Character.toLowerCase(word.charAt(0))) != -1){
                    row = i;
                    break;
                }
            }
            boolean flag = true;
            for(int i = 1; i < word.length(); i++){
                if(rows[row].indexOf(Character.toLowerCase(word.charAt(i))) == -1){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.add(word);
            }
        }
        return ans.toArray(new String[ans.size()]);
        
        
    }
}

    