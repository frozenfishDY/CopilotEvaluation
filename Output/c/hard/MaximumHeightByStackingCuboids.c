/**https://leetcode.com/problems/maximum-height-by-stacking-cuboids/ */
//Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.
//You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.
//Return the maximum height of the stacked cuboids.


int maxHeight(int** cuboids, int cuboidsSize, int* cuboidsColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*cuboidsSize);
    for(i=0;i<cuboidsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<cuboidsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<cuboidsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    