/**https://leetcode.com/problems/find-all-good-strings/ */
//Given the strings s1 and s2 of size n and the string evil, return the number of good strings.
//A good string has size n, it is alphabetically greater than or equal to s1, it is alphabetically smaller than or equal to s2, and it does not contain the string evil as a substring. Since the answer can be a huge number, return this modulo 10^9 + 7.


int findGoodStrings(int n, char * s1, char * s2, char * evil){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    int count = 0;
    int temp = 0;
    for(i=0;i<strlen(s1);i++){
        if(s1[i]=='-'){
            arr[count] = temp;
            temp = 0;
            count++;
        }
        else{
            temp = temp*10 + (s1[i]-'0');
        }
    }
    arr[count] = temp;
    count++;
    int* arr2 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr2[i] = 0;
    }
    int count2 = 0;
    int temp2 = 0;
    for(i=0;i<strlen(s2);i++){
        if(s2[i]=='-'){
            arr2[count2] = temp2;
            temp2 = 0;
            count2++;
        }
        else{
            temp2 = temp2*10 + (s2[i]-'0');
        }
    }
    arr2[count2] = temp2;
    count2++;
    int* arr3 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr3[i] = 0;
    }
    int count3 = 0;
    int temp3 = 0;
    for(i=0;i<strlen(evil);i++){
        if(evil[i]=='-'){
            arr3[count3] = temp3;
            temp3 = 0;
            count3++;
        }
        else{
            temp3 = temp3*10 + (evil[i]-'0');
        }
    }
    arr3[count3] = temp3;
    count3++;
    int* arr4 = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr4[i] = 0;
    }
    int count4 = 0;
    int temp4 = 0;
    for(i=0;i<strlen(evil);i++){
        if(evil[i]=='-'){
            arr4[count4] = temp4;
            temp4 = 0;
            count4++;
        }
        else{
            temp4 = temp4*10 + (evil[i]-'0');

}

    