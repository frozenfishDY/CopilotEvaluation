/**https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/ */
//There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:
//Eat one orange.
//If the number of remaining oranges n is divisible by 2 then you can eat n / 2 oranges.
//If the number of remaining oranges n is divisible by 3 then you can eat 2 * (n / 3) oranges.
//You can only choose one of the actions per day.
//Given the integer n, return the minimum number of days to eat n oranges.


int minDays(int n){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<n;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[n-1];

}

    