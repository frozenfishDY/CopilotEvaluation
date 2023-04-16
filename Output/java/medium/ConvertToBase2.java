/**https://leetcode.com/problems/convert-to-base-2/ */
//Given an integer n, return a binary string representing its representation in base -2.
//Note that the returned string should not have leading zeros unless the string is "0".


class ConvertToBase2 {
    public String baseNeg2(int n) {
        if(n == 0){
            return "0";
        }
        StringBuilder sb = new StringBuilder();
        while(n != 0){
            sb.append(n & 1);
            n = -(n >> 1);
        }
        return sb.reverse().toString();
        
    }
}

    