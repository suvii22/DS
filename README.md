# DS
## 线性表(List)
### 顺序表
所有元素依据次序映射为连续而完整的物理空间，称为顺序表（连续映射）。  
__优势__：借助物理空间的连续性确保全序关系，管理简单，访问速度快。  
__劣势__：连续空间难以预先准确规划，造成浪费或者无法扩展。  
insert：O(1)  
remove：O(n)  
locate：O(n)  
get：O(1)  
### 链表
各个元素映射到离散的物理空间并通过结构信息维护全序关系，称为链表（离散映射）。  
__优势__：不依赖物理空间的连续性，分散存储，充分利用存储空间，具有良好可扩展性。    
__劣势__：需要额外信息维护结构，逻辑较为复杂，动态分配内存造成额外时间消耗。  
**单向链表、双向链表、循环链表**  
## 栈
TODO
## 队列
TODO 
## 串
### KMP
对于模式串P的前j+1个序列字符：
- 若P[k] == P[j]，则next[j + 1] = next [j] + 1 = k + 1  
- 若p[k] ≠ p[j]，如果此时p[ next[k] ] == p[j]，则next[ j + 1 ] = next[k] + 1，否则继续递归前缀索引k = next[k]，而后重复此过程。 相当于在字符p[ j+1 ]之前不存在长度为k+1的前缀”p0 p1, …, pk-1 pk”跟后缀“pj-k pj-k+1, …, pj-1 pj”相等，那么是否可能存在另一个值t+1 < k+1，使得长度更小的前缀 “p0 p1, …, pt-1 pt” 等于长度更小的后缀 “pj-t pj-t+1, …, pj-1 pj” 呢？如果存在，那么这个t+1 便是next[ j+1 ]的值，此相当于利用已经求得的next 数组（next [0, …, k, …, j]）进行P串前缀跟P串后缀的匹配  

__优化__：当p[j] != s[i] 时，下次匹配必然是p[ next[j] ] 跟s[i]匹配，如果p[j] = p[ next[j] ]，必然导致后一步匹配失败（因为p[j]已经跟s[i]失配，然后你还用跟p[j]等同的值p[ next[j] ]去跟s[i]匹配，很显然，必然失配），所以不能允许p[j] = p[ next[j ]]。  
## 稀疏矩阵的转置
为加速转置速度，建立辅助数组num和cpot：  
num记录矩阵转置前各列，即转置矩阵各行非零元素个数；  
cpot记录各行非零元素在转置三元组表中开始存放位置。   
__cpot[0]=1__  
__cpot[col]=cpot[col-1]+num[col-1]__   2≦col≦M.colSize  
扫描矩阵原矩阵，根据某项列号，确定它转置后的行号,查cpot表,按查到的位置直接将该项存入转置矩阵数据表中。  




