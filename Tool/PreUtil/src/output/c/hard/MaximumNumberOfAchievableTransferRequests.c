/**https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/ */
//We have n buildings numbered from 0 to n - 1. Each building has a number of employees. It's transfer season, and some employees want to change the building they reside in.
//You are given an array requests where requests[i] = [fromi, toi] represents an employee's request to transfer from building fromi to building toi.
//All buildings are full, so a list of requests is achievable only if for each building, the net change in employee transfers is zero. This means the number of employees leaving is equal to the number of employees moving in. For example if n = 3 and two employees are leaving building 0, one is leaving building 1, and one is leaving building 2, there should be two employees moving to building 0, one employee moving to building 1, and one employee moving to building 2.
//Return the maximum number of achievable requests.


int maximumRequests(int n, int** requests, int requestsSize, int* requestsColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<n;i++){
        arr[i] = arr[i-1] * i;
    }
    int sum = 0;
    for(i=0;i<n;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    