/**https://leetcode.com/problems/invalid-transactions/ */
//A transaction is possibly invalid if:
//	the amount exceeds $1000, or;
//	if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
//You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.
//Return a list of transactions that are possibly invalid. You may return the answer in any order.
// 
//Example 1:
//Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
//Output: ["alice,20,800,mtv","alice,50,100,beijing"]
//Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
//Example 2:
//Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
//Output: ["alice,50,1200,mtv"]
//Example 3:
//Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
//Output: ["bob,50,1200,mtv"]
// 
//Constraints:
//	transactions.length <= 1000
//	Each transactions[i] takes the form "{name},{time},{amount},{city}"
//	Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
//	Each {time} consist of digits, and represent an integer between 0 and 1000.
//	Each {amount} consist of digits, and represent an integer between 0 and 2000.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** invalidTransactions(char ** transactions, int transactionsSize, int* returnSize){
   *returnSize = 0;
    char **res = (char **)malloc(sizeof(char *) * transactionsSize);
    int *invalid = (int *)malloc(sizeof(int) * transactionsSize);
    memset(invalid, 0, sizeof(int) * transactionsSize);
    for (int i = 0; i < transactionsSize; ++i) {
        char *name = (char *)malloc(sizeof(char) * 11);
        char *time = (char *)malloc(sizeof(char) * 4);
        char *amount = (char *)malloc(sizeof(char) * 5);
        char *city = (char *)malloc(sizeof(char) * 11);
        sscanf(transactions[i], "%[^,],%[^,],%[^,],%[^,]", name, time, amount, city);
        if (atoi(amount) > 1000) {
            invalid[i] = 1;
        }
        for (int j = 0; j < transactionsSize; ++j) {
            if (i == j) {
                continue;
            }
            char *name1 = (char *)malloc(sizeof(char) * 11);
            char *time1 = (char *)malloc(sizeof(char) * 4);
            char *amount1 = (char *)malloc(sizeof(char) * 5);
            char *city1 = (char *)malloc(sizeof(char) * 11);
            sscanf(transactions[j], "%[^,],%[^,],%[^,],%[^,]", name1, time1, amount1, city1);
            if (strcmp(name, name1) == 0 && strcmp(city, city1) != 0 && abs(atoi(time) - atoi(time1)) <= 60) {
                invalid[i] = 1;
            }
        }
    }
    for (int i = 0; i < transactionsSize; ++i) {
        if (invalid[i]) {
            res[*returnSize] = (char *)malloc(sizeof(char) * 101);
            strcpy(res[*returnSize], transactions[i]);
            ++*returnSize;
        }
    }
    return res;
}