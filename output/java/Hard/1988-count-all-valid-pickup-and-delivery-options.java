/**https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/ */
//Given n orders, each order consist in pickup and delivery services. 
//Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 
//Since the answer may be too large, return it modulo 10^9 + 7.


class CountAllValidPickupAndDeliveryOptions {
    public int countOrders(int n) {
        long res = 1;
        int mod = 1000000007;
        for(int i = 1; i <= n; i++){
            res = res * (i * 2 - 1) * (i * 2) % mod;
        }
        return (int)res;
        
    }
}
     
    