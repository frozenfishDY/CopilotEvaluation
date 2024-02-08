/**https://leetcode.com/problems/base-7/ */
//Given an integer num, return a string of its base 7 representation.


class Base7 {
    public String convertToBase7(int num) {
        if(num == 0) return "0";
        StringBuilder sb = new StringBuilder();
        boolean flag = false;
        if(num < 0){
            flag = true;
            num = -num;
        }
        while(num > 0){
            sb.append(num % 7);
            num /= 7;
        }
        if(flag) sb.append("-");
        return sb.reverse().toString();
        
    }
}

    