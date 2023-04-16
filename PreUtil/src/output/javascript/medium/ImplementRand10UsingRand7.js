/**https://leetcode.com/problems/implement-rand10-using-rand7/ */
//Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.
//Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().


/**
 * The rand7() API is already defined for you.
 * var rand7 = function() {}
 * @return {number} a random integer in the range 1 to 7
 */
var rand10 = function() {
    let row = 0;
    let col = 0;
    let idx = 0;
    do{
        row = rand7();
        col = rand7();
        idx = col + (row - 1) * 7;
    }while(idx > 40);
    return 1 + (idx - 1) % 10;
    
};

    