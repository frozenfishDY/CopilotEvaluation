/**https://leetcode.com/problems/push-dominoes/ */
//There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//You are given a string dominoes representing the initial state where:
//dominoes[i] = 'L', if the ith domino has been pushed to the left,
//dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//dominoes[i] = '.', if the ith domino has not been pushed.
//Return a string representing the final state.


char * pushDominoes(char * dominoes){
    int len = strlen(dominoes);
    int* hash = (int*)malloc(sizeof(int) * len);
    int left = -1;
    int right = -1;
    for(int i = 0; i < len; i++){
        if(dominoes[i] == 'L'){
            left = i;
        }
        if(dominoes[i] == 'R'){
            right = i;
        }
        if(left == -1 && right == -1){
            hash[i] = 0;
        }
        else if(left == -1){
            hash[i] = right;
        }
        else if(right == -1){
            hash[i] = left;
        }
        else{
            if(i - left < right - i){
                hash[i] = left;
            }
            else if(i - left > right - i){
                hash[i] = right;
            }
            else{
                hash[i] = -1;
            }
        }
    }
    for(int i = 0; i < len; i++){
        if(hash[i] == -1){
            dominoes[i] = '.';
        }
        else if(hash[i] < i){
            dominoes[i] = 'L';
        }
        else if(hash[i] > i){
            dominoes[i] = 'R';
        }
    }
    return dominoes;

}

    