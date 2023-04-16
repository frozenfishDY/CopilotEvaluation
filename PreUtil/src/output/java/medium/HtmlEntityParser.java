/**https://leetcode.com/problems/html-entity-parser/ */
//HTML entity parser is the parser that takes HTML code as input and replace all the entities of the special characters by the characters itself.
//The special characters and their entities for HTML are:
//Quotation Mark: the entity is &quot; and symbol character is ".
//Single Quote Mark: the entity is &apos; and symbol character is '.
//Ampersand: the entity is &amp; and symbol character is &.
//Greater Than Sign: the entity is &gt; and symbol character is >.
//Less Than Sign: the entity is &lt; and symbol character is <.
//Slash: the entity is &frasl; and symbol character is /.
//Given the input text string to the HTML parser, you have to implement the entity parser.
//Return the text after replacing the entities by the special characters.


class HtmlEntityParser {
    public String entityParser(String text) {
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < text.length(); i++){
            if(text.charAt(i) == '&'){
                if(i + 5 < text.length() && text.substring(i, i + 6).equals("&quot;")){
                    sb.append("\"");
                    i += 5;
                }else if(i + 5 < text.length() && text.substring(i, i + 6).equals("&apos;")){
                    sb.append("'");
                    i += 5;
                }else if(i + 4 < text.length() && text.substring(i, i + 5).equals("&amp;")){
                    sb.append("&");
                    i += 4;
                }else if(i + 3 < text.length() && text.substring(i, i + 4).equals("&gt;")){
                    sb.append(">");
                    i += 3;
                }else if(i + 3 < text.length() && text.substring(i, i + 4).equals("&lt;")){
                    sb.append("<");
                    i += 3;
                }else if(i + 6 < text.length() && text.substring(i, i + 7).equals("&frasl;")){
                    sb.append("/");
                    i += 6;
                }else{
                    sb.append(text.charAt(i));
                }
            }else{
                sb.append(text.charAt(i));
            }
        }
        return sb.toString();
        
        
    }
}

    