/**https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/ */
//The value of an alphanumeric string can be defined as:
//The numeric representation of the string in base 10, if it comprises of digits only.
//The length of the string, otherwise.
//Given an array strs of alphanumeric strings, return the maximum value of any string in strs.


class MaximumValueOfAStringInAnArray {
    public int maximumValue(String[] strs) {
        int max = 0;
        for(String s : strs){
            int val = 0;
            for(char c : s.toCharArray()){
                if(Character.isDigit(c)){
                    val = val * 10 + (c - '0');
                }else{
                    val++;
                }
            }
            max = Math.max(max, val);
        }
        return max;
        
        
    }
}

    