# DS
## 线性表(List)
### 顺序表
所有元素依据次序映射为连续而完整的物理空间，称为顺序表（连续映射）。  
__优势__：借助物理空间的连续性确保全序关系，管理简单，访问速度快。  
__劣势__：连续空间难以预先准确规划，造成浪费或者无法扩展。  
insert：*O(1)*  
remove：*O(n)*  
locate：*O(n)*  
get：*O(1)*  
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
__cpot[col]=cpot[col-1]+num[col-1]__   0<col<M.colSize  
扫描矩阵原矩阵，根据某项列号，确定它转置后的行号,查cpot表,按查到的位置直接将该项存入转置矩阵数据表中。  
## 二叉树
### 遍历
前序  VLR  
中序  LVR   
后序  LRV  
### 线索二叉树
在遍历的同时，使用二叉树中空闲的内存空间记录某些结点的前趋和后继元素的位置（不是全部）。这样在算法后期需要遍历二叉树时，就可以利用保存的结点信息，提高了遍历的效率。使用这种方法构建的二叉树，即为“线索二叉树”。  
### 树与森林
双亲表示，子女表示  
__孩子兄弟表示__：firstChild 指向该结点的第一个子女结点。无序树时，可任意指定一个结点为第一个子女。nextBrother 指向该结点的下一个兄弟。任一结点在存储时总是有顺序的。若想找某结点的所有子女，可先找firstChild,再反复用 nextBrother 沿链扫描。  
__森林与二叉树表示的转换__:可以借助树的二叉树表示来实现。先将森林中每一棵树变为二叉树；再将各二叉树的根结点视为兄弟连在一起。  
__树的先根次序遍历__：当树非空时，访问根结点，再依次先根遍历根的各棵子树。树的先根遍历可以借助对应二叉树的前序遍历算法实现。  
__树的后根次序遍历__：当树非空时，依次后根遍历根的各棵子树，再访问根结点。树的后根遍历可以借助对应二叉树的中序遍历算法实现。  
__森林的先根次序遍历__：访问森林的根（也是第一棵树的根）；先根遍历森林第一棵树的根的子树森林；先根遍历森林中除第一棵树外其他树组成的森林。  
__森林的后根次序遍历__：后根遍历森林 F 第一棵树的根结点的子树森林；访问森林的根结点；后根遍历森林中除第一棵树外其他树组成的森林。
## 图
有向图、无向图  
__完全图__：若有 n 个顶点的无向图有 n(n-1)/2 条边, 则此图为完全无向图。有 n 个顶点的有向图有n(n-1) 条边, 则此图为完全有向图。  
__邻接顶点__：如果 (u, v) 是 E(G) 中的一条边，则称 u 与 v 互为邻接顶点。   
__子图__：设有两个图G＝(V, E) 和G'＝(V', E')。若V'∈V 且E'∈E, 则称图G'是图G的子图。  
__顶点的度__：一个顶点v的度是与它相关联的边的条数。记作TD(v)。在有向图中, 顶点的度等于该顶点的入度与出度之和。  
__路径长度__：非带权图的路径长度是指此路径上边的条数。带权图的路径长度是指路径上各边的权之和。  
__简单路径__：若路径上各顶点 v1,v2,...,vm 均不互相重复, 则称这样的路径为简单路径。  
__连通图与连通分量__：在无向图中, 若从顶点v1到顶点v2有路径, 则称顶点v1与v2是连通的。如果图中任意一对顶点都是连通的, 则称此图是连通图。非连通图的极大连通子图叫做连通分量。  
__强连通图与强连通分量__：在有向图中, 若对于每一对顶点vi和vj, 都存在一条从vi到vj和从vj到vi的路径, 则称此图是强连通图。非强连通图的极大强连通子图叫做强连通分量。  
__生成树__：一个连通图的生成树是其极小连通子图，包含图中所有顶点，但在 n 个顶点的情形下，有 n-1 条边。 
  
__关于无向图的生成树的几个结论：__
- 一棵有n个顶点的生成树有且仅有n-1条边；
- 如果一个图有n个顶点和小于n-1条边，则是非连通图；
- 如果多于n-1条边，则一定有环；
- 有n-1条边的图不一定是生成树。  

__DFS、BFS__（看代码应该就会了，咕咕咕）  

__连通分量和生成树__：
- 当无向图为连通图时，从图中某一顶点出发，利用深度或广度优先搜索算法能够遍历到图中的所有顶点。这时图G=(V, E)中边集合E被分为已经历的T和未经历的B两个部分。那么(V, T)就是图G的极小连通子图，也就是连通图的一棵生成树。
- 利用广度优先搜索生成广度优先生成树，利用深度优先搜索生成深度优先生成树。
- 对于非连通的无向图，所有连通分量的生成树组成了非连通图的生成森林。  

__最小生成树__：设无向连通带权图G=<V,E,W>，T是G的一棵生成树，T的各边权之和称为T的权，记作W(T)。G的所有生成树中权最小的生成树称为G的最小生成树。  

