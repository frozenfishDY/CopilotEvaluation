# coding=utf8
# 2333333
import requests
import json
import math
import pandas as pd
import time
df=pd.read_excel('Links.xlsx')
lst_link=df['Link'].to_list()
lst_index=df['Index'].to_list()

def crawltime():
    headers = {
        "authority": "leetcode.com",
        "accept": "*/*",
        "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
        "cache-control": "no-cache",
        "content-type": "application/json",
        "origin": "https://leetcode.com",
        "pragma": "no-cache",
        "referer": "https://leetcode.com/problems/palindrome-number/discuss/?currentPage=1&orderBy=hot&query=",
        "sec-ch-ua": "\"Not_A Brand\";v=\"8\", \"Chromium\";v=\"120\", \"Microsoft Edge\";v=\"120\"",
        "sec-ch-ua-mobile": "?0",
        "sec-ch-ua-platform": "\"Windows\"",
        "sec-fetch-dest": "empty",
        "sec-fetch-mode": "cors",
        "sec-fetch-site": "same-origin",
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0",
        "x-csrftoken": "44jmiKDhw1b7MKa6XUtkcAr63mwkMydI49pFXPB1vmCMzOw6gEUY3YoKyGixwdqU",
        "x-newrelic-id": "UAQDVFVRGwIBVFFQDgIHXlM="
    }
    cookies = {
        "gr_user_id": "dc04171b-2b8a-437a-bd67-acc2b816d16d",
        "csrftoken": "44jmiKDhw1b7MKa6XUtkcAr63mwkMydI49pFXPB1vmCMzOw6gEUY3YoKyGixwdqU",
        "87b5a3c3f1a55520_gr_last_sent_cs1": "smingstudent",
        "LEETCODE_SESSION": "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJhY2NvdW50X3ZlcmlmaWVkX2VtYWlsIjpudWxsLCJfYXV0aF91c2VyX2lkIjoiMTE4MTcyNzUiLCJfYXV0aF91c2VyX2JhY2tlbmQiOiJhbGxhdXRoLmFjY291bnQuYXV0aF9iYWNrZW5kcy5BdXRoZW50aWNhdGlvbkJhY2tlbmQiLCJfYXV0aF91c2VyX2hhc2giOiI3MTgwZTUwOWEwZGU2ZmNhZTJjZThlNmQ3N2FmYWZjY2VkOWJjMTEyMGQ0ZDBhYjc5NzRiYmUzMzQxNTVkZmIwIiwiaWQiOjExODE3Mjc1LCJlbWFpbCI6InNtaW5nc3R1ZGVudEBnbWFpbC5jb20iLCJ1c2VybmFtZSI6InNtaW5nc3R1ZGVudCIsInVzZXJfc2x1ZyI6InNtaW5nc3R1ZGVudCIsImF2YXRhciI6Imh0dHBzOi8vYXNzZXRzLmxlZXRjb2RlLmNvbS91c2Vycy9kZWZhdWx0X2F2YXRhci5qcGciLCJyZWZyZXNoZWRfYXQiOjE3MDM0NzIzNjYsImlwIjoiMjEwLjIxLjc5LjIzOSIsImlkZW50aXR5IjoiY2U1OGE1MjYwYmE0ZmE5Y2RlZGY0ODg2ZTRjZjQ1YzYiLCJzZXNzaW9uX2lkIjo1MjE0NTEwNn0.v0BVjffY5Rv8FOFU0Z_jziALfxqQN5QecV45x5yfLgY",
        "_gid": "GA1.2.705629070.1703472367",
        "_gat": "1",
        "87b5a3c3f1a55520_gr_session_id": "a1828f83-bca7-4f6a-85ef-4e733083d59a",
        "87b5a3c3f1a55520_gr_last_sent_sid_with_cs1": "a1828f83-bca7-4f6a-85ef-4e733083d59a",
        "87b5a3c3f1a55520_gr_cs1": "smingstudent",
        "87b5a3c3f1a55520_gr_session_id_sent_vst": "a1828f83-bca7-4f6a-85ef-4e733083d59a",
        "_dd_s": "rum=0&expire=1703550431343",
        "c_a_u": "c21pbmdzdHVkZW50:1rHv3Q:E_kSLDqW97PZ0wC4ycbcke8LGqwfa1crhENxE38_K30",
        "_ga": "GA1.1.1208363238.1703245212",
        "_ga_CDRWKZTDEX": "GS1.1.1703549514.10.1.1703549538.36.0.0"
    }

    for dict_index,link in zip(lst_index[788:],lst_link[788:]):
        url = "https://leetcode.com/graphql"

        dict1 = {}
        questionSlug = link[:-1].split('/')[-1]
        print(questionSlug, '==')

        dict1['Question_id'] = dict_index

        dict1['Question_name'] = questionSlug
        dict1['Question_link'] = link
        data_id = {
            "operationName": "questionData",
            "variables": {
                "titleSlug": questionSlug
            },
            "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    canSeeQuestion\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    exampleTestcases\n    categoryTitle\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      paidOnly\n      hasVideoSolution\n      paidOnlyVideo\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    enableDebugger\n    envInfo\n    libraryUrl\n    adminUrl\n    challengeQuestion {\n      id\n      date\n      incompleteChallengeCount\n      streakCount\n      type\n      __typename\n    }\n    __typename\n  }\n}\n"
        }
        data_id = json.dumps(data_id, separators=(',', ':'))
        response = requests.post(url, headers=headers, cookies=cookies, data=data_id)
        questionId = response.json()['data']['question']['questionId']
        print(questionId)

        data = {
            "operationName": "questionTopicsList",
            "variables": {
                "orderBy": "newest_to_oldest",
                "query": "",
                "skip": 0,
                "first": 15,
                "tags": [],
                "questionId": str(questionId)
            },
            "query": "query questionTopicsList($questionId: String!, $orderBy: TopicSortingOption, $skip: Int, $query: String, $first: Int!, $tags: [String!]) {\n  questionTopicsList(questionId: $questionId, orderBy: $orderBy, skip: $skip, query: $query, first: $first, tags: $tags) {\n    ...TopicsList\n    __typename\n  }\n}\n\nfragment TopicsList on TopicConnection {\n  totalNum\n  edges {\n    node {\n      id\n      title\n      commentCount\n      viewCount\n      pinned\n      tags {\n        name\n        slug\n        __typename\n      }\n      post {\n        id\n        voteCount\n        creationDate\n        isHidden\n        author {\n          username\n          isActive\n          nameColor\n          activeBadge {\n            displayName\n            icon\n            __typename\n          }\n          profile {\n            userAvatar\n            __typename\n          }\n          __typename\n        }\n        status\n        coinRewards {\n          ...CoinReward\n          __typename\n        }\n        __typename\n      }\n      lastComment {\n        id\n        post {\n          id\n          author {\n            isActive\n            username\n            __typename\n          }\n          peek\n          creationDate\n          __typename\n        }\n        __typename\n      }\n      __typename\n    }\n    cursor\n    __typename\n  }\n  __typename\n}\n\nfragment CoinReward on ScoreNode {\n  id\n  score\n  description\n  date\n  __typename\n}\n"
        }
        data = json.dumps(data, separators=(',', ':'))
        response = requests.post(url, headers=headers, cookies=cookies, data=data)

        time.sleep(0.5)
        totalNum = response.json()['data']['questionTopicsList']['totalNum']
        lst_page = math.floor(totalNum / 15) * 15
        print(lst_page)
        data = {
            "operationName": "questionTopicsList",
            "variables": {
                "orderBy": "newest_to_oldest",
                "query": "",
                "skip": lst_page,
                "first": 15,
                "tags": [],
                "questionId": str(questionId)
            },
            "query": "query questionTopicsList($questionId: String!, $orderBy: TopicSortingOption, $skip: Int, $query: String, $first: Int!, $tags: [String!]) {\n  questionTopicsList(questionId: $questionId, orderBy: $orderBy, skip: $skip, query: $query, first: $first, tags: $tags) {\n    ...TopicsList\n    __typename\n  }\n}\n\nfragment TopicsList on TopicConnection {\n  totalNum\n  edges {\n    node {\n      id\n      title\n      commentCount\n      viewCount\n      pinned\n      tags {\n        name\n        slug\n        __typename\n      }\n      post {\n        id\n        voteCount\n        creationDate\n        isHidden\n        author {\n          username\n          isActive\n          nameColor\n          activeBadge {\n            displayName\n            icon\n            __typename\n          }\n          profile {\n            userAvatar\n            __typename\n          }\n          __typename\n        }\n        status\n        coinRewards {\n          ...CoinReward\n          __typename\n        }\n        __typename\n      }\n      lastComment {\n        id\n        post {\n          id\n          author {\n            isActive\n            username\n            __typename\n          }\n          peek\n          creationDate\n          __typename\n        }\n        __typename\n      }\n      __typename\n    }\n    cursor\n    __typename\n  }\n  __typename\n}\n\nfragment CoinReward on ScoreNode {\n  id\n  score\n  description\n  date\n  __typename\n}\n"
        }
        data = json.dumps(data, separators=(',', ':'))
        response = requests.post(url, headers=headers, cookies=cookies, data=data)
        time.sleep(0.8)
        try:
            timestamp=response.json()["data"]["questionTopicsList"]["edges"][-1]["node"]["post"]["creationDate"]
        except:
            data = {
                "operationName": "questionTopicsList",
                "variables": {
                    "orderBy": "newest_to_oldest",
                    "query": "",
                    "skip": lst_page-15,
                    "first": 15,
                    "tags": [],
                    "questionId": str(questionId)
                },
                "query": "query questionTopicsList($questionId: String!, $orderBy: TopicSortingOption, $skip: Int, $query: String, $first: Int!, $tags: [String!]) {\n  questionTopicsList(questionId: $questionId, orderBy: $orderBy, skip: $skip, query: $query, first: $first, tags: $tags) {\n    ...TopicsList\n    __typename\n  }\n}\n\nfragment TopicsList on TopicConnection {\n  totalNum\n  edges {\n    node {\n      id\n      title\n      commentCount\n      viewCount\n      pinned\n      tags {\n        name\n        slug\n        __typename\n      }\n      post {\n        id\n        voteCount\n        creationDate\n        isHidden\n        author {\n          username\n          isActive\n          nameColor\n          activeBadge {\n            displayName\n            icon\n            __typename\n          }\n          profile {\n            userAvatar\n            __typename\n          }\n          __typename\n        }\n        status\n        coinRewards {\n          ...CoinReward\n          __typename\n        }\n        __typename\n      }\n      lastComment {\n        id\n        post {\n          id\n          author {\n            isActive\n            username\n            __typename\n          }\n          peek\n          creationDate\n          __typename\n        }\n        __typename\n      }\n      __typename\n    }\n    cursor\n    __typename\n  }\n  __typename\n}\n\nfragment CoinReward on ScoreNode {\n  id\n  score\n  description\n  date\n  __typename\n}\n"
            }
            data = json.dumps(data, separators=(',', ':'))
            response = requests.post(url, headers=headers, cookies=cookies, data=data)
            timestamp=response.json()["data"]["questionTopicsList"]["edges"][-1]["node"]["post"]["creationDate"]

            time.sleep(0.8)
        timeArray = time.localtime(timestamp)
        date = time.strftime("%Y-%m-%d %H:%M:%S", timeArray)
        post_id=response.json()["data"]["questionTopicsList"]["edges"][-1]["node"]["id"]
        url=f'https://leetcode.com/problems/{questionSlug}/discuss/{post_id}'
        dict1['post_date']=date
        dict1['post_url']=url
        with open('ProblemInfoCrawler\\postTime.jsonl','a+',encoding='utf-8') as f:
            json.dump(dict1,f)
            f.write('\n')
        print(url)

def readDateJsonFile():
    datelist=[]
    with open ("ProblemInfoCrawler\postTime.jsonl","r+",encoding="utf-8") as f:
        content=f.readlines()
        for i in range(len(content)):
            json_obj=json.loads(content[i])
            date=json_obj["post_date"].strip()
            date_arr=date.split(" ")
            datelist.append(date_arr[0])
    
    with open("ProblemInfoCrawler\datelist.txt","w",encoding="utf-8") as f:
        for item in datelist:
            f.write(item+"\n")

def main():
    crawltime()
    readDateJsonFile()
