/**https://leetcode.com/problems/string-without-aaa-or-bbb/ */
//Given two integers a and b, return any string s such that:
//s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
//The substring 'aaa' does not occur in s, and
//The substring 'bbb' does not occur in s.


char * strWithout3a3b(int a, int b){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = a + b;
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    for(i = 0; i < len; i++){
        if(a > b){
            if(i > 1 && result[i - 1] == 'a' && result[i - 2] == 'a'){
                result[i] = 'b';
                b--;
            }
            else{
                result[i] = 'a';
                a--;
            }
        }
        else if(a < b){
            if(i > 1 && result[i - 1] == 'b' && result[i - 2] == 'b'){
                result[i] = 'a';
                a--;
            }
            else{
                result[i] = 'b';
                b--;
            }
        }
        else{
            if(i > 1 && result[i - 1] == 'a' && result[i - 2] == 'a'){
                result[i] = 'b';
                b--;
            }
            else{
                result[i] = 'a';
                a--;
            }
        }
    }
    result[i] = '\0';
    return result;

}

    