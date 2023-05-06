/**https://leetcode.com/problems/detect-capital/ */
//We define the usage of capitals in a word to be right when one of the following cases holds:
//All letters in this word are capitals, like "USA".
//All letters in this word are not capitals, like "leetcode".
//Only the first letter in this word is capital, like "Google".
//Given a string word, return true if the usage of capitals in it is right.


class DetectCapital {
    public boolean detectCapitalUse(String word) {
        if(word.length() == 1) return true;
        boolean flag = false;
        if(word.charAt(0) >= 'A' && word.charAt(0) <= 'Z'){
            flag = true;
        }
        if(flag){
            if(word.charAt(1) >= 'A' && word.charAt(1) <= 'Z'){
                for(int i = 2; i < word.length(); i++){
                    if(word.charAt(i) >= 'a' && word.charAt(i) <= 'z'){
                        return false;
                    }
                }
            }else{
                for(int i = 2; i < word.length(); i++){
                    if(word.charAt(i) >= 'A' && word.charAt(i) <= 'Z'){
                        return false;
                    }
                }
            }
        }else{
            for(int i = 1; i < word.length(); i++){
                if(word.charAt(i) >= 'A' && word.charAt(i) <= 'Z'){
                    return false;
                }
            }
        }
        return true;
        
        
    }
}

    