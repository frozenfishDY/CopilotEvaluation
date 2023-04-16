/**https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/ */
//Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.


int findTheLongestSubstring(char * s){
    int length = strlen(s);
    int result = 0;
    int* map = malloc(sizeof(int) * 32);
    memset(map, -1, sizeof(int) * 32);
    map[0] = -1;
    int state = 0;
    for(int i = 0; i < length; i++){
        if(s[i] == 'a'){
            state ^= 1;
        }
        else if(s[i] == 'e'){
            state ^= 2;
        }
        else if(s[i] == 'i'){
            state ^= 4;
        }
        else if(s[i] == 'o'){
            state ^= 8;
        }
        else if(s[i] == 'u'){
            state ^= 16;
        }
        if(map[state] == -1){
            map[state] = i;
        }
        else{
            int temp = i - map[state];
            if(temp > result){
                result = temp;
            }
        }
    }
    return result;

}

    