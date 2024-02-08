/**https://leetcode.com/problems/minimum-genetic-mutation/ */
//A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
//Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
//For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
//There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
//Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
//Note that the starting point is assumed to be valid, so it might not be included in the bank.


int minMutation(char * startGene, char * endGene, char ** bank, int bankSize){
    int* visited = (int*)malloc(sizeof(int) * bankSize);
    for(int i = 0; i < bankSize; i++){
        visited[i] = 0;
    }
    int count = 0;
    int* queue = (int*)malloc(sizeof(int) * bankSize);
    int queueSize = 0;
    int* nextQueue = (int*)malloc(sizeof(int) * bankSize);
    int nextQueueSize = 0;
    for(int i = 0; i < bankSize; i++){
        if(isMutation(startGene, bank[i])){
            queue[queueSize++] = i;
            visited[i] = 1;
        }
    }
    while(queueSize > 0){
        count++;
        for(int i = 0; i < queueSize; i++){
            if(strcmp(bank[queue[i]], endGene) == 0){
                return count;
            }
            for(int j = 0; j < bankSize; j++){
                if(!visited[j] && isMutation(bank[queue[i]], bank[j])){
                    nextQueue[nextQueueSize++] = j;
                    visited[j] = 1;
                }
            }
        }
        int* temp = queue;
        queue = nextQueue;
        nextQueue = temp;
        queueSize = nextQueueSize;
        nextQueueSize = 0;
    }
    return -1;

}

    