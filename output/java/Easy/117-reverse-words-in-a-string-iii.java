/**https://leetcode.com/problems/reverse-words-in-a-string-iii/ */
//Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.


class ReverseWordsInAStringIii {
    public String reverseWords(String s) {
        String[] arr = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < arr.length; i++){
            sb.append(new StringBuilder(arr[i]).reverse().toString());
            if(i != arr.length - 1) sb.append(" ");
        }
        return sb.toString();
        
    }
}

    