/**https://leetcode.com/problems/rearrange-words-in-a-sentence/ */
//Given a sentence text (A sentence is a string of space-separated words) in the following format:
//First letter is in upper case.
//Each word in text are separated by a single space.
//Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.
//Return the new text following the format shown above.


char * arrangeWords(char * text){
    int i, j, k, count = 0, *arr;
    char *str = (char*)malloc(100000 * sizeof(char));
    arr = (int*)malloc(100000 * sizeof(int));
    for(i = 0; i < 100000; i++){
        str[i] = '\0';
        arr[i] = 0;
    }
    for(i = 0; i < strlen(text); i++){
        if(text[i] == ' '){
            arr[count++] = i;
        }
    }
    for(i = 0; i < count; i++){
        for(j = i + 1; j < count; j++){
            if(arr[j] - arr[i] < arr[i + 1] - arr[j]){
                k = arr[i + 1];
                arr[i + 1] = arr[j];
                arr[j] = k;
            }
        }
    }
    for(i = 0; i < count; i++){
        if(i == 0){
            for(j = 0; j < arr[i]; j++){
                str[j] = text[j];
            }
        }
        else{
            for(j = arr[i - 1] + 1; j < arr[i]; j++){
                str[j - arr[i - 1] - 1] = text[j];
            }
        }
    }
    for(i = arr[count - 1] + 1; i < strlen(text); i++){
        str[i - arr[count - 1] - 1] = text[i];
    }
    if(str[0] >= 'a' && str[0] <= 'z'){
        str[0] = str[0] - 32;
    }
    return str;

}

    