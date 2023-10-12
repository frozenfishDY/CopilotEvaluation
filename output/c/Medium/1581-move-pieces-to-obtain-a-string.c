/**https://leetcode.com/problems/move-pieces-to-obtain-a-string/ */
//You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:
//	The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
//	The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
//Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
// 
//Example 1:
//Input: start = "_L__R__R_", target = "L______RR"
//Output: true
//Explanation: We can obtain the string target from start by doing the following moves:
//- Move the first piece one step to the left, start becomes equal to "L___R__R_".
//- Move the last piece one step to the right, start becomes equal to "L___R___R".
//- Move the second piece three steps to the right, start becomes equal to "L______RR".
//Since it is possible to get the string target from start, we return true.
//Example 2:
//Input: start = "R_L_", target = "__LR"
//Output: false
//Explanation: The 'R' piece in the string start can move one step to the right to obtain "_RL_".
//After that, no pieces can move anymore, so it is impossible to obtain the string target from start.
//Example 3:
//Input: start = "_R", target = "R_"
//Output: false
//Explanation: The piece in the string start can move only to the right, so it is impossible to obtain the string target from start.
// 
//Constraints:
//	n == start.length == target.length
//	1 <= n <= 105
//	start and target consist of the characters 'L', 'R', and '_'.
bool canChange(char * start, char * target){
int i;
    int j;
    int k;
    int count;
    int left;
    int right;
    int prev;
    int next;
    int len=strlen(start);
    int* arr = malloc(sizeof(int)*len);
    int* arr2 = malloc(sizeof(int)*len);
    int* arr3 = malloc(sizeof(int)*len);
    int* arr4 = malloc(sizeof(int)*len);
    int* ret = malloc(sizeof(int)*2);
    for(i=0;i<len;i++){
        if(start[i]=='L'){
            arr[i]=1;
        }else if(start[i]=='R'){
            arr[i]=2;
        }else{
            arr[i]=0;
        }
    }
    for(i=0;i<len;i++){
        if(target[i]=='L'){
            arr2[i]=1;
        }else if(target[i]=='R'){
            arr2[i]=2;
        }else{
            arr2[i]=0;
        }
    }
    for(i=0;i<len;i++){
        if(start[i]=='L' || start[i]=='R'){
            arr3[i]=1;
        }else{
            arr3[i]=0;
        }
    }
    for(i=0;i<len;i++){
        if(target[i]=='L' || target[i]=='R'){
            arr4[i]=1;
        }else{
            arr4[i]=0;
        }
    }
    for(i=0;i<len;i++){
        if(arr[i]==1){
            for(j=i-1;j>=0;j--){
                if(arr[j]==0){
                    arr[j]=1;
                    arr[i]=0;
                    break;
                }else if(arr[j]==1){
                    break;
                }
            }
        }else if(arr[i]==2){
            for(j=i+1;j<len;j++){
                if(arr[j]==0){
                    arr[j]=2;
                    arr[i]=0;
                    break;
                }else if(arr[j]==2){
                    break;
                }
            }
        }
    }
    for(i=0;i<len;i++){
        if(arr2[i]==1){
            for(j=i-1;j>=0;j--){
                if(arr2[j]==0){
                    arr2[j]=1;
                    arr2[i]=0;
                    break;
                }else if(arr2[j]==1){
                    break;
                }
            }
        }else if(arr2[i]==2){
            for(j=i+1;j<len;j++){
                if(arr2[j]==0){
                    arr2[j]=2;
                    arr2[i]=0;
                    break;
                }else if(arr2[j]==2){
                    break;
                }
            }
        } 
 

}