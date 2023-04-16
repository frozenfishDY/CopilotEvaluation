/**https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/ */
//Given an array of integers cost and an integer target, return the maximum integer you can paint under the following rules:
//The cost of painting a digit (i + 1) is given by cost[i] (0-indexed).
//The total cost used must be equal to target.
//The integer does not have 0 digits.
//Since the answer may be very large, return it as a string. If there is no way to paint any integer given the condition, return "0".


char * largestNumber(int* cost, int costSize, int target){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*target);
    for(i=0;i<target;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*target);
    for(i=0;i<target;i++){
        arr2[i] = 0;
    }
    for(i=0;i<target;i++){
        for(j=0;j<costSize;j++){
            if(i+1==cost[j]){
                arr[i] = j+1;
            }
        }
    }
    for(i=0;i<target;i++){
        for(j=0;j<costSize;j++){
            if(i+1>cost[j]){
                if(arr[i]<arr[i-cost[j]]+j+1){
                    arr[i] = arr[i-cost[j]]+j+1;
                }
            }
        }
    }
    if(arr[target-1]==0){
        return "0";
    }
    char* str = (char*)malloc(sizeof(char)*arr[target-1]);
    for(i=0;i<arr[target-1];i++){
        str[i] = '0';
    }
    int num = target;
    for(i=arr[target-1]-1;i>=0;i--){
        for(j=costSize-1;j>=0;j--){
            if(num>=cost[j]){
                if(arr[num-1]==arr[num-cost[j]-1]+j+1){
                    str[i] = j+1+'0';
                    num = num-cost[j];
                    break;
                }
            }
        }
    }
    return str;

}

    