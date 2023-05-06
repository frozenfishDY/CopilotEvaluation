/**https://leetcode.com/problems/longest-happy-prefix/ */
//A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
//Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.


char * longestPrefix(char * s){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr[i] = 0;
    }
    int count = 0;
    int temp = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr[count] = temp;
            temp = 0;
            count++;
        }
        else{
            temp = temp*10 + (s[i]-'0');
        }
    }
    arr[count] = temp;
    count++;
    int* arr2 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr2[i] = 0;
    }
    int count2 = 0;
    int temp2 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr2[count2] = temp2;
            temp2 = 0;
            count2++;
        }
        else{
            temp2 = temp2*10 + (s[i]-'0');
        }
    }
    arr2[count2] = temp2;
    count2++;
    int* arr3 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr3[i] = 0;
    }
    int count3 = 0;
    int temp3 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr3[count3] = temp3;
            temp3 = 0;
            count3++;
        }
        else{
            temp3 = temp3*10 + (s[i]-'0');
        }
    }
    arr3[count3] = temp3;
    count3++;
    int* arr4 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr4[i] = 0;
    }
    int count4 = 0;
    int temp4 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr4[count4] = temp4;
            temp4 = 0;
            count4++;
        }
        else{
            temp4 = temp4*10 + (s[i]-'0

}

    