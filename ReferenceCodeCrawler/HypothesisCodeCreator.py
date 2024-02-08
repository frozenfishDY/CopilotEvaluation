import json
import re
import os
import random
import ast
from natsort import natsorted
def removeContents(code,lan):
    if lan != "py":
        # remove Multi-line comments
        code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)

        # remove single line comment
        code = re.sub(r'//.*', '', code)

        return code
    else:
        # remove Multi-line comments
        code = re.sub(r'\"\"\".*?\"\"\"', '', code, flags=re.DOTALL)

        # remove single line comment
        code = re.sub(r'#.*', '', code)

        return code
def extractJSONfromOutput(folderPath):
    lan=folderPath.split("\\")[1]
    #create file path list
    easy_path=folderPath+"\\Easy"
    medium_path=folderPath+"\\Medium"
    hard_path=folderPath+"\\Hard"
    hypothesis_file_list=[]
    easy_file_list=[easy_path+"\\"+x for x in natsorted(os.listdir(easy_path))]
    medium_file_list=[medium_path+"\\"+x for x in natsorted(os.listdir(medium_path))]
    hard_file_list=[hard_path+"\\"+x for x in natsorted(os.listdir(hard_path))]
    hypothesis_file_list=easy_file_list+medium_file_list+hard_file_list
    json_obj_list=[]

    #create json list and write to jsonl file
    for path in hypothesis_file_list:
        with open (path,"r+",encoding="utf-8") as f:
            hypothesis_code=f.read()
            #remove comments
        hypothesis_code=removeContents(hypothesis_code,lan).strip()
        id=path.split("\\")[3].split("-")[0]
        json_obj={"id":id,"path":path,"hypo_code":hypothesis_code}
        json_obj_list.append(json_obj)
    
    
    with open ("ReferenceCodeCrawler\\hypothesis_"+lan+".jsonl","w",encoding="utf-8") as f:
        for item in json_obj_list:
            f.write(json.dumps(item) + '\n')




def main():
    c_folderPath="output\c"
    java_folderPath="output\java"
    js_folderPath="output\javascript"
    python_folderPath="output\python"
    extractJSONfromOutput(c_folderPath)
    extractJSONfromOutput(java_folderPath)
    extractJSONfromOutput(js_folderPath)
    extractJSONfromOutput(python_folderPath)

main()