/**https://leetcode.com/problems/minimum-space-wasted-from-packaging/ */
//You have n packages that you are trying to place in boxes, one package in each box. There are m suppliers that each produce boxes of different sizes (with infinite supply). A package can be placed in a box if the size of the package is less than or equal to the size of the box.
//The package sizes are given as an integer array packages, where packages[i] is the size of the ith package. The suppliers are given as a 2D integer array boxes, where boxes[j] is an array of box sizes that the jth supplier produces.
//You want to choose a single supplier and use boxes from them such that the total wasted space is minimized. For each package in a box, we define the space wasted to be size of the box - size of the package. The total wasted space is the sum of the space wasted in all the boxes.
//For example, if you have to fit packages with sizes [2,3,5] and the supplier offers boxes of sizes [4,8], you can fit the packages of size-2 and size-3 into two boxes of size-4 and the package with size-5 into a box of size-8. This would result in a waste of (4-2) + (4-3) + (8-5) = 6.
//Return the minimum total wasted space by choosing the box supplier optimally, or -1 if it is impossible to fit all the packages inside boxes. Since the answer may be large, return it modulo 109 + 7.


int minWastedSpace(int* packages, int packagesSize, int** boxes, int boxesSize, int* boxesColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*boxesSize);
    for(i=0;i<boxesSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<boxesSize;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[boxesSize-1];

}

    