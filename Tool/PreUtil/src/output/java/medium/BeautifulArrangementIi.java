/**https://leetcode.com/problems/beautiful-arrangement-ii/ */
//Given two integers n and k, construct a list answer that contains n different positive integers ranging from 1 to n and obeys the following requirement:
//Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
//Return the list answer. If there multiple valid answers, return any of them.


class BeautifulArrangementIi {
    public int[] constructArray(int n, int k) {
        int[] res = new int[n];
        int i = 0;
        int l = 1;
        int r = n;
        while(l <= r){
            if(k > 1){
                res[i++] = k-- % 2 == 1 ? l++ : r--;
            }else{
                res[i++] = l++;
            }
        }
        return res;
        
    }
}

    