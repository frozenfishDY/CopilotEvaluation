/**https://leetcode.com/problems/subdomain-visit-count/ */
//A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
//A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.
//For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
//Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** subdomainVisits(char ** cpdomains, int cpdomainsSize, int* returnSize){
    char** result = (char**)malloc(sizeof(char*) * 10000);
    *returnSize = 0;
    int* count = (int*)malloc(sizeof(int) * 10000);
    int countSize = 0;
    for(int i = 0; i < cpdomainsSize; i++){
        int j = 0;
        int currentCount = 0;
        while(cpdomains[i][j] != ' '){
            currentCount = currentCount * 10 + (cpdomains[i][j] - '0');
            j++;
        }
        j++;
        int k = j;
        while(cpdomains[i][k] != '\0'){
            if(cpdomains[i][k] == '.'){
                char* currentDomain = (char*)malloc(sizeof(char) * 100);
                int currentDomainSize = 0;
                for(int l = k + 1; l < strlen(cpdomains[i]); l++){
                    currentDomain[currentDomainSize] = cpdomains[i][l];
                    currentDomainSize++;
                }
                currentDomain[currentDomainSize] = '\0';
                int m = 0;
                for(m = 0; m < countSize; m++){
                    if(strcmp(result[m], currentDomain) == 0){
                        count[m] += currentCount;
                        break;
                    }
                }
                if(m == countSize){
                    result[countSize] = currentDomain;
                    count[countSize] = currentCount;
                    countSize++;
                }
            }
            k++;
        }
        char* currentDomain = (char*)malloc(sizeof(char) * 100);
        int currentDomainSize = 0;
        for(int l = j; l < strlen(cpdomains[i]); l++){
            currentDomain[currentDomainSize] = cpdomains[i][l];
            currentDomainSize++;
        }
        currentDomain[currentDomainSize] = '\0';
        int m = 0;
        for(m = 0; m < countSize; m++){
            if(strcmp(result[m], currentDomain) == 0){
                count[m] += currentCount;
                break;
            }
        }
        if(m == countSize){
            result[countSize] = currentDomain;
            count[countSize] = currentCount;
            countSize++;
        }
    }
    for(int i = 0; i < countSize; i++){
        char* currentResult = (char*)malloc(sizeof(char)
            * (strlen(result[i]) + 10));
        int currentResultSize = 0;
        int currentCount = count[i];
        while(currentCount != 0){
            currentResult[currentResultSize] = currentCount % 10 + '0';
            currentCount /= 10;
            currentResultSize++;
        }
        for(int j = currentResultSize - 1; j >= 0; j--){
            result[i][currentResultSize - j - 1] = currentResult[j];
        }
        result[i][currentResultSize] = ' ';
        for(int j = 0; j < strlen(result[i]); j++){
            result[i][currentResultSize + j + 1] = result[i][j];
        }
        result[i][currentResultSize + strlen(result[i]) + 1] = '\0';

        

}

    