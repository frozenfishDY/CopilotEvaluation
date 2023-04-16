/**https://leetcode.com/problems/heaters/ */
//Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
//Every house can be warmed, as long as the house is within the heater's warm radius range. 
//Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
//Notice that all the heaters follow your radius standard, and the warm radius will the same.


/**
 * @param {number[]} houses
 * @param {number[]} heaters
 * @return {number}
 */
var findRadius = function(houses, heaters) {
    let n = houses.length;
    let m = heaters.length;
    heaters.sort((a, b) => a - b);
    let result = 0;
    for(let i = 0; i < n; i++){
        let left = 0;
        let right = m - 1;
        while(left < right){
            let mid = Math.floor((left + right) / 2);
            if(heaters[mid] < houses[i]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        let dist1 = Math.abs(heaters[left] - houses[i]);
        let dist2 = left > 0 ? Math.abs(heaters[left - 1] - houses[i]) : Number.MAX_SAFE_INTEGER;
        result = Math.max(result, Math.min(dist1, dist2));
    }
    return result;
    
};

    