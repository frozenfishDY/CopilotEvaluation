from collections import Counter
import json
import re
import Levenshtein
import ast
from nltk.util import ngrams
# Import CrystalBLEU
from crystalbleu import corpus_bleu
from crystalbleu import sentence_bleu
from crystalbleu import SmoothingFunction
import tokenize
from io import BytesIO
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from scipy.stats import wilcoxon
from cliffs_delta import cliffs_delta
import numpy as np



def calculate_crystalbleu(references,candidates,tokenized_corpus):
    # 2. Extract trivially shared n-grams
    trivial_shares_number=20
    # <tokenized_corpus> is a list of strings
    # Extract all n-grams of length 1-4
    all_ngrams = []
    for n in range(1, 5):
        all_ngrams.extend(list(ngrams(tokenized_corpus, n)))
    # Calculate frequencies of all n-grams
    frequencies = Counter(all_ngrams)
    trivially_shared_ngrams = dict(frequencies.most_common(trivial_shares_number))
    #print(trivially_shared_ngrams)

    # 3. Calculate CrystalBLEU
    #crystalBLEU_score = corpus_bleu(references, candidates, ignoring=trivially_shared_ngrams)
    chencherry = SmoothingFunction()
    crystalBLEU_score=sentence_bleu(references,candidates,smoothing_function=chencherry.method1,ignoring=trivially_shared_ngrams)
    #crystalBLEU_score=sentence_bleu(references,candidates,ignoring=trivially_shared_ngrams)
    #print(crystalBLEU_score)
    return crystalBLEU_score

def flatten_nested_list(nested_list):
    flat_list = []
    for item in nested_list:
        if isinstance(item, list):
            flat_list.extend(flatten_nested_list(item))
        else:
            flat_list.append(item)
    return flat_list

def calculate_levenshtein(referencelist,hypothesis):
    scores=[]
    for i in range(len(referencelist)):
        scores.append(Levenshtein.distance(referencelist[i],hypothesis))
    average_score = sum(scores) / len(scores)
    return round(average_score)



def getAllLevenshteinScores(lan):
   with open ("reference_"+lan+".jsonl","r+",encoding="utf-8") as f:
         ref_content = f.readlines()
   with open ("hypothesis_"+lan+".jsonl","r+",encoding="utf-8") as f:
         hyp_content = f.readlines()
   if len(ref_content)!=len(hyp_content):
       print("Error: reference and hypothesis files are not the same length")
       return
   keyName="ref_"+lan
   lev_scores=[]

   for i in range(len(ref_content)):
       ref_json= json.loads(ref_content[i])
       hypo_json=json.loads(hyp_content[i])
       if hypo_json["id"]!=ref_json["id"]:
           print("ID Error: "+hypo_json["id"]+" "+ref_json["id"])
           return
       id=hypo_json["id"]
       ref_json_code_list=ref_json[keyName]
       ref_code_list=flatten_nested_list(ref_json_code_list)
       hypo_code=hypo_json["hypo_code"]
       score=calculate_levenshtein(ref_code_list,hypo_code)
       lev_scores.append(score)
    
   with open ("levenshtein_"+lan+".txt","w",encoding="utf-8") as f:
       for i in range(len(lev_scores)):
           f.write(str(lev_scores[i])+"\n")

def tokenize_code(code_str):
    tokens = re.findall(r'\b\w+\b|\S', code_str)
    return tokens

def getRefAndHypoTokenization(ref_code_list,hypo_code):
    corup_str=""
    ref_token_list=[]
    for i in range(len(ref_code_list)):
        corup_str+=ref_code_list[i]
        ref_token_list.append(tokenize_code(ref_code_list[i]))
    corup_str+=hypo_code
    hypo_token_list=tokenize_code(hypo_code)
    corup_token_list=tokenize_code(corup_str)
    token_dict={"ref_token":ref_token_list,"hypo_token":hypo_token_list,"corup_token":corup_token_list}
    return token_dict
    
