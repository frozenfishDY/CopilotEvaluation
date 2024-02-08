
import json
import re
import os
import random
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
def flatten_nested_list(nested_list):
    flat_list = []
    for item in nested_list:
        if isinstance(item, list):
            flat_list.extend(flatten_nested_list(item))
        else:
            flat_list.append(item)
    return flat_list


def java_regexMatch():
    new_ref_java_json_list=[]
    with open ("ReferenceCodeCrawler\\referenceText.jsonl","r+",encoding="utf-8") as f:
        ref_content=f.readlines()
    for i in range(len(ref_content)):
       
        ref_json_obj=json.loads(ref_content[i])
        id=ref_json_obj["Question_id"]
        java_code_list=[]
        for item in ref_json_obj['ref_java']:
            java_code_list.append(item["code"])
        filtered_java_code_list=[]
        for item in java_code_list:
            pattern = re.compile(r'class\s+Solution\s+{.*?}',re.DOTALL)
            matches = pattern.findall(item)
            filtered_matches = [match for match in matches if 'public:' not in match and 'def' not in match]
            if filtered_matches:
                filtered_java_code_list.append(filtered_matches[0])
            else:
                filtered_java_code_list.append("None")
        new_json_boj={"id":str(id),"ref_java":filtered_java_code_list}
        new_ref_java_json_list.append(new_json_boj)

    with open("Refiner\\reference_java.jsonl","w",encoding="utf-8") as f:
        for item in new_ref_java_json_list:
            f.write(json.dumps(item) + '\n')

def process_ref_java_jsonl():    
    new_ref_json_obj_list1=[]
    with open ("crystalBLEU\\reference_java.jsonl","r+",encoding="utf-8") as f:
        ref_content=f.readlines()
    for i in range(len(ref_content)):
        ref_json_obj=json.loads(ref_content[i])
        ref_java_list=ref_json_obj["ref_java"]
        if all(x =="None" for x in ref_java_list):
            #print(ref_json_obj["id"])
            with open ("crystalBLEU\\null_java.jsonl","r+",encoding="utf-8") as f:
                    null_content=f.readlines()
            for null_item in null_content:
                null_json_obj=json.loads(null_item)
                if null_json_obj["id"].strip()==ref_json_obj["id"].strip():
                    for i in range(len(ref_java_list)):
                        ref_java_list[i]=null_json_obj["code"]
                        ref_json_obj["ref_java"]=ref_java_list
                    break
        new_ref_json_obj_list1.append(ref_json_obj)
    
    new_ref_json_obj_list2=[]
    ref_content=new_ref_json_obj_list1
    for i in range(len(ref_content)):
        ref_json_obj=json.loads(ref_content[i])
        ref_java_list=ref_json_obj["ref_java"]
        if "None" in ref_java_list:
            no_none_list = [value for value in ref_java_list if value != "None"]
            for i in range(len(ref_java_list)):
                if ref_java_list[i] == "None":
                    ref_java_list[i] = random.choice(no_none_list)
            ref_json_obj["ref_java"]=ref_java_list
        new_ref_json_obj_list2.append(ref_json_obj)


    new_ref_json_obj_list3=[]
    ref_content=new_ref_json_obj_list2
    for i in range(len(ref_content)):
        ref_json_obj=json.loads(ref_content[i])
        id=ref_json_obj["id"]
        ref_java_list=ref_json_obj["ref_java"]
        code_java_list=flatten_nested_list(ref_java_list)
        for j in range(len(code_java_list)):
            code_java_list[j]=removeContents(code_java_list[j],"java")
        if len(code_java_list)==1:
            code_java_list=code_java_list*3
        elif len(code_java_list)==2:
            code_java_list.append(random.choice(code_java_list))
        new_ref_json_obj={"id":id,"ref_java":code_java_list}
        new_ref_json_obj_list3.append(new_ref_json_obj)
    
    with open ("Refiner\\reference_java.jsonl","w",encoding="utf-8") as f:
        for item in new_ref_json_obj_list3:
            f.write(json.dumps(item) + '\n')

