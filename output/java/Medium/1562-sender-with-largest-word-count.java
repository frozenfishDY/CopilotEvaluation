/**https://leetcode.com/problems/sender-with-largest-word-count/ */
//You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].
//A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number of words sent by the sender. Note that a sender may send more than one message.
//Return the sender with the largest word count. If there is more than one sender with the largest word count, return the one with the lexicographically largest name.
//Note:
//Uppercase letters come before lowercase letters in lexicographical order.
//"Alice" and "alice" are distinct.


class SenderWithLargestWordCount {
    public String largestWordCount(String[] messages, String[] senders) {
        Map<String, Integer> count = new HashMap<>();
        for (int i = 0; i < messages.length; i++) {
            String[] words = messages[i].split(" ");
            count.put(senders[i], count.getOrDefault(senders[i], 0) + words.length);
        }
        String result = "";
        int max = 0;
        for (String sender : count.keySet()) {
            if (count.get(sender) > max) {
                result = sender;
                max = count.get(sender);
            } else if (count.get(sender) == max) {
                result = result.compareTo(sender) < 0 ? result : sender;
            }
        }
        return result;
        
    }
}
     
    