def getCrystalBLEUScores(lan):
    with open ("reference_"+lan+".jsonl","r+",encoding="utf-8") as f:
         ref_content = f.readlines()
    with open ("hypothesis_"+lan+".jsonl","r+",encoding="utf-8") as f:
         hypo_content = f.readlines()
    if len(ref_content)!=len(hypo_content):
       print("Error: reference and hypothesis files are not the same length")
       return
    keyName="ref_"+lan
    crystalBLEU_scores=[]
    for i in range(len(ref_content)):
        ref_json=json.loads(ref_content[i])
        hypo_json=json.loads(hypo_content[i])
        if ref_json["id"]!=hypo_json["id"]:
            print("ID Error: "+ref_json["id"]+" "+hypo_json["id"])
            return
        ref_code_list=flatten_nested_list(ref_json[keyName])
        hypo_code=hypo_json["hypo_code"]
        token_dict=getRefAndHypoTokenization(ref_code_list,hypo_code)
        crystalBLEU_score=calculate_crystalbleu(token_dict["ref_token"],token_dict["hypo_token"],token_dict["corup_token"])
        #print(ref_json["id"])
        crystalBLEU_scores.append(crystalBLEU_score)
    
    with open ("crystalBLEU_"+lan+".txt","w",encoding="utf-8") as f:
       for i in range(len(crystalBLEU_scores)):
           f.write(str(crystalBLEU_scores[i])+"\n")

def draw_bleu_box_plot():
    # 读取Excel文件
    excel_file = r'..\record.xlsx'  # 替换为你的Excel文件路径
    df = pd.read_excel(excel_file,sheet_name='Sheet3')
    columns=['C','Java','JavaScript','Python']
    df[columns].boxplot()
    # 调整字体大小
    plt.xticks(fontsize=12)
    plt.yticks(fontsize=12)

    plt.title('CrystalBLEU Box Plot',fontsize=15)
    plt.xlabel('Language',fontsize=15)
    plt.ylabel('CrystalBLEU',fontsize=15)
    plt.show()

def draw_lev_box_plot():
    excel_file = r'..\record.xlsx'  # 替换为你的Excel文件路径
    df = pd.read_excel(excel_file,sheet_name='Sheet4')
    columns=['C','Java','JavaScript','Python']
    df[columns].boxplot()
    plt.title('Levenshtein Distance Box Plot')
    plt.xlabel('Language')
    plt.ylabel('Levenshtein Distance')
    plt.show()

def draw_bleu_box_plot_byDifficulty(difficulty):
    excel_file = r'..\record.xlsx'  # 替换为你的Excel文件路径
    df = pd.read_excel(excel_file,sheet_name='Sheet3')
    diff_df=df[df['Difficulty']==difficulty]
    columns=['C','Java','JavaScript','Python']
    diff_df[columns].boxplot()
    plt.title("CrystalBLEU box plot on "+difficulty+" difficulty")
    plt.xlabel('Language')
    plt.ylabel('CrystalBLEU')
    plt.show()

def draw_levdist_box_plot_byDifficulty(difficulty):
    excel_file = r'..\record.xlsx'  # 替换为你的Excel文件路径
    df = pd.read_excel(excel_file,sheet_name='Sheet4')
    diff_df=df[df['Difficulty']==difficulty]
    columns=['C','Java','JavaScript','Python']
    diff_df[columns].boxplot()
    plt.title("Levenshtein Distance box plot on "+difficulty+" difficulty")
    plt.xlabel('Language')
    plt.ylabel('Levenshtein Distance')
    plt.show()