def c_regexMatch():
    
    with open ("ReferenceCodeCrawler\referenceText.jsonl","r+",encoding="utf-8") as f:
        ref_content=f.readlines()

    with open ("ReferenceCodeCrawler\hypothesis_c.jsonl","r+",encoding="utf-8") as f:
        hypo_content=f.readlines()

    new_ref_json_obj_list=[]
    if len(ref_content)!=len(hypo_content):
        print("ref hypo length not match")
        return
    
    for i in range(len(ref_content)):
        ref_line=ref_content[i]
        hypo_line=hypo_content[i]
        ref_json_obj=json.loads(ref_line)
        hypo_json_obj=json.loads(hypo_line)
        if str(ref_json_obj["Question_id"]).strip()!=hypo_json_obj["id"]:
            print("id not match"+" "+str(ref_json_obj["Question_id"]).strip()+" "+hypo_json_obj["id"])
            return
        else:
            id=hypo_json_obj["id"]
            #link=ref_json_obj["Question_link"]
            new_ref_code=[]
            prefix=hypo_json_obj["prefix"]
            ref_obj_list=ref_json_obj["ref_c"]
            for ref_obj in ref_obj_list:
                code=ref_obj["code"]
                pattern_str = rf"{re.escape(prefix)}.*?}}"
                pattern = re.compile(pattern_str)
                # 使用re.findall()函数提取匹配的子串
                matches = pattern.findall(code)
                if matches:
                    new_ref_code.append(matches)
                else:
                    new_ref_code.append("None")
    
            new_json_obj={"id":id,"ref_c":new_ref_code}
            new_ref_json_obj_list.append(new_json_obj)
    
    with open("Refiner\\reference_c.jsonl","w",encoding="utf-8") as f:
        for item in new_ref_json_obj_list:
            f.write(json.dumps(item) + '\n')

def process_ref_c_json():
   
    new_ref_json_obj_list1=[]
    with open ("Refiner\\reference_c.jsonl","r+",encoding="utf-8") as f:
        ref_content=f.readlines()
        for line in ref_content:
            ref_json_obj=json.loads(line)
            ref_c_list=ref_json_obj["ref_c"]
            if len(ref_c_list)==3 and all(x =="None" for x in ref_c_list):
                with open ("crystalBLEU\\null.jsonl","r+",encoding="utf-8") as f:
                    null_content=f.readlines()
                for null_item in null_content:
                    null_json_obj=json.loads(null_item)
                    if null_json_obj["id"]==ref_json_obj["id"]:
                        for i in range(len(ref_c_list)):
                            ref_c_list[i]=null_json_obj["code"]
                        ref_json_obj["ref_c"]=ref_c_list
                        break
            new_ref_json_obj_list1.append(ref_json_obj)
        
    new_ref_json_obj_list2=[]
    ref_content=new_ref_json_obj_list1
    for line in ref_content:
        ref_json_obj=json.loads(line)
        ref_c_list=ref_json_obj["ref_c"]
        if len(ref_c_list)==3 and "None" in ref_c_list:
            no_none_list = [value for value in ref_c_list if value != "None"]
            for i in range(len(ref_c_list)):
                if ref_c_list[i] == "None":
                    ref_c_list[i] = random.choice(no_none_list)
            ref_json_obj["ref_c"]=ref_c_list
        new_ref_json_obj_list2.append(ref_json_obj)
    
   
    new_ref_json_obj_list3=[]
    ref_content=new_ref_json_obj_list2
    for line in ref_content:
        ref_json_obj=json.loads(line)
        ref_c_list=ref_json_obj["ref_c"]
        if len(ref_c_list)==2 and "None" in ref_c_list and not all(x =="None" for x in ref_c_list):
            no_none_list = [value for value in ref_c_list if value != "None"]
            new__list=[no_none_list[0],no_none_list[0],no_none_list[0]]
            ref_json_obj["ref_c"]=new__list
        new_ref_json_obj_list3.append(ref_json_obj)
    
    
    new_ref_json_obj_list4=[]
    ref_content=new_ref_json_obj_list3
    for i in range(len(ref_content)):
        ref_json_obj=json.loads(ref_content[i])
        ref_code_list=ref_json_obj["ref_c"]
        flag=(len(ref_code_list)==1 or len(ref_code_list)==2) and "None" in ref_code_list and all(x =="None" for x in ref_code_list)
        if (len(ref_code_list)==0) or flag:
            print(ref_json_obj["id"])
            random_index=random.randrange(0,i-1)
            last_json_obj=new_ref_json_obj_list4[random_index]
            ref_code_list=last_json_obj["ref_c"]
            ref_json_obj["ref_c"]=ref_code_list
        new_ref_json_obj_list4.append(ref_json_obj)
    
    
    new_ref_json_obj_list5=[]
   
    ref_content=new_ref_json_obj_list4
    for line in ref_content:
        ref_json_obj=json.loads(line)
        ref_c_list=ref_json_obj["ref_c"]
        if len(ref_c_list)<3:
            extension_length=3
            new_list=[]
            for _ in range(extension_length):
                random_element=random.choice(ref_c_list)
                new_list.append(random_element)
            ref_json_obj["ref_c"]=new_list
        new_ref_json_obj_list5.append(ref_json_obj)
    
    with open("Refiner\\reference_c.jsonl","w",encoding="utf-8") as f:
        for item in new_ref_json_obj_list5:
            f.write(json.dumps(item) + '\n')

