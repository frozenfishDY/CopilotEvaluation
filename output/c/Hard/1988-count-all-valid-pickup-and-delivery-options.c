/**https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/ */
//Given n orders, each order consist in pickup and delivery services. 
//Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
//Since the answer may be too large, return it modulo 10^9 + 7.


int countOrders(int n){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<n;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    