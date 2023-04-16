/**https://leetcode.com/problems/sort-integers-by-the-power-value/ */
//The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:
//if x is even then x = x / 2
//if x is odd then x = 3 * x + 1
//For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).
//Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.
//Return the kth integer in the range [lo, hi] sorted by the power value.
//Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in a 32-bit signed integer.


int getKth(int lo, int hi, int k){
    int i, j, temp, *arr = malloc((hi - lo + 1) * sizeof(int));
    for(i = lo; i <= hi; i++){
        temp = i;
        j = 0;
        while(temp != 1){
            if(temp % 2 == 0){
                temp /= 2;
            }
            else{
                temp = 3 * temp + 1;
            }
            j++;
        }
        arr[i - lo] = j;
    }
    for(i = 0; i < hi - lo + 1; i++){
        for(j = i + 1; j < hi - lo + 1; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[k - 1] + lo;

}

    