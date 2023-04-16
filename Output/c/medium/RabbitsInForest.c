/**https://leetcode.com/problems/rabbits-in-forest/ */
//There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
//Given the array answers, return the minimum number of rabbits that could be in the forest.


int numRabbits(int* answers, int answersSize){
    int* count = (int*)malloc(sizeof(int) * 1000);
    int result = 0;
    for(int i = 0; i < 1000; i++){
        count[i] = 0;
    }
    for(int i = 0; i < answersSize; i++){
        count[answers[i]]++;
    }
    for(int i = 0; i < 1000; i++){
        if(count[i] > 0){
            result += (count[i] + i) / (i + 1) * (i + 1);
        }
    }
    return result;

}

    