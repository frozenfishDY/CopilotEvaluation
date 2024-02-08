/**https://leetcode.com/problems/flip-string-to-monotone-increasing/ */
//A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).
//You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.
//Return the minimum number of flips to make s monotone increasing.


int minFlipsMonoIncr(char * s){
    int flip = 0;
    int one = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '1'){
            one++;
        }else{
            flip++;
        }
        if(flip > one){
            flip = one;
        }
    }
    return flip;

}

    