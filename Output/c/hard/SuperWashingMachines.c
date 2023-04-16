/**https://leetcode.com/problems/super-washing-machines/ */
//You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.
//For each move, you could choose any m (1 <= m <= n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time.
//Given an integer array machines representing the number of dresses in each washing machine from left to right on the line, return the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.


int findMinMoves(int* machines, int machinesSize){
    int sum = 0;
    for(int i = 0; i < machinesSize; i++){
        sum += machines[i];
    }
    if(sum % machinesSize != 0) return -1;
    int avg = sum / machinesSize;
    int result = 0;
    int count = 0;
    for(int i = 0; i < machinesSize; i++){
        count += machines[i] - avg;
        result = fmax(result, fmax(abs(count), machines[i] - avg));
    }
    return result;

}

    