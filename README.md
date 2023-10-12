# Assessing and Analyzing the Correctness of Github Copilot's Code Suggestions

- [Introduction](#1.Introduction ) 
- [Project structure and explanation](#2.Project-Structure-and-explanation)
- [Evaluation Result](#3.Evaluation-Result)

![ExperimentProcess](./Figure/ExperimentProcess.png)



## 1.Introduction

  we aim to analyze and evaluate the performance of Copilot's multi-language code suggestions. To proceed with our study, we first collect all open-source questions from the question website LeetCode, which totally contains 2,033 coding problems with three difficulty levels and twenty question types. Moreover, we attempt to collect defective code suggestions and the corresponding causes. Meanwhile, we try to analyze why Copilot generates these defective codes, so as to have a comprehensive understanding and analysis of Copilot's defective codes. To facilitate our experiments, we have designed relevant tools to help researchers automatically collect questions, create code suggestions, and analyze execution results. 

***RQ*1**:  To what extent can the Copilot provide correct code suggestions?

***RQ*2**:  For the coding problems with different difficulties, what is the performance of Copilot? 

***RQ*3**:   For the coding problems in different domains, what is the performance of Copilot?

***RQ*4**:  What are the reasons for the incorrectness of Copilot's code suggestions and why?

The date of our experiments and the relevant versions of the tools are shown in Table 1

![Table1](./Figure/Table1_Version.png)



## 2.Project Structure and explanation

```powershell
├── Figure                     
├── output                             
├── results
   ├── RQ1_to_RQ3
   ├── RQ4
   └── calculator.py
├── AllData.xlsx
├── collector.py      
├── README.md         
└── record.xlsx       
```

- ***Figure***  : Experimental result pictures and error cause code examples
- ***output*** : All code suggestion files, sorted by language and difficulty
- **results/RQ1_to_RQ3**:   Experimental results from RQ1 to RQ3
- **results/RQ4** :    Experimental results of RQ4
- **results/calculator.py**:   This script file is used to calculate the indicators and ratios of RQ1~RQ4
- ***AllData.xlsx*** :   This file is used to store all LeetCode issues crawled by collector.py
- ***collector.py*** :   This script is used to crawl all LeetCode questions (satisfying 4 programming languages) and store the content in *AllData.xlsx*. The script also generates a code suggestion file from the extracted content into the *output* folder.
- ***record.xlsx***:     This file is a record of the experimental sample, including the link to the question, difficulty, execution status of the corresponding language code suggestion, question type, and all error types(Because the file is too large, we package it into a compressed file).
- ***README.md***:   User guidance

## 3.Evaluation Result

### 3.1 ***RQ*1**:  To what extent can the Copilot provide correct code suggestions?

![Table2](./Figure/Table2_Overall.png)

### 3.2 ***RQ*2**:  For the coding problems with different difficulties, what is the performance of Copilot?

![Table3](./Figure/Table3_Difficulty.png)

### 2.3 ***RQ*3**: For the coding problems in different domains, What is the performance of Copilot?

![Rq3_Overall](./Figure/rq3_Copilot.png)

<center>Overall Performance of Copilot</center>



![RQ3_C](./Figure/rq3_c.png)

<center>Performance of C</center>



![RQ3_Java](./Figure/rq3_java.png)

<center>Performance of Java</center>



![RQ3_JS](./Figure/rq3_js.png)

<center>Performance of JavaScript</center>



![RQ3_Py](./Figure/rq3_python.png)

<center>Performance of Python</center>

### 3.4 ***RQ*4**:  What are the reasons for the incorrectness of Copilot’s code suggestions and why?

#### 3.4.1 Wrong Answer Results

![WrongAnswer](./Figure/Table4_WrongAnswer.png)



#### 3.4.2 Compile Error Results

![CompileError](./Figure/Table5_CompileError.png)



#### 3.4.3 Runtime Error Results

![RuntimeError](./Figure/Table6_RuntimeError.png)

#### 3.4.4 Error type explanation

***Wrong Answer:***

- *logic Error*:  there is nothing wrong with the code itself, but the logic suggested by the code does not allow it to pass all test cases.

- *Return Only*:  the code in this case only contains ***return*** statements. There are three forms of return statements: 1) Return function parameters directly; 2) Return constants; 3) Return function parameters after constant assignment.

  ![ReturnOnly](./Figure/ErrorSample/ReturnOnly.png)

- *Pass Only*:  this code case only appears in Python. the code suggestion does nothing by only giving  the pass statement.

![ReturnOnly](./Figure/ErrorSample/PassOnly.png)





***Compile Error:***

- *Undeclared Variable*: the code suggestion references an undeclared variable or undeclared member variable in a data structure.

![UV](./Figure/ErrorSample/UndeclaredVariable.png)

- *Variable Redeclaration*: the code suggestion redeclares a variable name.

![VR](./Figure/ErrorSample/VariableRedeclaration.png)

- *Undefined Class Reference*: the code suggestion references undefined class.

![UCR](./Figure/ErrorSample/UndefinedClassReference.png)

- *Variable Declaration Only*: the code suggestion generates only a series of variable declaration statements. And when we call Copilot at the end of the code, we still get a series of declaration statements.

![VDO](./Figure/ErrorSample/VariableDeclarationOnly.png)

- *Undefined Function Reference*: In this case, the code suggestion references a function that is not defined in the code environment. If we call Copilot on these undefined functions, Copilot also cannot generate the specific implementation code of the unknown function.

![UFR](./Figure/ErrorSample/UndefinedFunctionReference.png)

- *For/If Only*: the code suggestion in this case contains a large number of For/if statement blocks. Likewise, when we call Copilot at the end of the code, you just get infinite for/if blocks.

![FIO](./Figure/ErrorSample/ForIfOnly.png)

- *Conflicting Types*: the code suggestions can not be accepted because of data type conflicts, which mainly include the following situations:

​       a) The variable data types at both ends of the operator conflict, such as *double* % *int*;

​       b) The function return value type does not match the specified type;

​       c) When assigning or initializing variables, the given data type conflicts with the defined type, such as *int a=’c*’.

![FIO](./Figure/ErrorSample/ConflictingTypes.png)



***Runtime Error:***

- *Data Overflow*: When the program is running, the data stored in the variable exceeds its capacity.

![FIO](./Figure/ErrorSample/DataOverflow.png)

- *Heap/Stack Overflow*: When the program is running, the heap or stack buffer overflows.

![FIO](./Figure/ErrorSample/HeapStackOverflow.png)

- *Memory Error*: Insufficient memory during program running.

![FIO](./Figure/ErrorSample/MemoryError.png)

- *Null Pointer Error*: This errors occurs when the program accesses or references a **NULL** value data object.

![FIO](./Figure/ErrorSample/NUllPointerError.png)

- *Arithmetic Error*: Exceptions in mathematical operations in the program, such as *a/0* or *a%0*.

![FIO](./Figure/ErrorSample/ArithmeticError.png)

- *Iteration Error*: The objects being iterated in the program are not iterable, such as traversing *integer* or *boolean* types.

![FIO](./Figure/ErrorSample/IterationError.png)
