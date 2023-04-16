/**https://leetcode.com/problems/repeated-dna-sequences/ */
//The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
//For example, "ACGAATTCCG" is a DNA sequence.
//When studying DNA, it is useful to identify repeated sequences within the DNA.
//Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.


class RepeatedDnaSequences {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> seen = new HashSet<>();
        Set<String> res = new HashSet<>();
        for(int i = 0; i + 10 <= s.length(); i++){
            String sub = s.substring(i, i + 10);
            if(seen.contains(sub)){
                res.add(sub);
            }
            seen.add(sub);
        }
        return new ArrayList<>(res);
        
    }
}

    