def draw_diff_bleu_boxPlot():
    filepath=r'..\record.xlsx'
    df=pd.read_excel(filepath,sheet_name='Sheet3')
    # 使用箱型图绘制不同难度下四种语言的BLEU分数分布
    diff_order=['Easy','Medium','Hard']
    df['Difficulty']=pd.Categorical(df['Difficulty'],categories=diff_order,ordered=True)
    df=df.sort_values('Difficulty')
    #plt.figure(figsize=(15, 6))
    df.boxplot(column=['C', 'Java', 'JavaScript', 'Python'], by='Difficulty', grid=False)
    #plt.title('CrystalBLEU under 3 difficulty levels')
    plt.suptitle('')  # 删除默认的分组标题
    plt.xlabel('Difficulty')
    plt.ylabel('CrystalBLEU')
    plt.show()

def draw_crystal_BLEU(mode):
    if mode=="BLEU":
        sheetName='Sheet3'
        y_label='CrystalBLEU Scores'
    
    if mode=="LEV":
        sheetName='Sheet4'
        y_label='Levenshtein Distance'


    filepath=r'..\record.xlsx'
    df=pd.read_excel(filepath,sheet_name=sheetName)
       
    lan_columns=['C','Java','JavaScript','Python']
    data1=df[lan_columns]
    data2=df[df['Difficulty']=='Easy'][lan_columns]
    data3=df[df['Difficulty']=='Medium'][lan_columns]
    data4=df[df['Difficulty']=='Hard'][lan_columns]
    fig, axs = plt.subplots(1, 4, figsize=(6, 6),sharey=True,sharex=True)
    #axs.title.set_position([0.5, -0.1])  # 调整标题位置，[0.5, -0.1] 表示水平居中，垂直下移
    xticklabels = ['C', 'Java', 'JS', 'Python']
    #设置子图的y轴刻度字体大小
    
    for ax in axs:
        ax.tick_params(axis='y',labelsize=15)
    for ax in axs:
        ax.tick_params(axis='x',labelsize=14)

    boxplot0=axs[0].set_xticks([1, 2, 3, 4])
    axs[0].set_xticklabels(xticklabels)
    axs[0].set_title('(a) Overall',y=-0.1,fontdict={'fontsize': 14})
    axs[0].set_ylabel(y_label,fontsize=15)
    axs[0].boxplot(data1)
    
    boxplot1=axs[1].boxplot(data2)
    axs[1].set_title('(b) Easy',y=-0.1,fontdict={'fontsize': 14})
    axs[1].set_xticks([1, 2, 3, 4])
    axs[1].set_xticklabels(xticklabels)

    boxplot2=axs[2].boxplot(data3) 
    axs[2].set_title('(c) Medium',y=-0.1,fontdict={'fontsize': 14})
    axs[2].set_xticks([1, 2, 3, 4])
    axs[2].set_xticklabels(xticklabels)

    boxplot3=axs[3].boxplot(data4)
    axs[3].set_title('(d) Hard',y=-0.1,fontdict={'fontsize': 14})
    axs[3].set_xticks([1, 2, 3, 4])
    axs[3].set_xticklabels(xticklabels)

    plt.show()

  
    quartiles1 = [item.get_ydata() for item in boxplot1['whiskers']]
    medians1 = [item.get_ydata() for item in boxplot1['medians']]
    """
    # 打印四分位值和中位数
    print("子图1的四分位值和中位数:")
    print("Q1:", quartiles1[0][1])
    print("Q3:", quartiles1[1][1])
    print("中位数:", medians1[0][1])
    """


