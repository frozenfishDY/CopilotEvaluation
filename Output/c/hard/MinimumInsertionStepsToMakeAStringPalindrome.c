/**https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */
//Given a string s. In one step you can insert any character at any index of the string.
//Return the minimum number of steps to make s palindrome.
//A Palindrome String is one that reads the same backward as well as forward.


int minInsertions(char * s){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*strlen(s));
    for(i=0;i<strlen(s);i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*strlen(s));
    for(i=0;i<strlen(s);i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*strlen(s));
    for(i=0;i<strlen(s);i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*strlen(s));
    for(i=0;i<strlen(s);i++){
        arr4[i] = 0;
    }
    int ans = 0;
    int flag = 0;
    while(flag==0){
        flag = 1;
        for(i=0;i<strlen(s);i++){
            if(arr[i]<strlen(s)){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            break;
        }
        for(i=0;i<strlen(s);i++){
            if(arr[i]<strlen(s)){
                arr[i]++;
                arr2[i]++;
                break;
            }
        }
        for(i=0;i<strlen(s);i++){
            if(arr3[i]<strlen(s)){
                arr3[i]++;
                arr4[i]++;
                break;
            }
        }
        ans++;
    }
    return ans;

}

    