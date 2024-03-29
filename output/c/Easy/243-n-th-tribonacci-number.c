/**https://leetcode.com/problems/n-th-tribonacci-number/ */
//The Tribonacci sequence Tn is defined as follows: _x000D_
//_x000D_
//T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0._x000D_
//_x000D_
//Given n, return the value of Tn._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: n = 4_x000D_
//Output: 4_x000D_
//Explanation:_x000D_
//T_3 = 0 + 1 + 1 = 2_x000D_
//T_4 = 1 + 1 + 2 = 4_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//Input: n = 25_x000D_
//Output: 1389537_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	0 <= n <= 37_x000D_
//	The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1._x000D_


int tribonacci(int n){
if(n==0)return 0;
    if(n==1||n==2)return 1;
    int a=0,b=1,c=1;
    int i;
    for(i=3;i<=n;i++){
        int temp=c;
        c=a+b+c;
        a=b;
        b=temp;
    }
    return c;
}