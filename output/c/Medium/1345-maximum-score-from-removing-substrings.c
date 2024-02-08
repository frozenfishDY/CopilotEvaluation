/**https://leetcode.com/problems/maximum-score-from-removing-substrings/ */
//You are given a string s and two integers x and y. You can perform two types of operations any number of times.
//Remove substring "ab" and gain x points.
//For example, when removing "ab" from "cabxbae" it becomes "cxbae".
//Remove substring "ba" and gain y points.
//For example, when removing "ba" from "cabxbae" it becomes "cabxe".
//Return the maximum points you can gain after applying the above operations on s.


int maximumGain(char * s, int x, int y){
    int len = strlen(s);
    int count = 0;
    int a = 0;
    int b = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == 'a'){
            a++;
        }else if(s[i] == 'b'){
            b++;
        }else{
            if(a > 0 && b > 0){
                if(x > y){
                    count += x;
                    a--;
                    b--;
                }else{
                    count += y;
                    a--;
                    b--;
                }
            }
        }
    }
    return count;

}

    