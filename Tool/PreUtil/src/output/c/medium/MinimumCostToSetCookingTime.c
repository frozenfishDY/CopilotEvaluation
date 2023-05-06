/**https://leetcode.com/problems/minimum-cost-to-set-cooking-time/ */
//A generic microwave supports cooking times for:
//at least 1 second.
//at most 99 minutes and 99 seconds.
//To set the cooking time, you push at most four digits. The microwave normalizes what you push as four digits by prepending zeroes. It interprets the first two digits as the minutes and the last two digits as the seconds. It then adds them up as the cooking time. For example,
//You push 9 5 4 (three digits). It is normalized as 0954 and interpreted as 9 minutes and 54 seconds.
//You push 0 0 0 8 (four digits). It is interpreted as 0 minutes and 8 seconds.
//You push 8 0 9 0. It is interpreted as 80 minutes and 90 seconds.
//You push 8 1 3 0. It is interpreted as 81 minutes and 30 seconds.
//You are given integers startAt, moveCost, pushCost, and targetSeconds. Initially, your finger is on the digit startAt. Moving the finger above any specific digit costs moveCost units of fatigue. Pushing the digit below the finger once costs pushCost units of fatigue.
//There can be multiple ways to set the microwave to cook for targetSeconds seconds but you are interested in the way with the minimum cost.
//Return the minimum cost to set targetSeconds seconds of cooking time.
//Remember that one minute consists of 60 seconds.


int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds){
    int i;
    int sum = 0;
    int arr[4] = {0};
    int count = 0;
    int mod = 1000000007;
    int min = 0;
    int index = 0;
    int* arr1 = malloc(4 * sizeof(int));
    while(targetSeconds > 0){
        arr[count] = targetSeconds % 10;
        targetSeconds = targetSeconds / 10;
        count++;
    }
    for(i = 0; i < count; i++){
        arr1[i] = arr[i];
    }
    for(i = 0; i < count; i++){
        if(arr[i] < arr1[i]){
            if(arr1[i] - arr[i] > min){
                min = arr1[i] - arr[i];
                index = i;
            }
        }
    }
    sum = sum - arr1[index] + min;
    return sum;

}

    