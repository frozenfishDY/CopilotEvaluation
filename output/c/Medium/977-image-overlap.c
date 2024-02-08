/**https://leetcode.com/problems/image-overlap/ */
//You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.
//We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.
//Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.
//Return the largest possible overlap.


int largestOverlap(int** img1, int img1Size, int* img1ColSize, int** img2, int img2Size, int* img2ColSize){
    int n = img1Size;
    int max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int count = 0;
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(k + i < n && l + j < n && img1[k + i][l + j] == 1 && img2[k][l] == 1){
                        count++;
                    }
                }
            }
            if(count > max){
                max = count;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int count = 0;
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(k + i < n && l + j < n && img1[k][l] == 1 && img2[k + i][l + j] == 1){
                        count++;
                    }
                }
            }
            if(count > max){
                max = count;
            }
        }
    }
    return max;

}

    