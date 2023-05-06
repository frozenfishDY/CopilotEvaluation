/**https://leetcode.com/problems/reorder-data-in-log-files/ */
//You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.
//There are two types of logs:
//Letter-logs: All words (except the identifier) consist of lowercase English letters.
//Digit-logs: All words (except the identifier) consist of digits.
//Reorder these logs so that:
//The letter-logs come before all digit-logs.
//The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
//The digit-logs maintain their relative ordering.
//Return the final order of the logs.


/**
 * @param {string[]} logs
 * @return {string[]}
 */
var reorderLogFiles = function(logs) {
    let result = [];
    let digitLogs = [];
    let letterLogs = [];
    for(let i = 0; i < logs.length; i++){
        let log = logs[i];
        let index = log.indexOf(' ');
        let identifier = log.substring(0, index);
        let content = log.substring(index + 1);
        if(content[0] >= '0' && content[0] <= '9'){
            digitLogs.push(log);
        }else{
            letterLogs.push({identifier: identifier, content: content});
        }
    }
    letterLogs.sort((a, b) => {
        if(a.content == b.content){
            return a.identifier.localeCompare(b.identifier);
        }
        return a.content.localeCompare(b.content);
    });
    for(let i = 0; i < letterLogs.length; i++){
        result.push(letterLogs[i].identifier + ' ' + letterLogs[i].content);
    }
    for(let i = 0; i < digitLogs.length; i++){
        result.push(digitLogs[i]);
    }
    return result;
    
};

    