def calculate_wilcoxon(mode,diff=None):
    if mode=="BLEU":
        sheetName='Sheet3'
    if mode=="LEV":
        sheetName='Sheet4'
    filepath=r'..\record.xlsx'
    df=pd.read_excel(filepath,sheet_name=sheetName)
    lan_columns=['C','Java','JavaScript','Python']
    if diff==None:
        data=df[lan_columns]
    elif diff=='Easy':
        data=df[df['Difficulty']=='Easy'][lan_columns]
    elif diff=='Medium':
        data=df[df['Difficulty']=='Medium'][lan_columns]
    elif diff=='Hard':
        data=df[df['Difficulty']=='Hard'][lan_columns]
    
    if diff:
        print("=========="+diff+"============:")
    # 获取列名列表
    columns = data.columns
    # 两两进行Wilcoxon符号秩检验
    for i in range(len(columns)):
        for j in range(i + 1, len(columns)):
            col1 = data[columns[i]].tolist()
            col2 = data[columns[j]].tolist()
            # 执行Wilcoxon符号秩检验
            statistic, p_value = wilcoxon(col1, col2)

            print(f'Wilcoxon符号秩检验 ({columns[i]}, {columns[j]}):')
            print(f'Statistic: {statistic}')
            print(f'P-value: {p_value}')
            print('------------------------')

def calculate_cliffsdelta(mode,diff=None):

    if mode=="BLEU":
        sheetName='Sheet3'
    if mode=="LEV":
        sheetName='Sheet4'
    filepath=r'..\record.xlsx'
    df=pd.read_excel(filepath,sheet_name=sheetName)
    lan_columns=['C','Java','JavaScript','Python']
    if diff==None:
        data=df[lan_columns]
    elif diff=='Easy':
        data=df[df['Difficulty']=='Easy'][lan_columns]
    elif diff=='Medium':
        data=df[df['Difficulty']=='Medium'][lan_columns]
    elif diff=='Hard':
        data=df[df['Difficulty']=='Hard'][lan_columns]


    # 获取列名列表
    columns = data.columns
    for i in range(len(columns)):
        for j in range(i + 1, len(columns)):
            col1 = data[columns[i]].tolist()
            col2 = data[columns[j]].tolist()
            d,res=cliffs_delta(col1,col2)
            print(f'Cliff\'s delta 符号秩检验 ({columns[i]}, {columns[j]}):')
            print(f'Delta: {round(d,2)}    Level:{res}')
            print('------------------------')

def calculate_table_wilcoxonAndCliff(rq):
    if rq=="RQ3":
        sheetName='Sheet5'
    elif rq=="RQ1":
        sheetName='Sheet6'
    filepath=r'..\record.xlsx'
    df=pd.read_excel(filepath,sheet_name=sheetName)
    lan_columns=['C','Java','JavaScript','Python']
    data=df[lan_columns]  
   

    
    # 获取列名列表
    columns = data.columns
    for i in range(len(columns)):
        for j in range(i + 1, len(columns)):
            col1 = data[columns[i]].tolist()
            col2 = data[columns[j]].tolist()
            statistic, p_value = wilcoxon(col1, col2)
            print(f'Wilcoxon符号秩检验 ({columns[i]}, {columns[j]}):')
            print(f'Statistic: {statistic}')
            print(f'P-value: {p_value}')
            print('------------------------')\
    
    for i in range(len(columns)):
        for j in range(i + 1, len(columns)):
            col1 = data[columns[i]].tolist()
            col2 = data[columns[j]].tolist()
            d,res=cliffs_delta(col1,col2)
            print(f'Cliff\'s delta 符号秩检验 ({columns[i]}, {columns[j]}):')
            print(f'Delta: {round(d,2)}    Level:{res}')
            print('------------------------')


