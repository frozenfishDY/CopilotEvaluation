/**https://leetcode.com/problems/maximum-number-of-eaten-apples/ */
//There is a special kind of apple tree that grows apples every day for n days. On the ith day, the tree grows apples[i] apples that will rot after days[i] days, that is on day i + days[i] the apples will be rotten and cannot be eaten. On some days, the apple tree does not grow any apples, which are denoted by apples[i] == 0 and days[i] == 0.
//You decided to eat at most one apple a day (to keep the doctors away). Note that you can keep eating after the first n days.
//Given two integer arrays days and apples of length n, return the maximum number of apples you can eat.


int eatenApples(int* apples, int applesSize, int* days, int daysSize){
    int* arr = malloc(applesSize * sizeof(int));
    int max = 0;
    for(int i = 0; i < applesSize; i++){
        arr[i] = apples[i] + i;
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int sum = 0;
    for(int i = 0; i < applesSize; i++){
        if(arr[i] > i){
            sum += apples[i];
        }
    }
    return sum;

}

    