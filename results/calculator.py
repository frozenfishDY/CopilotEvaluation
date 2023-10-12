import numpy as np
import pandas as pd
import openpyxl
  
def rq1(data,raw_data1):
    
    problem_number=len(data)
    """
    c_acc,java_acc,js_acc,python_acc=0
    c_wa,java_wa,js_wa,python_wa=0
    c_ce,java_ce,js_ce,python_ce=0
    c_re,java_re,js_re,python_re=0
    c_tle,java_tle,js_tle,python_tle=0
    c_mle,java_mle,js_mle,python_mle=0
    """
    accin = 0
    for i in range(0,problem_number):
        if raw_data1.loc[i, 'S_C'] == 'acc' or raw_data1.loc[i, 'S_Java'] == 'acc' or raw_data1.loc[i, 'S_JS'] == 'acc' or raw_data1.loc[i, 'S_Python'] == 'acc':
            accin = accin + 1
    print(accin)
    arr=np.zeros((6,4))
    #The outermost loop, traverses each question
    for i in range(0,problem_number):
        for j in range(4,8):
            lan_index=j-4
            if(data[i][j]=="acc"):
                arr[0][lan_index]+=1
                continue
            if(data[i][j]=="wa"):
                arr[1][lan_index]+=1
                continue
            if(data[i][j]=="ce"):
                arr[2][lan_index]+=1
                continue
            if(data[i][j]=="re"):
                arr[3][lan_index]+=1
                continue
            if(data[i][j]=="tle"):
                arr[4][lan_index]+=1
                continue
            if(data[i][j]=="mle"):
                arr[5][lan_index]+=1
        
    result=np.zeros((6,4)).astype(np.str_)
    for i in range(0,len(result)):
        for j in range(0,len(result[i])):
            item=str(arr[i][j])+" "+"("+format_percentage(arr[i][j],problem_number)+")"
            result[i][j]=item
    hasacc=str(accin)+" "+"("+format_percentage(accin,problem_number)+")"
    result_print(result=result,hasacc=hasacc,mode="Overall")
    return arr

def rq2(data,mode,raw_data1):
    problem_number=0
    has_acc=0
    arr=np.zeros((6,4))
    #The outermost loop, traverses each question
    for i in range(0,len(data)):
     if(data[i][2]==mode):
         problem_number+=1
         for j in range(4,8):
            lan_index=j-4
            if(data[i][j]=="acc"):
                arr[0][lan_index]+=1
                continue
            if(data[i][j]=="wa"):
                arr[1][lan_index]+=1
                continue
            if(data[i][j]=="ce"):
                arr[2][lan_index]+=1
                continue
            if(data[i][j]=="re"):
                arr[3][lan_index]+=1
                continue
            if(data[i][j]=="tle"):
                arr[4][lan_index]+=1
                continue
            if(data[i][j]=="mle"):
                arr[5][lan_index]+=1
    
    result=np.zeros((6,4)).astype(np.str_)
    for i in range(0,len(result)):
        for j in range(0,len(result[i])):
            item=str(arr[i][j])+" "+"("+format_percentage(arr[i][j],problem_number)+")"
            result[i][j]=item
    accin = 0
    for i in range(0,len(data)):
      if raw_data1.loc[i,'Difficulty']==mode:
        if raw_data1.loc[i, 'S_C'] == 'acc' or raw_data1.loc[i, 'S_Java'] == 'acc' or raw_data1.loc[i, 'S_JS'] == 'acc' or raw_data1.loc[i, 'S_Python'] == 'acc':
            accin = accin + 1
    hasacc=str(accin)+" "+"("+format_percentage(accin,problem_number)+")"
    result_print(result=result,hasacc=hasacc,mode=mode)
    print(problem_number)
  

    

def result_print(result,hasacc,mode):
    print("--------------------"+mode+"---------------------------")
    print("Status"+"\t"+"C"+"\t"+"Java"+"\t"+"JavaScript"+"\t"+"Python"+"\n")
    print("ACC   "+"\t"+result[0][0]+"\t"+result[0][1]+"\t"+result[0][2]+"\t"+result[0][3])
    print("WA    "+"\t"+result[1][0]+"\t"+result[1][1]+"\t"+result[1][2]+"\t"+result[1][3])
    print("CE    "+"\t"+result[2][0]+"\t"+result[2][1]+"\t"+result[2][2]+"\t"+result[2][3])
    print("RE    "+"\t"+result[3][0]+"\t"+result[3][1]+"\t"+result[3][2]+"\t"+result[3][3])
    print("TLE   "+"\t"+result[4][0]+"\t"+result[4][1]+"\t"+result[4][2]+"\t"+result[4][3])
    print("MLE   "+"\t"+result[5][0]+"\t"+result[5][1]+"\t"+result[5][2]+"\t"+result[5][3])
    print("HasACC"+"\t"+hasacc)

#calculate percentage
def format_percentage(a,b):
    res=round((a/b)*100,1)
    return str(res)+"%"