__普里姆(Prim)算法__：
1. 从连通网络 N = {V, E}中的某一顶点 u0 出发, 选择与它关联的具有最小权值的边 (u0, v), 将其顶点加入到生成树顶点集合U中。
2. 以后每一步从一个顶点在集合U中,  而另一个顶点不在集合U中的各条边中选择权值最小的边(u, v), 把它的顶点加入到集合U中。如此继续下去, 直到网络中的所有顶点都加入到生成树顶点集合U中为止。  

__AOV__：可以用有向图表示一个工程。在这种有向图中，用顶点表示活动，用有向边<Vi, Vj>表示活动Vi 必须先于活动Vj 进行。这种有向图叫做顶点表示活动的AOV网络 (Activity  On Vertices)。  在AOV网络中不能出现有向回路,  即有向环。如果出现了有向环，则意味着某项活动应以自己作为先决条件。
因此，对给定的AOV网络，必须先判断它是否存在有向环。  
__进行拓扑排序的方法__：
1. 在AOV网络中选一个没有直接前驱的顶点, 并输出之;
2. 从图中删去该顶点, 同时删去所有它发出的有向边;
3. 重复以上 ① 、②步, 直到：全部顶点均已输出，拓扑有序序列形成，拓扑排序完成；或图中还有未输出的顶点, 但已跳出处理循环。说明图中还剩下一些顶点, 它们都有直接前驱。这时网络中必存在有向环。  

### AOE
如果在无有向环的带权有向图中, 用有向边表示一个工程中的活动 (Activity), 用边上权值表示活动持续时间 (Duration),  用顶点表示事件 (Event),  则这样的有向图叫做用边表示活动的网络, 简称 AOE ( Activity On Edges ) 网络。  
从源点到各个顶点, 以至从源点到汇点的有向路径可能不止一条。这些路径的长度也可能不同。完成不同路径的活动所需的时间虽然不同, 但只有各条路径上所有活动都完成了, 整个工程才算完成。因此, 完成整个工程所需的时间取决于从源点到汇点的最长路径长度, 即在这条路径上所有活动的持续时间之和。这条路径长度最长的路径就叫做关键路径(Critical Path)。  
1. 事件Vi 的最早可能发生时间Ve[i]是从源点V0 到顶点Vi 的最长路径长度，Ve[i]=max{Ve[j]+dur(<Vj,Vi>)}
2. 事件Vi 的最迟发生时间Vl[i]是在保证汇点Vn-1 在Ve[n-1] 时刻完成的前提下，事件Vi 的允许的最迟开始时间，Vl[i]=min{Vl[Vj]-dur(<Vi-Vj>)}
3. 活动ak 的最早可能开始时间 e[k] 设活动ak 在边<Vi, Vj>上, 则e[k]是从源点V0到 顶点Vi 的最长路径长度。因此, e[k] = Ve[i]。
4. 活动ak的最迟允许开始时间 l[k]是在不会引起时间延误的前提下, 该活动允许的最迟开始时间。
           l[k] = Vl[j]-dur(<i, j>)。
其中, dur(<i, j>)是完成ak所需的时间。
5. 时间余量 l[k]-e[k]表示活动ak的最早可能开始时间和最迟允许开始时间的时间余量。l[k] == e[k]表示活动 ak 是没有时间余量的关键活动。  

## 查找
查找过程中主要操作是关键字的比较，查找过程中关键字的平均比较次数(平均查找长度ASL：Average Search Length)作为衡量一个查找算法效率高低的标准。ASL定义为：ASL =∑PixCi，n为查找表中记录个数，∑Pi=1。  
Pi ：查找第i个记录的概率，不失一般性，认为查找每个记录的概率相等，即P1=P2=…=Pn=1/n ；  
Ci ：查找第i个记录需要进行比较的次数。  
### 二分查找 
前提：查找表中的所有记录是按关键字有序(升序或降序)  
时间复杂度：*O(logn)*  
算法分析  
1. 查找时每经过一次比较，查找范围就缩小一半，该过程可用一棵二叉树表示，这样所得到的二叉树称为判定树(Decision Tree)。
2. 将二叉判定树的第[log2n] +1层上的结点补齐就成为一棵满二叉树，深度不变，h=[log2(n+1)]
3. 由满二叉树性质知，第i 层上的结点数为2i-1(i≤h) ，设表中每个记录的查找概率相等，即Pi=1/n，查找成功时的平均查找长度ASL：ASL=[(n+1)/n]log2(n+1)-1  
### 分块查找
分块查找(Blocking Search)又称索引顺序查找，是前面两种查找方法的综合。
1. 将查找表分成几块。块间有序，即第i+1块的所有记录关键字均大于(或小于)第i块记录关键字；块内无序。
2. 在查找表的基础上附加一个索引表，索引表是按关键字有序的。  













