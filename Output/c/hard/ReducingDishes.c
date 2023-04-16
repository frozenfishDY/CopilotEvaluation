/**https://leetcode.com/problems/reducing-dishes/ */
//A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
//Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
//Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
//Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.


int maxSatisfaction(int* satisfaction, int satisfactionSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*satisfactionSize);
    for(i=0;i<satisfactionSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<satisfactionSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<satisfactionSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    