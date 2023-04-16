/**https://leetcode.com/problems/minimum-number-of-frogs-croaking/ */
//You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
//Return the minimum number of different frogs to finish all the croaks in the given string.
//A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.


int minNumberOfFrogs(char * croakOfFrogs){
    int i, j, k, count = 0, max = 0, maxIndex = 0;
    char *str = (char*)malloc(100000 * sizeof(char));
    int *arr = (int*)malloc(5 * sizeof(int));
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 0;
    arr[3] = 0;
    arr[4] = 0;
    for(i = 0; i < 100000; i++){
        str[i] = '\0';
    }
    for(i = 0; i < strlen(croakOfFrogs); i++){
        if(croakOfFrogs[i] == 'c'){
            arr[0]++;
        }
        else if(croakOfFrogs[i] == 'r'){
            arr[1]++;
        }
        else if(croakOfFrogs[i] == 'o'){
            arr[2]++;
        }
        else if(croakOfFrogs[i] == 'a'){
            arr[3]++;
        }
        else if(croakOfFrogs[i] == 'k'){
            arr[4]++;
        }
        else{
            return -1;
        }
    }
    for(i = 0; i < 5; i++){
        if(arr[i] > max){
            max = arr[i];
            maxIndex = i;
        }
    }
    if(maxIndex == 0){
        for(i = 0; i < max; i++){
            str[count++] = 'c';
        }
        arr[0] = 0;
    }
    else if(maxIndex == 1){
        for(i = 0; i < max; i++){
            str[count++] = 'r';
        }
        arr[1] = 0;
    }
    else if(maxIndex == 2){
        for(i = 0; i < max; i++){
            str[count++] = 'o';
        }
        arr[2] = 0;
    }
    else if(maxIndex == 3){
        for(i = 0; i < max; i++){
            str[count++] = 'a';
        }
        arr[3] = 0;
    }
    else{
        for(i = 0; i < max; i++){
            str[count ++] = 'k';

            

}

    