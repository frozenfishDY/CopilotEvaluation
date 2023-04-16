/**https://leetcode.com/problems/pizza-with-3n-slices/ */
//There is a pizza with 3n slices of varying size, you and your friends will take slices of pizza as follows:
//You will pick any pizza slice.
//Your friend Alice will pick the next slice in the anti-clockwise direction of your pick.
//Your friend Bob will pick the next slice in the clockwise direction of your pick.
//Repeat until there are no more slices of pizzas.
//Given an integer array slices that represent the sizes of the pizza slices in a clockwise direction, return the maximum possible sum of slice sizes that you can pick.


int maxSizeSlices(int* slices, int slicesSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*slicesSize);
    for(i=0;i<slicesSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<slicesSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<slicesSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;


}

    