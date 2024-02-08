/**https://leetcode.com/problems/string-without-aaa-or-bbb/ */
//Given two integers a and b, return any string s such that:
//s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//The substring 'aaa' does not occur in s, and
//The substring 'bbb' does not occur in s.


class StringWithoutAaaOrBbb {
    public String strWithout3a3b(int a, int b) {
        StringBuilder sb = new StringBuilder();
        while(a > 0 || b > 0){
            boolean writeA = false;
            int l = sb.length();
            if(l >= 2 && sb.charAt(l - 1) == sb.charAt(l - 2)){
                if(sb.charAt(l - 1) == 'b'){
                    writeA = true;
                }
            }else{
                if(a >= b){
                    writeA = true;
                }
            }
            if(writeA){
                sb.append('a');
                a--;
            }else{
                sb.append('b');
                b--;
            }
        }
        return sb.toString();
        
        
    }
}

    