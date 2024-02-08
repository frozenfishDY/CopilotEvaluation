/**https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ */
//Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of all these characters a, b and c.


int numberOfSubstrings(char * s){
    int length = strlen(s);
    int count = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int start = 0;
    for(int i = 0; i < length; i++){
        if(s[i] == 'a'){
            a++;
        }
        else if(s[i] == 'b'){
            b++;
        }
        else{
            c++;
        }
        while(a > 0 && b > 0 && c > 0){
            if(s[start] == 'a'){
                a--;
            }
            else if(s[start] == 'b'){
                b--;
            }
            else{
                c--;
            }
            start++;
        }
        count += start;
    }
    return count;

}

    