def extract_js_jsonl():
    new_json_obj_list=[]
    with open ("ReferenceCodeCrawler\\referenceText.jsonl","r+",encoding="utf-8") as f:
        json_content=f.readlines()
    for i in range (len(json_content)):
        json_obj=json.loads(json_content[i])
        id=str(json_obj["Question_id"])
        js_code_list=[]
        for code_obj in json_obj["ref_javascript"]:
            js_code_list.append(code_obj["code"])
        filtered_js_code_list=[]
        for code in js_code_list:
            pattern = re.compile(r'var\s+\w+\s*=\s*function\s*.*{.*?};', re.DOTALL)
            subpattern=re.compile(r'.*?};')
            matches = pattern.findall(code)
            for i in range(len(matches)):
                submatches=subpattern.findall(matches[i])
                for j in range(len(submatches)):
                    if submatches[j].startswith("var"):
                        #print(submatches[j])
                        filtered_js_code_list.append(submatches[j])
        new_json_obj={"id":id,"ref_js":filtered_js_code_list}
        new_json_obj_list.append(new_json_obj)
    
    with open ("Refiner\\reference_js.jsonl","w",encoding="utf-8") as f:
        for item in new_json_obj_list:
            f.write(json.dumps(item) + '\n')




def process_ref_js_jsonl():

    #step1 split nested list
    new_json_obj_list1=[]
    with open("Refiner\\reference_js.jsonl","r+",encoding="utf-8") as f:
        json_content=f.readlines()
    for i in range(len(json_content)):
        json_obj=json.loads(json_content[i])
        id=json_obj["id"]     
        ref_js_list=json_obj["ref_js"]
        code_js_list=flatten_nested_list(ref_js_list)
        if len(code_js_list)==0:
            random_index=random.randrange(0,i-1)
            last_json_obj=new_json_obj_list1[random_index]
            code_js_list=last_json_obj["ref_js"]
        elif len(code_js_list)==1:
            code_js_list=code_js_list*3
        elif len(code_js_list)==2:
            code_js_list.append(random.choice(code_js_list))
        elif len(code_js_list)>3:
            print(" length error"+id)
        
        for j in range (len(code_js_list)):
            code_js_list[j]=removeContents(code_js_list[j],"js")
        new_json_obj={"id":id,"ref_js":code_js_list}
        new_json_obj_list1.append(new_json_obj)
    
    with open ("Refiner\\reference_js.jsonl","w",encoding="utf-8") as f:
        for item in new_json_obj_list1:
            f.write(json.dumps(item) + '\n')

def extract_py_jsonl():
    new_json_obj_list=[]
    with open ("ReferenceCodeCrawler\referenceText.jsonl","r+",encoding="utf-8") as f:
        json_content=f.readlines()
    for i in range(len(json_content)):
        json_obj=json.loads(json_content[i])
        id=str(json_obj["Question_id"])
        code_json_list=json_obj["ref_python"]
        match_code_list=[]
        for code in code_json_list:
            py_code=code["code"]
            pattern = re.compile(r'def.*?return.*\\n\\n?', re.DOTALL)
            matches = pattern.findall(py_code)
            match_code_list+=flatten_nested_list(matches)
        last_code_list=[]
        for i in range(len(match_code_list)):
            original_string=match_code_list[i]
            substring = original_string[:original_string.find("\\n\\n")]
            last_code_list.append(substring)
            if len(last_code_list)==3:
                break
        new_json_obj={"id":id,"ref_py":last_code_list}
        new_json_obj_list.append(new_json_obj)
    
    with open("Refiner\\reference_py.jsonl","w",encoding="utf-8") as f:
        for item in new_json_obj_list:
            f.write(json.dumps(item) + '\n')

def process_ref_py_jsonl():
    with open("Refiner\\reference_py.jsonl","r+",encoding="utf-8") as f:
        ref_content=f.readlines()
    new_json_obj_list1=[]
    for i in range(len(ref_content)):
        json_obj=json.loads(ref_content[i])
        ref_py_list=json_obj["ref_py"]
        if len(ref_py_list)==0:
            random_index=random.randrange(0,i-1)
            last_json_obj=new_json_obj_list1[random_index]
            ref_py_list=last_json_obj["ref_py"]
        elif len(ref_py_list)==1:
            ref_py_list=ref_py_list*3
        elif len(ref_py_list)==2:
            ref_py_list.append(random.choice(ref_py_list))
        print(len(ref_py_list))
        for j in range(len(ref_py_list)):
            ref_py_list[j]=removeContents(ref_py_list[j],"py")
        json_obj["ref_py"]=ref_py_list
        new_json_obj_list1.append(json_obj)
    
    with open ("crystalBLEU\\new_reference_py_1.jsonl","w",encoding="utf-8") as f:
        for item in new_json_obj_list1:
            f.write(json.dumps(item) + '\n')
  

def refineCCode():
    c_regexMatch()
    process_ref_c_json()

def refineJavaCode():
    java_regexMatch()
    process_ref_java_jsonl()

def refineJSCode():
    extract_js_jsonl()
    process_ref_js_jsonl()

def refinePyCode():
    extract_py_jsonl()
    process_ref_py_jsonl()

def main():
    refineCCode()
    refineJavaCode()
    refineJSCode()
    refinePyCode()
main()




