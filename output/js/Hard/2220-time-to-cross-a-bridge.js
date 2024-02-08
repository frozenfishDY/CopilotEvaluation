/**https://leetcode.com/problems/time-to-cross-a-bridge/ */
//There are k workers who want to move n boxes from an old warehouse to a new one. You are given the two integers n and k, and a 2D integer array time of size k x 4 where time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi].
//The warehouses are separated by a river and connected by a bridge. The old warehouse is on the right bank of the river, and the new warehouse is on the left bank of the river. Initially, all k workers are waiting on the left side of the bridge. To move the boxes, the ith worker (0-indexed) can :
//Cross the bridge from the left bank (new warehouse) to the right bank (old warehouse) in leftToRighti minutes.
//Pick a box from the old warehouse and return to the bridge in pickOldi minutes. Different workers can pick up their boxes simultaneously.
//Cross the bridge from the right bank (old warehouse) to the left bank (new warehouse) in rightToLefti minutes.
//Put the box in the new warehouse and return to the bridge in putNewi minutes. Different workers can put their boxes simultaneously.
//A worker i is less efficient than a worker j if either condition is met:
//leftToRighti + rightToLefti > leftToRightj + rightToLeftj
//leftToRighti + rightToLefti == leftToRightj + rightToLeftj and i > j
//The following rules regulate the movement of the workers through the bridge :
//If a worker x reaches the bridge while another worker y is crossing the bridge, x waits at their side of the bridge.
//If the bridge is free, the worker waiting on the right side of the bridge gets to cross the bridge. If more than one worker is waiting on the right side, the one with the lowest efficiency crosses first.
//If the bridge is free and no worker is waiting on the right side, and at least one box remains at the old warehouse, the worker on the left side of the river gets to cross the bridge. If more than one worker is waiting on the left side, the one with the lowest efficiency crosses first.
//Return the instance of time at which the last worker reaches the left bank of the river after all n boxes have been put in the new warehouse.


/**
 * @param {number} n
 * @param {number} k
 * @param {number[][]} time
 * @return {number}
 */
var findCrossingTime = function(n, k, time) {
    let ans = 0;
    let left = new Array(k).fill(0);
    let right = new Array(k).fill(0);
    let leftToRight = new Array(k).fill(0);
    let rightToLeft = new Array(k).fill(0);
    let pickOld = new Array(k).fill(0);
    let putNew = new Array(k).fill(0);
    for(let i = 0; i < k; i++){
        leftToRight[i] = time[i][0];
        pickOld[i] = time[i][1];
        rightToLeft[i] = time[i][2];
        putNew[i] = time[i][3];
    }
    let leftToRightSorted = leftToRight.slice().sort((a, b) => a - b);
    let rightToLeftSorted = rightToLeft.slice().sort((a, b) => a - b);
    let pickOldSorted = pickOld.slice().sort((a, b) => a - b);
    let putNewSorted = putNew.slice().sort((a, b) => a - b);
    let leftToRightMap = new Map();
    let rightToLeftMap = new Map();
    let pickOldMap = new Map();
    let putNewMap = new Map();
    for(let i = 0; i < k; i++){
        leftToRightMap.set(leftToRightSorted[i], i);
        rightToLeftMap.set(rightToLeftSorted[i], i);
        pickOldMap.set(pickOldSorted[i], i);
        putNewMap.set(putNewSorted[i], i);
    }
    let leftToRightIndex = 0;
    let rightToLeftIndex = 0;
    let pickOldIndex = 0;
    let putNewIndex = 0;
    let leftToRightCount = 0;
    let rightToLeftCount = 0;
    let pickOldCount = 0;
    let putNewCount = 0;
    let leftToRightSet = new Set();
    let rightToLeftSet = new Set();
    let pickOldSet = new Set();
    let putNewSet = new Set();
    while(n > 0){
        if(leftToRightCount < k && rightToLeftCount < k && pickOldCount < k && putNewCount < k){
            let leftToRightMin = leftToRightSorted[leftToRightIndex];
            let rightToLeftMin = rightToLeftSorted[rightToLeftIndex];
            let pickOldMin = pickOldSorted[pickOldIndex];
            let putNewMin = putNewSorted[putNewIndex];
            let min = Math.min(leftToRightMin, rightToLeftMin, pickOldMin, putNewMin);
            if(min == leftToRightMin){
                leftToRightSet.add(leftToRightMap.get(leftToRightMin));
                leftToRightIndex++;
                leftToRightCount++;
            }
            if(min == rightToLeftMin){
                rightToLeftSet.add(rightToLeftMap.get(rightToLeftMin));
                rightToLeftIndex++;
                rightToLeftCount++;
            }
            if(min == pickOldMin){
                pickOldSet.add(pickOldMap.get(pickOldMin));
                pickOldIndex++;
                pickOldCount++;
            }
            if(min == putNewMin){
                putNewSet.add(putNewMap.get(putNewMin));
                putNewIndex++;
                putNewCount++;
            }
            ans += min;
        }
        else if(leftToRightCount < k && rightToLeftCount < k && pickOldCount < k){
            let leftToRightMin = leftToRightSorted[leftToRightIndex];
            let rightToLeftMin = rightToLeftSorted[rightToLeftIndex];
            let pickOldMin = pickOldSorted[pickOldIndex];
            let min = Math.min(leftToRightMin, rightToLeftMin, pickOldMin);
            if(min == leftToRightMin){
                leftToRightSet.add(leftToRightMap.get(leftToRightMin));
                leftToRightIndex++;
                leftToRightCount++;
            }
            if(min == rightToLeftMin){
                rightToLeftSet.add(rightToLeftMap.get(rightToLeftMin));
                rightToLeftIndex++;
                rightToLeftCount++;
            }
            if(min == pickOldMin){
                pickOldSet.add(pickOldMap.get(pickOldMin));
                pickOldIndex++;
                pickOldCount++;
            }
            ans += min;
        }
        else if(leftToRightCount < k && rightToLeftCount < k && putNewCount < k){
            let leftToRightMin = leftToRightSorted[leftToRightIndex];
            let rightToLeftMin = rightToLeftSorted[rightToLeftIndex];
            let putNewMin = putNewSorted[putNewIndex];
            let min = Math.min(leftToRightMin, rightToLeftMin, putNewMin);
            if(min == leftToRightMin){
                leftToRightSet.add(leftToRightMap.get(leftToRightMin));
                leftToRightIndex++;
                leftToRightCount++;
            }
            if(min == rightToLeftMin){
                rightToLeftSet.add(rightToLeftMap.get(rightToLeftMin));
                rightToLeftIndex++;
                rightToLeftCount++;
            }
            if(min == putNewMin){
                putNewSet.add(putNewMap.get(putNewMin));
                putNewIndex++;
                putNewCount++;
            }
            ans += min;
        }
        else if(leftToRightCount < k && pickOldCount < k && putNewCount < k){
     
};

    