/**https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/ */
//Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
//If the current number is even, you have to divide it by 2.
//If the current number is odd, you have to add 1 to it.
//It is guaranteed that you can always reach one for all test cases.


int numSteps(char * s){
    int i, j, count = 0;
    for(i = strlen(s) - 1; i > 0; i--){
        if(s[i] == '0'){
            count++;
        }
        else{
            count++;
            for(j = i - 1; j >= 0; j--){
                if(s[j] == '0'){
                    s[j] = '1';
                    break;
                }
                else{
                    s[j] = '0';
                }
            }
        }
    }
    return count;

}

    