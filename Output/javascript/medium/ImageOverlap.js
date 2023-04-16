/**https://leetcode.com/problems/image-overlap/ */
//You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.
//We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.
//Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.
//Return the largest possible overlap.


/**
 * @param {number[][]} img1
 * @param {number[][]} img2
 * @return {number}
 */
var largestOverlap = function(img1, img2) {
    let n = img1.length;
    let max = 0;
    for(let i = -n + 1; i < n; i++){
        for(let j = -n + 1; j < n; j++){
            max = Math.max(max, countOverlap(img1, img2, i, j));
        }
    }
    return max;
    
    
};

    