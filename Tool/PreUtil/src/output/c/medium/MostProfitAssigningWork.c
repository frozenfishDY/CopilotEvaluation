/**https://leetcode.com/problems/most-profit-assigning-work/ */
//You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
//difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
//worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
//Every worker can be assigned at most one job, but one job can be completed multiple times.
//For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
//Return the maximum profit we can achieve after assigning the workers to the jobs.


int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize){
    int* hash = (int*)malloc(sizeof(int) * 100001);
    for(int i = 0; i < difficultySize; i++){
        hash[difficulty[i]] = fmax(hash[difficulty[i]], profit[i]);
    }
    for(int i = 1; i < 100001; i++){
        hash[i] = fmax(hash[i], hash[i - 1]);
    }
    int max = 0;
    for(int i = 0; i < workerSize; i++){
        max += hash[worker[i]];
    }
    return max;


}

    