# coding=utf8
# 2333333
import time

import requests
import json
import pandas as pd

df=pd.read_excel('Links.xlsx')
lst_link=df['Link'].to_list()
lst_index=df['Index'].to_list()

headers = {
    "authority": "leetcode.com",
    "accept": "*/*",
    "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "authorization": "",
    "cache-control": "no-cache",
    "content-type": "application/json",
    "origin": "https://leetcode.com",
    "pragma": "no-cache",
    "random-uuid": "b2620714-aa57-261f-4e65-9cae773ce574",
    "referer": "https://leetcode.com/problems/two-sum/solutions/",
    "sec-ch-ua": "\"Not_A Brand\";v=\"8\", \"Chromium\";v=\"120\", \"Microsoft Edge\";v=\"120\"",
    "sec-ch-ua-mobile": "?0",
    "sec-ch-ua-platform": "\"Windows\"",
    "sec-fetch-dest": "empty",
    "sec-fetch-mode": "cors",
    "sec-fetch-site": "same-origin",
    "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36 Edg/120.0.0.0",
    "uuuserid": "c7c6dbb8caa515732857b71cf8cbce5f",

    "x-csrftoken": "Zx6ENK601sDu5f7dJrNAgfXaZgFxGnYV6SxIvchtV9nm8WxD3zyh0BeqcWoEmhni",
    "x-newrelic-id": "UAQDVFVRGwIAUVhbAAMFXlQ="
}
cookies = {
    "csrftoken": "Zx6ENK601sDu5f7dJrNAgfXaZgFxGnYV6SxIvchtV9nm8WxD3zyh0BeqcWoEmhni",
    "gr_user_id": "dc04171b-2b8a-437a-bd67-acc2b816d16d",
    "_gid": "GA1.2.1436279393.1703245212",
    "_ga": "GA1.1.1208363238.1703245212",
    "87b5a3c3f1a55520_gr_session_id": "53b6bd46-20ec-4b83-887d-b5eed45c8f59",
    "87b5a3c3f1a55520_gr_session_id_sent_vst": "53b6bd46-20ec-4b83-887d-b5eed45c8f59",
    "_gat": "1",
    "_ga_CDRWKZTDEX": "GS1.1.1703255097.2.1.1703255111.46.0.0"
}
url = "https://leetcode.com/graphql/"
for dict_index,link in zip(lst_index[1256:],lst_link[1256:]):
    dict1 = {}

    questionSlug=link[:-1].split('/')[-1]
    print(questionSlug,'==')

    dict1['Question_id']=dict_index

    dict1['Question_name']=questionSlug
    dict1['Question_link']=link

    lst_language=['c','java','javascript','python']
    for language in lst_language:
        print(language,'--')
        language_format='ref_{}'.format(language)
        dict1[language_format]=[]
        if language=='c':
            tags=language+'-3'
        else:
            tags = language
        data = {
            "operationName": "questionData",
            "variables": {
                "titleSlug": questionSlug
            },
            "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    canSeeQuestion\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    exampleTestcases\n    categoryTitle\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      paidOnly\n      hasVideoSolution\n      paidOnlyVideo\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    enableDebugger\n    envInfo\n    libraryUrl\n    adminUrl\n    challengeQuestion {\n      id\n      date\n      incompleteChallengeCount\n      streakCount\n      type\n      __typename\n    }\n    __typename\n  }\n}\n"
        }
        data = json.dumps(data, separators=(',', ':'))

        response = requests.post(url, headers=headers, cookies=cookies, data=data)
        questionId=response.json()['data']['question']['questionId']
        print(questionId)

        data = {
            "operationName": "questionTopicsList",
            "variables": {
                "orderBy": "hot",
                "query": "",
                "skip": 0,
                "first": 15,
                "tags": [
                    tags
                ],
                "questionId": str(questionId)
            },
            "query": "query questionTopicsList($questionId: String!, $orderBy: TopicSortingOption, $skip: Int, $query: String, $first: Int!, $tags: [String!]) {\n  questionTopicsList(questionId: $questionId, orderBy: $orderBy, skip: $skip, query: $query, first: $first, tags: $tags) {\n    ...TopicsList\n    __typename\n  }\n}\n\nfragment TopicsList on TopicConnection {\n  totalNum\n  edges {\n    node {\n      id\n      title\n      commentCount\n      viewCount\n      pinned\n      tags {\n        name\n        slug\n        __typename\n      }\n      post {\n        id\n        voteCount\n        creationDate\n        isHidden\n        author {\n          username\n          isActive\n          nameColor\n          activeBadge {\n            displayName\n            icon\n            __typename\n          }\n          profile {\n            userAvatar\n            __typename\n          }\n          __typename\n        }\n        status\n        coinRewards {\n          ...CoinReward\n          __typename\n        }\n        __typename\n      }\n      lastComment {\n        id\n        post {\n          id\n          author {\n            isActive\n            username\n            __typename\n          }\n          peek\n          creationDate\n          __typename\n        }\n        __typename\n      }\n      __typename\n    }\n    cursor\n    __typename\n  }\n  __typename\n}\n\nfragment CoinReward on ScoreNode {\n  id\n  score\n  description\n  date\n  __typename\n}\n"
        }

        data = json.dumps(data, separators=(',', ':'))
        while True:
            try:
                response = requests.post(url, headers=headers, cookies=cookies, data=data)
                break
            except:
                print('agin1')

                continue

        lst=response.json()["data"]["questionTopicsList"]["edges"][:3]

        for index,i in enumerate(lst):
            print(index,'|||')
            id_=i['node']['id']
            data_detail = {
                "operationName": "DiscussTopic",
                "variables": {
                    "topicId": id_
                },
                "query": "query DiscussTopic($topicId: Int!) {\n  topic(id: $topicId) {\n    id\n    viewCount\n    topLevelCommentCount\n    subscribed\n    title\n    pinned\n    tags\n    hideFromTrending\n    post {\n      ...DiscussPost\n      __typename\n    }\n    __typename\n  }\n}\n\nfragment DiscussPost on PostNode {\n  id\n  voteCount\n  voteStatus\n  content\n  updationDate\n  creationDate\n  status\n  isHidden\n  coinRewards {\n    ...CoinReward\n    __typename\n  }\n  author {\n    isDiscussAdmin\n    isDiscussStaff\n    username\n    nameColor\n    activeBadge {\n      displayName\n      icon\n      __typename\n    }\n    profile {\n      userAvatar\n      reputation\n      __typename\n    }\n    isActive\n    __typename\n  }\n  authorIsModerator\n  isOwnPost\n  __typename\n}\n\nfragment CoinReward on ScoreNode {\n  id\n  score\n  description\n  date\n  __typename\n}\n"
            }
            data_detail = json.dumps(data_detail, separators=(',', ':'))
            while True:
                try:
                    resp = requests.post(url, headers=headers, cookies=cookies, data=data_detail)
                    break
                except:
                    print('agin2')
                    continue
            content=resp.json()['data']['topic']['post']['content']
            answer_id = resp.json()["data"]['topic']["id"]
            answer_post_id = resp.json()['data']['topic']['post']['id']

            dict1[language_format].append({
                'url': 'https://leetcode.com/problems/'+ questionSlug+'/solutions/' + str(answer_id)+'/'+ str(answer_post_id),
                'code': content
            })
            time.sleep(0.5)
    with open('ReferenceCodeCrawler\\referenceText.jsonl','a+',encoding='utf-8') as f:
        json.dump(dict1,f)
        f.write('\n')

