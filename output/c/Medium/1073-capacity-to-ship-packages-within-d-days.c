/**https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ */
//A conveyor belt has packages that must be shipped from one port to another within days days.
//The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
//Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


int shipWithinDays(int* weights, int weightsSize, int days){
    int left = 0;
    int right = 0;
    for(int i = 0; i < weightsSize; i++){
        left = left > weights[i] ? left : weights[i];
        right += weights[i];
    }
    while(left < right){
        int mid = left + (right - left) / 2;
        int sum = 0;
        int count = 1;
        for(int i = 0; i < weightsSize; i++){
            if(sum + weights[i] > mid){
                count++;
                sum = weights[i];
            }else{
                sum += weights[i];
            }
        }
        if(count > days){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;

}

    