def rq3(raw_data1):
    typelist=["Array","String","HashTable",
              "Math","DP","Sorting","Greedy",
              "DFS","BS","BFS","Tree","Matrix",
              "TwoPointers","BinaryTree","BitManipulation","Heap",
              "Stack","PrefixSum","Graph","Simulation","Counting","Backtracking"]
    for i in range(0,len(typelist)):
        calculateType(typelist[i],raw_data1)


    

def calculateType(typename,raw_data1):
    type_number=0
    c_acc=0
    java_acc=0
    js_acc=0
    py_acc=0
    hasacc=0
    for i in range(0,len(raw_data1)):
        if typename in str(raw_data1.loc[i,'Type']):
            type_number+=1
            c_flag=False
            java_flag=False
            js_flag=False
            py_flag=False
            if raw_data1.loc[i,'S_C']=='acc':
                c_acc+=1
                c_flag=True
            if raw_data1.loc[i,'S_Java']=='acc':
                java_acc+=1
                java_flag=True
            if raw_data1.loc[i,'S_JS']=='acc':
                js_acc+=1
                js_flag=True
            if raw_data1.loc[i,'S_Python']=='acc':
                py_acc+=1
                py_flag=True
            if c_flag or java_flag or js_flag or py_flag:
                hasacc+=1
    print("-------------"+typename+"----------------")
    print("Problem Number: "+str(type_number))
    print("Acc           : "+str(c_acc)+" "+"("+format_percentage(c_acc,type_number)+")"+" "
          +str(java_acc)+" "+"("+format_percentage(java_acc,type_number)+")"+" "
          +str(js_acc)+" "+"("+format_percentage(js_acc,type_number)+")"+" "
          +str(py_acc)+" "+"("+format_percentage(py_acc,type_number)+")")
    print("HasAcc        : "+str(hasacc)+" "+"("+format_percentage(hasacc,type_number)+")")

def rq4(arr):
    """
    The causes of errors in the table are manually counted by us. 
    This function is responsible for calculating the types and corresponding proportions.
    """
    #paths of RQ4 result files
    wa_c_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\WrongAnswer_C.xlsx"
    wa_py_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\WrongAnswer_Py.xlsx"
    ce_c_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\CompileError_C.xlsx"
    ce_java_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\CompileError_Java.xlsx"
    re_c_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\RuntimeError_C.xlsx"
    re_java_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\RuntimeError_Java.xlsx"
    re_js_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\RuntimeError_JS.xlsx"
    re_py_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ4\RuntimeError_Py.xlsx"
    print("\n----Wrong Answer: C "+"("+str(arr[1][0])+")"+"-----")
    wa_c_df=pd.read_excel(wa_c_path)
    calculateErrorType(wa_c_df,arr[1][0])

    print("----Wrong Answer: Python "+"("+str(arr[1][3])+")"+"-----")
    wa_py_df=pd.read_excel(wa_py_path)
    calculateErrorType(wa_py_df,arr[1][3])

    print("----Compile Error: C "+"("+str(arr[2][0])+")"+"-----")
    ce_c_df=pd.read_excel(ce_c_path)
    calculateErrorType(ce_c_df,arr[2][0])

    print("----Compile Error: Java "+"("+str(arr[2][1])+")"+"-----")
    ce_java_df=pd.read_excel(ce_java_path)
    calculateErrorType(ce_java_df,arr[2][1])

    print("----Runtime Error: C "+"("+str(arr[3][0])+")"+"-----")
    re_c_df=pd.read_excel(re_c_path)
    calculateErrorType(re_c_df,arr[3][0])

    print("----Runtime Error: Java "+"("+str(arr[3][1])+")"+"-----")
    re_java_df=pd.read_excel(re_java_path)
    calculateErrorType(re_java_df,arr[3][1])

    print("----Runtime Error: JavaScript "+"("+str(arr[3][2])+")"+"-----")
    re_js_df=pd.read_excel(re_js_path)
    calculateErrorType(re_js_df,arr[3][2])

    print("----Runtime Error: Python "+"("+str(arr[3][3])+")"+"-----")
    re_py_df=pd.read_excel(re_py_path)
    calculateErrorType(re_py_df,arr[3][3])  

    

def calculateErrorType(dataframe,totalCount):
    grouped=dataframe['Reason'].value_counts()
    
    for key,value in grouped.items():
        print(key+" "+str(value)+" "+"("+format_percentage(value,totalCount)+")")
    print("\n")
        
def main():
    input_path=r"D:\LeetCodeCrawler\GitMaterial\results\RQ1_to_3\RQ1_to_3.xlsx"
    raw_data=pd.read_excel(input_path)
    raw_data1=pd.read_excel(input_path)
    data=raw_data.values.astype(str)
    overall_arr=rq1(data=data, raw_data1=raw_data1)
    rq2(data=data,mode="Easy",raw_data1=raw_data1)
    rq2(data=data,mode="Medium",raw_data1=raw_data1)
    rq2(data=data,mode="Hard",raw_data1=raw_data1)
    rq3(raw_data1=raw_data1)
    rq4(overall_arr)
    
 
main()


    

    
    

   
    
            


    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 