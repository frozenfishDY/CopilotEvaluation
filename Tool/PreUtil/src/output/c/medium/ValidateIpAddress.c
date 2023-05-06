/**https://leetcode.com/problems/validate-ip-address/ */
//Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any type.
//A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255 and xi cannot contain leading zeros. For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and "192.168@1.1" are invalid IPv4 addresses.
//A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8" where:
//1 <= xi.length <= 4
//xi is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English letters ('A' to 'F').
//Leading zeros are allowed in xi.
//For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.


char * validIPAddress(char * queryIP){
    int len = strlen(queryIP);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(queryIP[i] == '.'){
            count++;
        }
    }
    if(count == 3){
        int start = 0;
        int end = 0;
        for(int i = 0; i < len; i++){
            if(queryIP[i] == '.'){
                end = i;
                if(end - start > 3 || end - start == 0){
                    return "Neither";
                }
                if(end - start > 1 && queryIP[start] == '0'){
                    return "Neither";
                }
                int num = 0;
                for(int j = start; j < end; j++){
                    if(queryIP[j] < '0' || queryIP[j] > '9'){
                        return "Neither";
                    }
                    num = num * 10 + (queryIP[j] - '0');
                }
                if(num > 255){
                    return "Neither";
                }
                start = end + 1;
            }
        }
        end = len;
        if(end - start > 3 || end - start == 0){
            return "Neither";
        }
        if(end - start > 1 && queryIP[start] == '0'){
            return "Neither";
        }
        int num = 0;
        for(int j = start; j < end; j++){
            if(queryIP[j] < '0' || queryIP[j] > '9'){
                return "Neither";
            }
            num = num * 10 + (queryIP[j] - '0');
        }
        if(num > 255){
            return "Neither";
        }
        return "IPv4";
    }
    count = 0;
    for(int i = 0; i < len; i++){
        if(queryIP[i] == ':'){
            count++;
        }
    }
    if(count == 7){
        int start = 0;
        int end = 0;
        for(int i = 0; i < len; i++){
            if(queryIP[i] == ':'){
                end = i;
                if(end - start > 4 || end - start == 0){
                    return "Neither";
                }
                for(int j = start; j < end; j++){
                    if((queryIP[j] < '0' || queryIP[j] > '9') && (queryIP[j] < 'a' || queryIP[j] > 'f') && (queryIP[j] < 'A' || queryIP[j] > 'F')){
                        return "Neither";
                    }

}

    