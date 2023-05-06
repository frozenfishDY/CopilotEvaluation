/**https://leetcode.com/problems/implement-rand10-using-rand7/ */
//Given the API rand7() that generates a uniform random integer in the range [1, 7], write a function rand10() that generates a uniform random integer in the range [1, 10]. You can only call the API rand7(), and you shouldn't call any other API. Please do not use a language's built-in random API.
//Each test case will have one internal argument n, the number of times that your implemented function rand10() will be called while testing. Note that this is not an argument passed to rand10().


/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class ImplementRand10UsingRand7 extends SolBase {
    public int rand10() {
        int res = 40;
        while(res >= 40){
            res = 7 * (rand7() - 1) + rand7() - 1;
        }
        return res % 10 + 1;
        
        
    }
}

    