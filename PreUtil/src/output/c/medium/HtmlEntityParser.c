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


char * entityParser(char * text){
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;
    char *str;
    str = (char*)malloc(100000 * sizeof(char));
    for(i = 0; i < strlen(text); i++){
        if(text[i] == '&'){
            if(text[i + 1] == 'q' && text[i + 2] == 'u' && text[i + 3] == 'o' && text[i + 4] == 't' && text[i + 5] == ';'){
                str[i] = '"';
                i += 5;
            }
            else if(text[i + 1] == 'a' && text[i + 2] == 'p' && text[i + 3] == 'o' && text[i + 4] == 's' && text[i + 5] == ';'){
                str[i] = '\'';
                i += 5;
            }
            else if(text[i + 1] == 'a' && text[i + 2] == 'm' && text[i + 3] == 'p' && text[i + 4] == ';'){
                str[i] = '&';
                i += 4;
            }
            else if(text[i + 1] == 'g' && text[i + 2] == 't' && text[i + 3] == ';'){
                str[i] = '>';
                i += 3;
            }
            else if(text[i + 1] == 'l' && text[i + 2] == 't' && text[i + 3] == ';'){
                str[i] = '<';
                i += 3;
            }
            else if(text[i + 1] == 'f' && text[i + 2] == 'r' && text[i + 3] == 'a' && text[i + 4] == 's' && text[i + 5] == 'l' && text[i + 6] == ';'){
                str[i] = '/';
                i += 6;
            }
            else{
                str[i] = text[i];
            }
        }
        else{
            str[i] = text[i];
        }
    }
    return str;

}

    