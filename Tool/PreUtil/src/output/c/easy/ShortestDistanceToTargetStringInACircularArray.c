/**https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/ */
//You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.
//Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
//Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.
//Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.


int closetTarget(char ** words, int wordsSize, char * target, int startIndex){
    int i = 0;
    int j = 0;
    int k = 0;
    int len = strlen(target);
    int min = 0;
    int temp = 0;
    int flag = 0;
    for(i = startIndex; i < wordsSize; i++){
        if(strstr(words[i], target) != NULL){
            min = i - startIndex;
            flag = 1;
            break;
        }
    }
    for(i = startIndex - 1; i >= 0; i--){
        if(strstr(words[i], target) != NULL){
            temp = startIndex - i;
            if(flag == 0){
                min = temp;
                flag = 1;
            }
            else{
                min = min > temp ? temp : min;
            }
            break;
        }
    }
    if(flag == 0){
        return -1;
    }
    else{
        return min;
    }

}

    