def draw_crystal_BLEU_new(rq_mode):
    """
    if mode=="BLEU":
        sheetName='Sheet3'
        y_label='CrystalBLEU Scores'
    
    if mode=="LEV":
        sheetName='Sheet4'
        y_label='Levenshtein Distance'
    """

    filepath=r'..\record.xlsx'
    lan_columns=['C','Java','JavaScript','Python']
    df_bleu=pd.read_excel(filepath,sheet_name='Sheet3')
    df_lev=pd.read_excel(filepath,sheet_name='Sheet4')

    bleu_y_label='CrystalBLEU Scores'
    lev_y_label='Levenshtein Distance'
    
    #top=0.805,bottom=0.11,left=0.08,right=0.625,hspace=0.2,wspace=0.2
    #fig.subplots_adjust(top=0.805,bottom=0.11,left=0.08,right=0.625,hspace=0.2,wspace=0.2)
    #fig.tight_layout()
    xticklabels = ['C', 'Java', 'JS', 'Python']

    if rq_mode=='overall':
       fig, axs = plt.subplots(1, 2, figsize=(1, 4),sharey=False,sharex=True)
       data_bleu=df_bleu[lan_columns]
       data_lev=df_lev[lan_columns]
       
       for ax in axs:
        ax.tick_params(axis='y',labelsize=15)
       for ax in axs:
        ax.tick_params(axis='x',labelsize=14)
        #ax.xticks(np.arange(1, 5, 0.1))

       boxplot0=axs[0].boxplot(data_bleu)
       axs[0].set_xticks(range(1,5))
       axs[0].set_xticklabels(xticklabels)
       axs[0].set_title('CrystalBLEU',y=-0.1,fontdict={'fontsize': 14})
       #axs[0].set_ylabel(bleu_y_label,fontsize=15)

       boxplot1=axs[1].boxplot(data_lev)
       axs[1].set_title('Levenshtein Distance',y=-0.1,fontdict={'fontsize': 14})
       axs[1].set_xticks([1, 2, 3, 4])
       #axs[1].set_ylabel(lev_y_label,fontsize=15)
       axs[1].set_xticklabels(xticklabels)
       plt.show()

    elif rq_mode=='Easy':
        fig, axs = plt.subplots(1, 2, figsize=(1, 4),sharey=False,sharex=True)
        data_bleu=df_bleu[df_bleu['Difficulty']=='Easy'][lan_columns]
        data_lev=df_lev[df_lev['Difficulty']=='Easy'][lan_columns]
        for ax in axs:
            ax.tick_params(axis='y',labelsize=15)
        for ax in axs:
            ax.tick_params(axis='x',labelsize=14)

        boxplot0=axs[0].set_xticks([1, 2, 3, 4])
        axs[0].set_xticklabels(xticklabels)
        axs[0].set_title('CrystalBLEU',y=-0.1,fontdict={'fontsize': 14})
        #axs[0].set_ylabel(bleu_y_label,fontsize=15)
        axs[0].boxplot(data_bleu)

        boxplot1=axs[1].boxplot(data_lev)
        axs[1].set_title('Levenshtein Distance',y=-0.1,fontdict={'fontsize': 14})
        axs[1].set_xticks([1, 2, 3, 4])
        #axs[1].set_ylabel(lev_y_label,fontsize=15)
        axs[1].set_xticklabels(xticklabels)
        plt.show()
    
    elif rq_mode=='Medium':
        fig, axs = plt.subplots(1, 2, figsize=(1, 4),sharey=False,sharex=True)
        data_bleu=df_bleu[df_bleu['Difficulty']=='Medium'][lan_columns]
        data_lev=df_lev[df_lev['Difficulty']=='Medium'][lan_columns]
        for ax in axs:
            ax.tick_params(axis='y',labelsize=15)
        for ax in axs:
            ax.tick_params(axis='x',labelsize=14)

        boxplot0=axs[0].set_xticks([1, 2, 3, 4])
        axs[0].set_xticklabels(xticklabels)
        axs[0].set_title('CrystalBLEU',y=-0.1,fontdict={'fontsize': 14})
        #axs[0].set_ylabel(bleu_y_label,fontsize=15)
        axs[0].boxplot(data_bleu)

        boxplot1=axs[1].boxplot(data_lev)
        axs[1].set_title('Levenshtein Distance',y=-0.1,fontdict={'fontsize': 14})
        axs[1].set_xticks([1, 2, 3, 4])
        #axs[1].set_ylabel(lev_y_label,fontsize=15)
        axs[1].set_xticklabels(xticklabels)
        plt.show()

    elif rq_mode=='Hard':
        fig, axs = plt.subplots(1, 2, figsize=(1, 4),sharey=False,sharex=True)
        data_bleu=df_bleu[df_bleu['Difficulty']=='Hard'][lan_columns]
        data_lev=df_lev[df_lev['Difficulty']=='Hard'][lan_columns]
        for ax in axs:
            ax.tick_params(axis='y',labelsize=15)
        for ax in axs:
            ax.tick_params(axis='x',labelsize=14)

        boxplot0=axs[0].set_xticks([1, 2, 3, 4])
        axs[0].set_xticklabels(xticklabels)
        axs[0].set_title('CrystalBLEU',y=-0.1,fontdict={'fontsize': 14})
        #axs[0].set_ylabel(bleu_y_label,fontsize=15)
        axs[0].boxplot(data_bleu)

        boxplot1=axs[1].boxplot(data_lev)
        axs[1].set_title('Levenshtein Distance',y=-0.1,fontdict={'fontsize': 14})
        axs[1].set_xticks([1, 2, 3, 4])
        #axs[1].set_ylabel(lev_y_label,fontsize=15)
        axs[1].set_xticklabels(xticklabels)
        plt.show()

    elif rq_mode=='RQ2_BLEU':
        data_bleu_easy=df_bleu[df_bleu['Difficulty']=='Easy'][lan_columns]
        data_bleu_medium=df_bleu[df_bleu['Difficulty']=='Medium'][lan_columns]
        data_bleu_hard=df_bleu[df_bleu['Difficulty']=='Hard'][lan_columns]
        fig_bleu,axs_bleu=plt.subplots(1,3,figsize=(6,6),sharey=True,sharex=True)
        for ax in axs_bleu:
            ax.tick_params(axis='y',labelsize=15)
        for ax in axs_bleu:
            ax.tick_params(axis='x',labelsize=14)
        
        boxplot0=axs_bleu[0].boxplot(data_bleu_easy)
        axs_bleu[0].set_xticks(range(1,5))
        axs_bleu[0].set_xticklabels(xticklabels)
        axs_bleu[0].set_title('Easy',y=-0.1,fontdict={'fontsize': 14})
        
        boxplot1=axs_bleu[1].boxplot(data_bleu_medium)
        axs_bleu[1].set_xticks(range(1,5))
        axs_bleu[1].set_xticklabels(xticklabels)
        axs_bleu[1].set_title('Medium',y=-0.1,fontdict={'fontsize': 14})

        boxplot2=axs_bleu[2].boxplot(data_bleu_hard)
        axs_bleu[2].set_xticks(range(1,5))
        axs_bleu[2].set_xticklabels(xticklabels)
        axs_bleu[2].set_title('Hard',y=-0.1,fontdict={'fontsize': 14})
        plt.show()

    elif rq_mode=='RQ2_LEV':
        data_lev_easy=df_lev[df_lev['Difficulty']=='Easy'][lan_columns]
        data_lev_medium=df_lev[df_lev['Difficulty']=='Medium'][lan_columns]
        data_lev_hard=df_lev[df_lev['Difficulty']=='Hard'][lan_columns]
        fig_bleu,axs_lev=plt.subplots(1,3,figsize=(6,6),sharey=True,sharex=True)
        for ax in axs_lev:
            ax.tick_params(axis='y',labelsize=15)
        for ax in axs_lev:
            ax.tick_params(axis='x',labelsize=14)
        
        boxplot0=axs_lev[0].boxplot(data_lev_easy)
        axs_lev[0].set_xticks(range(1,5))
        axs_lev[0].set_xticklabels(xticklabels)
        axs_lev[0].set_title('Easy',y=-0.1,fontdict={'fontsize': 14})
        
        boxplot1=axs_lev[1].boxplot(data_lev_medium)
        axs_lev[1].set_xticks(range(1,5))
        axs_lev[1].set_xticklabels(xticklabels)
        axs_lev[1].set_title('Medium',y=-0.1,fontdict={'fontsize': 14})

        boxplot1=axs_lev[2].boxplot(data_lev_hard)
        axs_lev[2].set_xticks(range(1,5))
        axs_lev[2].set_xticklabels(xticklabels)
        axs_lev[2].set_title('Hard',y=-0.1,fontdict={'fontsize': 14})
        plt.show()
       
        
        


        
        

        

           
       
       



    """   
    #df=pd.read_excel(filepath,sheet_name=sheetName)
       
    lan_columns=['C','Java','JavaScript','Python']
    data1=df[lan_columns]
    data2=df[df['Difficulty']=='Easy'][lan_columns]
    data3=df[df['Difficulty']=='Medium'][lan_columns]
    data4=df[df['Difficulty']=='Hard'][lan_columns]
    fig, axs = plt.subplots(1, 4, figsize=(6, 6),sharey=True,sharex=True)
    #axs.title.set_position([0.5, -0.1])  # 调整标题位置，[0.5, -0.1] 表示水平居中，垂直下移
    xticklabels = ['C', 'Java', 'JS', 'Python']
    axs[0].set_xticklabels(xticklabels)
    axs[0].set_title('(a) CrystalBLEU',y=-0.1,fontdict={'fontsize': 14})
    axs[0].set_ylabel(y_label,fontsize=15)
    axs[0].boxplot(data1)
    #设置子图的y轴刻度字体大小
    
    for ax in axs:
        ax.tick_params(axis='y',labelsize=15)
    for ax in axs:
        ax.tick_params(axis='x',labelsize=14)
    
    boxplot0=axs[0].set_xticks([1, 2, 3, 4])
    axs[0].set_xticklabels(xticklabels)
    axs[0].set_title('(a) Overall',y=-0.1,fontdict={'fontsize': 14})
    axs[0].set_ylabel(y_label,fontsize=15)
    axs[0].boxplot(data1)
    
    boxplot1=axs[1].boxplot(data2)
    axs[1].set_title('(b) Easy',y=-0.1,fontdict={'fontsize': 14})
    axs[1].set_xticks([1, 2, 3, 4])
    axs[1].set_xticklabels(xticklabels)

    boxplot2=axs[2].boxplot(data3) 
    axs[2].set_title('(c) Medium',y=-0.1,fontdict={'fontsize': 14})
    axs[2].set_xticks([1, 2, 3, 4])
    axs[2].set_xticklabels(xticklabels)

    boxplot3=axs[3].boxplot(data4)
    axs[3].set_title('(d) Hard',y=-0.1,fontdict={'fontsize': 14})
    axs[3].set_xticks([1, 2, 3, 4])
    axs[3].set_xticklabels(xticklabels)
    plt.show()

    quartiles1 = [item.get_ydata() for item in boxplot1['whiskers']]
    medians1 = [item.get_ydata() for item in boxplot1['medians']]
    # 打印四分位值和中位数
    print("子图1的四分位值和中位数:")
    print("Q1:", quartiles1[0][1])
    print("Q3:", quartiles1[1][1])
    print("中位数:", medians1[0][1])
    """
    
    
   
    

           
def main():
    #getAllLevenshteinScores("c")
    #getCrystalBLEUScores("py")
    #draw_bleu_box_plot()
    #draw_lev_box_plot()
    #draw_bleu_box_plot_byDifficulty("Hard")
    #draw_levdist_box_plot_byDifficulty("Hard")
    #draw_diff_bleu_boxPlot()
    #draw_crystal_BLEU("LEV")
    #calculate_wilcoxon("")
    #calculate_cliffsdelta("LEV")
    #calculate_table_wilcoxonAndCliff("RQ3")
    """
    top=0.75,
    bottom=0.11,
    left=0.03,
    right=0.55,
    hspace=0.2,
    wspace=0.2
    """
    draw_crystal_BLEU_new("RQ2_LEV")

main()
