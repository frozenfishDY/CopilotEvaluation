/**https://leetcode.com/problems/sum-of-numbers-with-units-digit-k/ */
//Given two integers num and k, consider a set of positive integers with the following properties:
//	The units digit of each integer is k.
//	The sum of the integers is num.
//Return the minimum possible size of such a set, or -1 if no such set exists.
//Note:
//	The set can contain multiple instances of the same integer, and the sum of an empty set is considered 0.
//	The units digit of a number is the rightmost digit of the number.
// 
//Example 1:
//Input: num = 58, k = 9
//Output: 2
//Explanation:
//One valid set is [9,49], as the sum is 58 and each integer has a units digit of 9.
//Another valid set is [19,39].
//It can be shown that 2 is the minimum possible size of a valid set.
//Example 2:
//Input: num = 37, k = 2
//Output: -1
//Explanation: It is not possible to obtain a sum of 37 using only integers that have a units digit of 2.
//Example 3:
//Input: num = 0, k = 7
//Output: 0
//Explanation: The sum of an empty set is considered 0.
// 
//Constraints:
//	0 <= num <= 3000
//	0 <= k <= 9
int minimumNumbers(int num, int k){
int count=0;
    int i,j;
    int sum=0;
    int temp;
    int ret;
    if(num<k){
        return -1;
    }
    if(num==k){
        return 1;
    }
    if(k==0){
        return -1;
    }
    if(k==1){
        return num;
    }
    if((num%k)==0){
        return num/k;
    }
    for(i=1;i<=k;i++){
        sum+=i;
    }
    if((num%k)==sum){
        return num/k;
    }
    if((num%k)<sum){
        return -1;
    }
    ret=num/k;
    temp=num%k;
    if(temp>0){
        ret+=1;
    }
    return ret;
}