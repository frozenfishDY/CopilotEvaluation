/**https://leetcode.com/problems/integer-to-english-words/ */
//Convert a non-negative integer num to its English words representation.
// 
//Example 1:
//Input: num = 123
//Output: "One Hundred Twenty Three"
//Example 2:
//Input: num = 12345
//Output: "Twelve Thousand Three Hundred Forty Five"
//Example 3:
//Input: num = 1234567
//Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//Constraints:
//	0 <= num <= 231 - 1
/**
 * @param {number} num
 * @return {string}
 */
var numberToWords = function(num) {
    var numStr = num.toString();
    var numStrLen = numStr.length;
    var result = "";
    var billion = "";
    var million = "";
    var thousand = "";
    var hundred = "";
    var tens = "";
    var ones = "";
    var numStrIndex = 0;
    var numStrIndexMax = 0;
    var numStrIndexMin = 0;
    var numStrIndexHundred = 0;
    var numStrIndexThousand = 0;
    var numStrIndexMillion = 0;
    var numStrIndexBillion = 0;
    var numStrIndexHundredMax = 0;
    var numStrIndexThousandMax = 0;
    var numStrIndexMillionMax = 0;
    var numStrIndexBillionMax = 0;
    var numStrIndexHundreds = 0;
    var numStrIndexTens = 0;
    var numStrIndexOnes = 0;
    var numStrIndexTensMax = 0;
    var numStrIndexOnesMax = 0;
    var numStrIndexHundredsMax = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    var numStrIndexHundredsMin = 0;
    var numStrIndexTensMin = 0;
    var numStrIndexOnesMin = 0;
    if (numStrLen > 9) {
        numStrIndexBillion = numStrLen - 9;
        numStrIndexBillionMax = numStrIndexBillion + 3;
        billion = numStr.substring(numStrIndexBillion, numStrIndexBillionMax);
        billion = convertHundreds(billion);
        billion += " Billion ";
    }
    if (numStrLen > 6) {
        numStrIndexMillion = numStrLen - 6;
        numStrIndexMillionMax = numStrIndexMillion + 3;
        million = numStr.substring(numStrIndexMillion, numStrIndexMillionMax);
        million = convertHundreds(million);
        million += " Million ";
    }
    if (numStrLen > 3) {
        numStrIndexThousand = numStrLen - 3;
        numStrIndexThousandMax = numStrIndexThousand + 3;
        thousand = numStr.substring(numStrIndexThousand, numStrIndexThousandMax);
        thousand = convertHundreds(thousand);
        thousand += " Thousand ";
    }
    numStrIndex = numStrIndexMax;
    numStrIndexMax = numStrIndex + 3;
    hundred = numStr.substring(numStrIndex, numStrIndexMax);
    hundred = convertHundreds(hundred);
    result = billion + million + thousand + hundred;
    return result;
};