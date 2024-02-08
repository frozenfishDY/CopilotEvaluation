/**https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/ */
//You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.
//Your goal is to satisfy one of the following three conditions:
//Every letter in a is strictly less than every letter in b in the alphabet.
//Every letter in b is strictly less than every letter in a in the alphabet.
//Both a and b consist of only one distinct letter.
//Return the minimum number of operations needed to achieve your goal.


int minCharacters(char * a, char * b){
    int aLen = strlen(a);
    int bLen = strlen(b);
    int* aCount = (int*)calloc(26, sizeof(int));
    int* bCount = (int*)calloc(26, sizeof(int));
    int* aCount2 = (int*)calloc(26, sizeof(int));
    int* bCount2 = (int*)calloc(26, sizeof(int));
    int* aCount3 = (int*)calloc(26, sizeof(int));
    int* bCount3 = (int*)calloc(26, sizeof(int));
    int* aCount4 = (int*)calloc(26, sizeof(int));
    int* bCount4 = (int*)calloc(26, sizeof(int));
    int* aCount5 = (int*)calloc(26, sizeof(int));
    int* bCount5 = (int*)calloc(26, sizeof(int));
    int* aCount6 = (int*)calloc(26, sizeof(int));
    int* bCount6 = (int*)calloc(26, sizeof(int));
    int* aCount7 = (int*)calloc(26, sizeof(int));
    int* bCount7 = (int*)calloc(26, sizeof(int));
    int* aCount8 = (int*)calloc(26, sizeof(int));
    int* bCount8 = (int*)calloc(26, sizeof(int));
    int* aCount9 = (int*)calloc(26, sizeof(int));
    int* bCount9 = (int*)calloc(26, sizeof(int));
    int* aCount10 = (int*)calloc(26, sizeof(int));
    int* bCount10 = (int*)calloc(26, sizeof(int));
    int* aCount11 = (int*)calloc(26, sizeof(int));
    int* bCount11 = (int*)calloc(26, sizeof(int));
    int* aCount12 = (int*)calloc(26, sizeof(int));
    int* bCount12 = (int*)calloc(26, sizeof(int));
    int* aCount13 = (int*)calloc(26, sizeof(int));
    int* bCount13 = (int*)calloc(26, sizeof(int));
    int* aCount14 = (int*)calloc(26, sizeof(int));
    int* bCount14 = (int*)calloc(26, sizeof(int));
    


}

    