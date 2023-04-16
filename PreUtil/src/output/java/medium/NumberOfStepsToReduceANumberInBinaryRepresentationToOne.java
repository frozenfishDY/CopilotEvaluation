/**https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/ */
//Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
//If the current number is even, you have to divide it by 2.
//If the current number is odd, you have to add 1 to it.
//It is guaranteed that you can always reach one for all test cases.


class NumberOfStepsToReduceANumberInBinaryRepresentationToOne {
    public int numSteps(String s) {
        int count = 0;
        int carry = 0;
        for(int i = s.length() - 1; i > 0; i--){
            if(s.charAt(i) == '0'){
                if(carry == 1){
                    count += 2;
                }else{
                    count++;
                }
            }else{
                if(carry == 1){
                    count++;
                }else{
                    count += 2;
                    carry = 1;
                }
            }
        }
        return count + carry;
        
    }
}

    