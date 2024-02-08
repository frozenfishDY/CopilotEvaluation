/**https://leetcode.com/problems/baseball-game/ */
//You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
//You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
//An integer x.
//Record a new score of x.
//'+'.
//Record a new score that is the sum of the previous two scores.
//'D'.
//Record a new score that is the double of the previous score.
//'C'.
//Invalidate the previous score, removing it from the record.
//Return the sum of all the scores on the record after applying all the operations.
//The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.


int calPoints(char ** operations, int operationsSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int sum = 0;
    int temp = 0;
    int flag = 0;
    int *arr = (int *)malloc(sizeof(int) * operationsSize);
    for(i = 0; i < operationsSize; i++){
        if(operations[i][0] == 'C'){
            arr[j - 1] = 0;
            j--;
        }
        else if(operations[i][0] == 'D'){
            arr[j] = arr[j - 1] * 2;
            j++;
        }
        else if(operations[i][0] == '+'){
            arr[j] = arr[j - 1] + arr[j - 2];
            j++;
        }
        else{
            arr[j] = atoi(operations[i]);
            j++;
        }
    }
    for(k = 0; k < j; k++){
        sum += arr[k];
    }
    return sum;

}

    