/**https://leetcode.com/problems/number-of-ways-to-split-a-string/ */
//Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
//Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.


int numWays(char * s){
    int count = 0;
    int len = strlen(s);
    int oneCount = 0;
    int twoCount = 0;
    int threeCount = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '1'){
            oneCount++;
        }
    }
    if(oneCount % 3 != 0){
        return 0;
    }
    if(oneCount == 0){
        return (int)(((long long)(len - 1) * (long long)(len - 2) / 2) % 1000000007);
    }
    int one = oneCount / 3;
    int two = one * 2;
    int oneIndex = 0;
    int twoIndex = 0;
    int threeIndex = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '1'){
            oneIndex++;
            if(oneIndex == one){
                twoIndex = oneIndex;
            }
            if(oneIndex == two){
                threeIndex = oneIndex;
            }
        }
        if(oneIndex == one){
            twoCount++;
        }
        if(oneIndex == two){
            threeCount++;
        }
    }
    return (int)(((long long)twoCount * (long long)threeCount) % 1000000007);

}

    