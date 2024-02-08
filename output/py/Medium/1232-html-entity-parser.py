#https://leetcode.com/problems/html-entity-parser/
#HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.
#The special characters and their entities for HTML are:
#Quotation Mark: the entity is &quot; and symbol character is ".
#Single Quote Mark: the entity is &apos; and symbol character is '.
#Ampersand: the entity is &amp; and symbol character is &.
#Greater Than Sign: the entity is &gt; and symbol character is >.
#Less Than Sign: the entity is &lt; and symbol character is <.
#Slash: the entity is &frasl; and symbol character is /.
#Given the input text string to the HTML parser, you have to implement the entity parser.
#Return the text after replacing the entities by the special characters.


class Solution(object):
    def entityParser(self, text):
        """
        :type text: str
        :rtype: str
        """    
        # 1. Create a dictionary of entities
        # 2. Loop through the string
        # 3. If the current character is & and the next 6 characters are in the dictionary, then replace the string with the value of the dictionary
        # 4. Return the string
        entities = {
            "&quot;": "\"",
            "&apos;": "'",
            "&amp;": "&",
            "&gt;": ">",
            "&lt;": "<",
            "&frasl;": "/"
        }
        for i in range(len(text)):
            if text[i] == "&" and text[i:i+6] in entities:
                text = text[:i] + entities[text[i:i+6]] + text[i+6:]
        return text

        

    