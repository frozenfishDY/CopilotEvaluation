/**https://leetcode.com/problems/repeated-string-match/ */
//Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b to be a substring of a after repeating it, return -1.
//Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".


class RepeatedStringMatch {
    public int repeatedStringMatch(String a, String b) {
        int n = a.length();
        int m = b.length();
        int cnt = 0;
        StringBuilder sb = new StringBuilder();
        while(sb.length() < m){
            sb.append(a);
            cnt++;
        }
        if(sb.indexOf(b) != -1){
            return cnt;
        }
        if(sb.append(a).indexOf(b) != -1){
            return cnt + 1;
        }
        return -1;
        
        
    }
}

    