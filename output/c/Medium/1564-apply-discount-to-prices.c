/**https://leetcode.com/problems/apply-discount-to-prices/ */
//A sentence is a string of single-space separated words where each word can contain digits, lowercase letters, and the dollar sign '$'. A word represents a price if it is a sequence of digits preceded by a dollar sign.
//For example, "$100", "$23", and "$6" represent prices while "100", "$", and "$1e5" do not.
//You are given a string sentence representing a sentence and an integer discount. For each word representing a price, apply a discount of discount% on the price and update the word in the sentence. All updated prices should be represented with exactly two decimal places.
//Return a string representing the modified sentence.
//Note that all prices will contain at most 10 digits.


char * discountPrices(char * sentence, int discount){
    int i, j, k, count = 0, temp = 0, sum = 0;
    for(i = 0; i < strlen(sentence); i++){
        if(sentence[i] == '$'){
            for(j = i+1; j < strlen(sentence); j++){
                if(sentence[j] == ' '){
                    break;
                }
                temp = temp * 10 + sentence[j] - '0';
            }
            sum = temp - (temp * discount) / 100;
            temp = 0;
            for(k = i+1; k < j; k++){
                sentence[k] = ' ';
            }
            while(sum != 0){
                sentence[k] = sum % 10 + '0';
                sum = sum / 10;
                k++;
            }
            sentence[k] = ' ';
        }
    }
    return sentence;


}

    