/**https://leetcode.com/problems/longest-duplicate-substring/ */
//Given a string s, consider all duplicated substrings: (contiguous) substrings of s that occur 2 or more times. The occurrences may overlap.
//Return any duplicated substring that has the longest possible length. If s does not have a duplicated substring, the answer is "".


char * longestDupSubstring(char * s){
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
'        }
    }
    arr4[count4] = temp4;
    count4++;
    int* arr5 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr5[i] = 0;
    }
    int count5 = 0;
    int temp5 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr5[count5] = temp5;
            temp5 = 0;
            count5++;
        }
        else{
            temp5 = temp5*10 + (s[i]-'0');
        }
    }
    arr5[count5] = temp5;
    count5++;
    int* arr6 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr6[i] = 0;
    }
    int count6 = 0;
    int temp6 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr6[count6] = temp6;
            temp6 = 0;
            count6++;
        }
        else{
            temp6 = temp6*10 + (s[i]-'0');
        }
    }
    arr6[count6] = temp6;
    count6++;
    int* arr7 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr7[i] = 0;
    }
    int count7 = 0;
    int temp7 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr7[count7] = temp7;
            temp7 = 0;
            count7++;
        }
        else{
            temp7 = temp7*10 + (s[i]-'0');
        }
    }
    arr7[count7] = temp7;
    count7++;
    int* arr8 = (int*)malloc(sizeof(int)*1000);
    for(i=0;i<1000;i++){
        arr8[i] = 0;
    }
    int count8 = 0;
    int temp8 = 0;
    for(i=0;i<strlen(s);i++){
        if(s[i]=='-'){
            arr8[count8] = temp8;
            temp8 = 0;  
            count8++;
            

}

    