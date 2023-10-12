/**https://leetcode.com/problems/next-greater-numerically-balanced-number/ */
//An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
//Given an integer n, return the smallest numerically balanced number strictly greater than n.
// 
//Example 1:
//Input: n = 1
//Output: 22
//Explanation: 
//22 is numerically balanced since:
//- The digit 2 occurs 2 times. 
//It is also the smallest numerically balanced number strictly greater than 1.
//Example 2:
//Input: n = 1000
//Output: 1333
//Explanation: 
//1333 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times. 
//It is also the smallest numerically balanced number strictly greater than 1000.
//Note that 1022 cannot be the answer because 0 appeared more than 0 times.
//Example 3:
//Input: n = 3000
//Output: 3133
//Explanation: 
//3133 is numerically balanced since:
//- The digit 1 occurs 1 time.
//- The digit 3 occurs 3 times.
//It is also the smallest numerically balanced number strictly greater than 3000.
// 
//Constraints:
//	0 <= n <= 106
int nextBeautifulNumber(int n){
int i,j;
    int count[10]={0};
    int tmp=n;
    int len=0;
    int *arr=(int *)malloc(sizeof(int)*7);
    int index=0;
    int flag=0;
    while(tmp){
        count[tmp%10]++;
        tmp/=10;
        len++;
    }
    for(i=0;i<10;i++){
        if(count[i]!=0){
            for(j=0;j<count[i];j++){
                arr[index]=i;
                index++;
            }
        }
    }
    for(i=n+1;i<=1000000;i++){
        tmp=i;
        while(tmp){
            count[tmp%10]--;
            tmp/=10;
        }
        flag=0;
        for(j=0;j<10;j++){
            if(count[j]!=0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
        tmp=i;
        while(tmp){
            count[tmp%10]++;
            tmp/=10;
        }
    }
    return 0;
}