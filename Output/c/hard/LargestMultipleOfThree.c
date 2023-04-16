/**https://leetcode.com/problems/largest-multiple-of-three/ */
//Given an array of digits digits, return the largest multiple of three that can be formed by concatenating some of the given digits in any order. If there is no answer return an empty string.
//Since the answer may not fit in an integer data type, return the answer as a string. Note that the returning answer must not contain unnecessary leading zeros.


char * largestMultipleOfThree(int* digits, int digitsSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*digitsSize);
    for(i=0;i<digitsSize;i++){
        arr[i] = digits[i];
    }
    int sum = 0;
    for(i=0;i<digitsSize;i++){
        sum += arr[i];
    }
    if(sum%3==0){
        return "0";
    }
    int* arr2 = (int*)malloc(sizeof(int)*digitsSize);
    for(i=0;i<digitsSize;i++){
        arr2[i] = 0;
    }
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    for(i=0;i<digitsSize;i++){
        if(arr[i]%3==1){
            count++;
        }
        else if(arr[i]%3==2){
            count2++;
        }
        else{
            count3++;
        }
    }
    if(sum%3==1){
        if(count>0){
            for(i=0;i<digitsSize;i++){
                if(arr[i]%3==1){
                    arr2[i] = 1;
                    break;
                }
            }
        }
        else{
            for(i=0;i<digitsSize;i++){
                if(arr[i]%3==2){
                    arr2[i] = 1;
                    count2--;
                    if(count2==0){
                        break;
                    }
                }
            }
        }
    }
    else{
        if(count2>0){
            for(i=0;i<digitsSize;i++){
                if(arr[i]%3==2){
                    arr2[i] = 1;
                    break;
                }
            }
        }
        else{
            for(i=0;i<digitsSize;i++){
                if(arr[i]%3==1){
                    arr2[i] = 1;
                    count--;
                    if(count==0){
                        break;
                    }
                }
            }
        }
    }
    int* arr3 = (int*)malloc(sizeof(int)*digitsSize);
    for(i=0;i<digitsSize;i++){
        arr3[i] = 0;
    }
    int count4 = 0;
    for(i=0;i<digitsSize;i++){
        if(arr2[i]==0){
            arr3[count4] = arr[i];
            count4++;
        }
    }
    int* arr4 = (int*)malloc

}

    