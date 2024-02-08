/**https://leetcode.com/problems/assign-cookies/ */
//Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
//Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.


int findContentChildren(int* g, int gSize, int* s, int sSize){
    int i = 0;
    int j = 0;
    int count = 0;
    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);
    while(i < gSize && j < sSize){
        if(g[i] <= s[j]){
            count++;
            i++;
            j++;
        }else{
            j++;
        }
    }
    return count;


}

    