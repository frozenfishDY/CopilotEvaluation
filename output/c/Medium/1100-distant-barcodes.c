/**https://leetcode.com/problems/distant-barcodes/ */
//In a warehouse, there is a row of barcodes, where the ith barcode is barcodes[i].
//Rearrange the barcodes so that no two adjacent barcodes are equal. You may return any answer, and it is guaranteed an answer exists.
// 
//Example 1:
//Input: barcodes = [1,1,1,2,2,2]
//Output: [2,1,2,1,2,1]
//Example 2:
//Input: barcodes = [1,1,1,1,2,2,3,3]
//Output: [1,3,1,3,1,2,1,2]
// 
//Constraints:
//	1 <= barcodes.length <= 10000
//	1 <= barcodes[i] <= 10000
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeBarcodes(int* barcodes, int barcodesSize, int* returnSize){
int* res = (int*)malloc(sizeof(int) * barcodesSize);
    *returnSize = barcodesSize;
    int count[10001] = {0};
    int max = 0, index = 0;
    for (int i = 0; i < barcodesSize; i++) {
        count[barcodes[i]]++;
        if (count[barcodes[i]] > max) {
            max = count[barcodes[i]];
            index = barcodes[i];
        }
    }
    int pos = 0;
    while (count[index] > 0) {
        res[pos] = index;
        pos += 2;
        count[index]--;
    }
    for (int i = 0; i < 10001; i++) {
        while (count[i] > 0) {
            if (pos >= barcodesSize) {
                pos = 1;
            }
            res[pos] = i;
            pos += 2;
            count[i]--;
        }
    }
    return res;
}