# coding=utf-8
import random
import re
import requests
from lxml import etree
import openpyxl
from bs4 import BeautifulSoup
import time
from DrissionPage import ChromiumPage, web_page, ChromiumOptions
import pandas as pd

proxies = {
   "http": "http://127.0.0.1:7890",
   "https": "http://127.0.0.1:7890",
}
import requests
import json



def crawler():
        headers = {
            "authority": "leetcode.com",
            "accept": "*/*",
            "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
            "authorization": "",
            "cache-control": "no-cache",
            "content-type": "application/json",
            "origin": "https://leetcode.com",
            "pragma": "no-cache",
            "random-uuid": "99ff4a67-830d-6a2f-9be2-d39cb4ebd057",
            "referer": "https://leetcode.com/problems/determine-if-string-halves-are-alike/",
            "sec-ch-ua": "\"Not/A)Brand\";v=\"99\", \"Microsoft Edge\";v=\"115\", \"Chromium\";v=\"115\"",
            "sec-ch-ua-mobile": "?0",
            "sec-ch-ua-platform": "\"Windows\"",
            "sec-fetch-dest": "empty",
            "sec-fetch-mode": "cors",
            "sec-fetch-site": "same-origin",
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/115.0.0.0 Safari/537.36 Edg/115.0.1901.203",
            "uuuserid": "e81b95bfdfa2bbcc29826787612630f2",
            "x-csrftoken": "9JQJ3T4SA9EZRL28q0SPI0CXqAjcbhccJ4hX5EbjuV5Wy0ttOQdBjEu9V3kG02Pw"
        }
        cookies = {
            "csrftoken": "9JQJ3T4SA9EZRL28q0SPI0CXqAjcbhccJ4hX5EbjuV5Wy0ttOQdBjEu9V3kG02Pw",
            "_gid": "GA1.2.961319558.1692529146",
            "gr_user_id": "d59f7352-f4ac-4166-853a-44aed1215bad",
            "87b5a3c3f1a55520_gr_session_id": "d4fda777-f722-4474-92ea-4242184eb5d6",
            "87b5a3c3f1a55520_gr_session_id_sent_vst": "d4fda777-f722-4474-92ea-4242184eb5d6",
            "_ga_CDRWKZTDEX": "GS1.1.1692538876.3.0.1692538876.60.0.0",
            "_ga": "GA1.2.1717022445.1692529146",
            "_gat": "1",
            "_dd_s": "rum=0&expire=1692539776568"
        }
        df=pd.read_excel('Links  .xlsx')
        link=df['Link'].to_list()
        difficulty=df['Difficulty'].to_list()
        # description=df['Description'].to_list()
        df2=pd.DataFrame(columns=['Link','Difficulty','Description','C'	,'Java'	,'JavaScript',	'Python'])
        url = "https://leetcode.com/graphql/"
        data = {
            "query": "\n    query questionEditorData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    codeSnippets {\n      lang\n      langSlug\n      code\n    }\n    envInfo\n    enableRunCode\n  }\n}\n    ",
            "variables": {
                "titleSlug": ""
            },
            "operationName": "questionEditorData"
        }
        data_question = {
            "query": "\n    query questionContent($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    content\n    mysqlSchemas\n    dataSchemas\n  }\n}\n    ",
            "variables": {
                "titleSlug": ""
            },
            "operationName": "questionContent"
        }
        for diff,l in zip(difficulty,link):
            title=l.replace('https://leetcode.com/problems/','').replace('/','')
            print(title,'====')
            data['variables']['titleSlug']=title
            data_question['variables']['titleSlug'] = title
            data = json.dumps(data, separators=(',', ':'))
            data_question = json.dumps(data_question, separators=(',', ':'))
            while True:

                try:
                    response = requests.post(url, headers=headers, data=data,timeout=10)
                    break
                except Exception as e:
                    print(e)
                    time.sleep(0.5)
                    print('continue')
                    continue

            time.sleep(0.3)


            json_data=response.json()
            codeSnippets=json_data['data']['question']['codeSnippets']
            lang_lst=['C','Java','JavaScript','Python']
            d={}
            if codeSnippets is None:
                data = json.loads(data)
                data_question = json.loads(data_question)
                continue
            for i in codeSnippets:

                if i['lang'] in lang_lst:
                    if i['lang']!='Python3':
                        d[i['lang']]=i['code']
            d['Link']=l
            d['Difficulty']=diff
            try:
                response = requests.post(url, headers=headers, cookies=cookies, data=data_question,timeout=15)

            except:
                time.sleep(0.5)
                response = requests.post(url, headers=headers, cookies=cookies, data=data_question)

            time.sleep(0.5)
            content=response.json()['data']['question']['content']
            ee=etree.HTML(content)
            code_text=ee.xpath("//text()")
            des=''.join(code_text)
            d['Description']=des
            print(d)
            data = json.loads(data)
            data_question = json.loads(data_question)
            df2=df2._append(d,ignore_index=True)
            df2.to_excel('data.xlsx',index=False)
            time.sleep(1)

def creator(filePath):
   raw_data=pd.read_excel(filePath,header=0)
   data=raw_data.values
   for i in range(len(data)):
      extract(data[i])

def extract(data):
   index=data[0]
   url=data[1]
   difficulty=data[2]
   desc=data[3]
   c_func=str(data[4])
   java_func=str(data[5])
   js_func=str(data[6])
   py_func=str(data[7])
   prefix="https://leetcode.com/problems/"
   fileName=str(index)+'-'+url[len(prefix):len(url)-1]
   
   path_dict={".c":"output1/c/"+difficulty+"/",".java":"output1/java/"+difficulty+"/",".js":"output1/javascript/"+difficulty+"/",".py":"output1/python/"+difficulty+"/"}
   content_dict={".c":c_func,".java":java_func,".js":js_func,".py":py_func}
   for key,value in content_dict.items():
      filepath=path_dict[key]+fileName+key
      with open(filepath,'w',encoding="utf-8") as f:
         if key==".py":
            f.write("#"+url+"\n")
            for comment in desc.splitlines():
               if comment !="":
                  comment_string="#"+comment+"\n"
                  f.write(comment_string)
         else:
            f.write("/**"+url+" */"+"\n")
            for comment in desc.splitlines():
               if comment !="":
                  comment_string="//"+comment+"\n"
                  f.write(comment_string)
         f.write(value)
   print(str(index)+" "+url+"    done")



def main():
    #Setp1: Crawl all questions in all LeetCode
    #crawler()
    #Setp2:Please make sure all issues are crawled before calling creator()
    creator("D:\LeetCodeCrawler\GitMaterial\AllData.xlsx")

main()
      
