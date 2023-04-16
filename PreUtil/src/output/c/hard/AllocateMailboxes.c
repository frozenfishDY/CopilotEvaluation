/**https://leetcode.com/problems/allocate-mailboxes/ */
//Given the array houses where houses[i] is the location of the ith house along a street and an integer k, allocate k mailboxes in the street.
//Return the minimum total distance between each house and its nearest mailbox.
//The test cases are generated so that the answer fits in a 32-bit integer.


int minDistance(int* houses, int housesSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*housesSize);
    for(i=0;i<housesSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*housesSize);
    for(i=0;i<housesSize;i++){
        arr2[i] = 0;
    }
    for(i=0;i<housesSize;i++){
        for(j=0;j<housesSize;j++){
            if(i==j){
                arr[i] = arr[i] + houses[j];
            }
            else{
                arr[i] = arr[i] + abs(houses[i]-houses[j]);
            }
        }
    }
    for(i=0;i<housesSize;i++){
        for(j=0;j<housesSize;j++){
            if(i==j){
                arr2[i] = arr2[i] + arr[j];
            }
            else{
                arr2[i] = arr2[i] + abs(arr[i]-arr[j]);
            }
        }
    }
    int sum = 0;
    for(i=0;i<housesSize;i++){
        sum = sum + arr2[i];
    }
    return sum;

}

    