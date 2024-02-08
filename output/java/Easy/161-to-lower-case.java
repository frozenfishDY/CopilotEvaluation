/**https://leetcode.com/problems/to-lower-case/ */
//Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.


class ToLowerCase {
    public String toLowerCase(String s) {
        StringBuilder sb = new StringBuilder();
        for(char c : s.toCharArray()){
            if(c >= 'A' && c <= 'Z'){
                sb.append((char)(c + 32));
            }else{
                sb.append(c);
            }
        }
        return sb.toString();
        
    }
}

    