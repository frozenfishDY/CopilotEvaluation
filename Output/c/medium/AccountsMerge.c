/**https://leetcode.com/problems/accounts-merge/ */
//Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** accountsMerge(char *** accounts, int accountsSize, int* accountsColSize, int* returnSize, int** returnColumnSizes){
    int* parent = (int*)malloc(sizeof(int) * accountsSize);
    for(int i = 0; i < accountsSize; i++){
        parent[i] = i;
    }
    for(int i = 0; i < accountsSize; i++){
        for(int j = i + 1; j < accountsSize; j++){
            for(int k = 1; k < accountsColSize[i]; k++){
                for(int l = 1; l < accountsColSize[j]; l++){
                    if(strcmp(accounts[i][k], accounts[j][l]) == 0){
                        int x = i;
                        int y = j;
                        while(parent[x] != x){
                            x = parent[x];
                        }
                        while(parent[y] != y){
                            y = parent[y];
                        }
                        if(x != y){
                            parent[x] = y;
                        }
                    }
                }
            }
        }
    }
    int* count = (int*)malloc(sizeof(int) * accountsSize);
    for(int i = 0; i < accountsSize; i++){
        count[i] = 0;
    }
    for(int i = 0; i < accountsSize; i++){
        int x = i;
        while(parent[x] != x){
            x = parent[x];
        }
        count[x]++;
    }
    char*** answer = (char***)malloc(sizeof(char**) * accountsSize);
    for(int i = 0; i < accountsSize; i++){
        answer[i] = (char**)malloc(sizeof(char*) * 1001);
        for(int j = 0; j < 1001; j++){
            answer[i][j] = (char*)malloc(sizeof(char) * 31);
        }
    }
    int* index = (int*)malloc(sizeof(int) * accountsSize);
    for(int i = 0; i < accountsSize; i++){
        index[i] = 0;
    }
    for(int i = 0; i < accountsSize; i++){
        int x = i;
        while(parent[x] != x){
            x = parent[x];
        }
        strcpy(answer[x][index[x]], accounts[i][0]);
        index[x]++;
        for(int j = 1; j < accountsColSize[i]; j++){
            int flag = 0;
            for(int k = 1; k < index[x]; k++){
                if (strcmp(answer[x][k], accounts[i][j]) == 0){
                    flag = 1;
                    break;
                }

}

    