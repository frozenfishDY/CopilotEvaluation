/**https://leetcode.com/problems/russian-doll-envelopes/ */
//You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
//One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
//Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
//Note: You cannot rotate an envelope.


int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int* queue = (int*)malloc(sizeof(int) * envelopesSize);
    int head = 0, tail = 0;
    for(int i = 0; i < envelopesSize; i++){
        while(head < tail && envelopes[queue[tail - 1]] < envelopes[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result[i - k + 1] = envelopes[queue[head]];
    }
    return envelopesSize - k + 1;

}

    