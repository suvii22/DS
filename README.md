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

### 二叉搜索树（BST）
ASL同二分查找，时间复杂度为O(log2(n))
- 结点左子树上所有关键字小于结点关键字
- 右子树上所有关键字大于结点关键字
- 如果对一棵二叉搜索树进行中序遍历，可以按从小到大的顺序，将各结点关键字排列起来，所以也称二叉搜索树为二叉排序树  

__查询__:  
```
TREE-SEARCH(x, k)
    if x == nil or k == x.key  //如不存在或者找到，直接返回
        return x
    if k < x.key                    //如果小于当前节点，根据性质，在左子树中搜索
        return TREE-SEARCH(x.left, k)
    else                          //如果大于等于当前节点，根据性质，在右子树中搜索
        return TREE-SEARCH(x.right, k)
```
__插入__：  
```
TREE-INSERT(T, z)
    y = nil
    x = T.root
    while x != nil //循环结束后，x一定为空，此时x即为节点z要插入的地方
        y = x    //在这里给y赋值，保证循环结束后y始终是x的父节点
        if z.key < x.key
            x = x.left
        else
            x = x.right
        z.p = y  //  y始终是x的父节点，为了插入z，需要让z的父节点指向x的父节点，即指向y
        if y == nil  //  如果y为空，说明插入时是一棵空的树，需要将树根指向z
            T.root = z
        elseif z.key < y.key   //  判断节点z是y的左孩子还是右孩子
            y.left = z
        else
            y.right = z
```
__删除__：  
为了实现删除过程的伪代码，我们需要定义一个子过程`TRANSPLANT`，它是用为了用以`v`为根的子树替换以`u`为根的子树，让`u`的双亲节点变为`v`的双亲节点，即让`v`称为`u`的双亲节点的孩子：  
```
TRANSPLANT(T, u, v)
    if u.p == nil   // 当u为树的根节点时，直接将树的根节点指向v
        T.root = v
    elseif u == u.p.left   // 如果u是左孩子，则u的父节点的左孩子指向v
        u.p.left = v
    else    // 如果u是右孩子，则u的父节点的右孩子指向v
        u.p.right = v
    if v != nil   
        v.p = u.p    // 将v的父节点设为u的父节点

```
然后实现具体的删除过程：  
```
TREE-DELETE(T, z)
    if z.left == nil  // 如果左孩子为空，则直接用右孩子代替z即可，而不管右孩子是否为空（右孩子为空时对应情况一否则对应情况二）
        TRANSPLANT(T, z, z.right)
    elseif z.right == nil  // 右孩子为空，直接用左孩子代替z
        TRANSPLANT(T, z, z.left)
    else y = TREE-MINIMUM(z.right)  // 左右孩子均不为空，找到z的后继y，即z的右子树的最小值，对应第三种情况
        if y.p != z   // 如果z的后继y不是z的右孩子，对应第三种情况的2
            TRANSPLANT(T, y, y.right)  // 用y的右孩子代替y
            y.right = z.right    // 将y的右孩子指向z的右孩子
            y.right.p = y     // 将y的右孩子(原来的z的右孩子)的父节点设为y
        TRANSPLANT(T, z, y)  // 用y代替z
        y.left = z.left
        y.left.p = p
```        
因此总的来说，删除操作可以分为两大类：  
1. z的孩子总数小于2时，直接用z的孩子代替z即完成了对z的删除。
2. z有两个孩子时：  
2.1. z的后继y是z的右孩子：直接用y代替z即可（别忘了将z的左孩子的父节点设置为y）。  
2.2. z的后继y不是z的右孩子：先用y的右孩子x代替y，再用y代替z。  

### 平衡二叉排序树（AVL）
平衡二叉树或者是空树，或者是满足下列性质的二叉树。
1. 左子树和右子树深度之差的绝对值不大于1；
2. 左子树和右子树也都是平衡二叉树。  

平衡因子(Balance Factor) ：二叉树上结点的左子树的深度减去其右子树深度称为该结点的平衡因子。  
因此，平衡二叉树上每个结点的平衡因子只可能是-1、0和1，否则，只要有一个结点的平衡因子的绝对值大于1，该二叉树就不是平衡二叉树。  

__平衡化旋转__：
一般的二叉排序树是不平衡的，若能通过某种方法使其既保持有序性，又具有平衡性，就找到了构造平衡二叉排序树的方法，该方法称为平衡化旋转。  
在对AVL树进行插入或删除一个结点后，通常会影响到从根结点到插入(或删除)结点的路径上的某些结点，这些结点的子树可能发生变化。以插入结点为例，影响有以下几种可能性：
- 以某些结点为根的子树的深度发生了变化； 
- 某些结点的平衡因子发生了变化；
- 某些结点失去平衡。  

__左单旋__：
```
void  LL_rotate(BSTNode *treeRoot){  
   BSTNode *b ;
    b = treeRoot->Lchild ;
    treeRoot->Lchild=b->Rchild ;
    b->Rchild=treeRoot ;
    treeRoot=b ;
}
```
__右单旋__：
```
void  RR_rotate(BSTNode *treeRoot){  
   BSTNode *b ;
    b = treeRoot->Rchild ;
    treeRoot->Rchild=b->Lchild ;
    b->Lchild=treeRoot ;
    treeRoot=b ;
}
```
__AVL的插入__：TODO  

### B树
B 树是平衡的多路查找树，在文件系统中很有用。一棵m阶B树或者是空树, 或是满足下列性质的树：
1. 树中每个结点至多有m 棵子树
2. 若根结点不是叶子结点，则至少有 2 个子树
3. 除根结点以外的所有非终端结点至少有Math.ceil(m/2)-1个子女
4. 所有的非终端结点包含下列信息数据：(n, P0, K1, P1, K2, P2, ……, Kn, Pn)，其中，Pi是指向子树的指针，0≤i≤n<m。Ki是关键字，1≤i≤n<m。Ki<Ki+1, 1≤i<n。在子树 Pi 中所有的关键字都小于Ki+1，且大于 Ki。且Math.ceil(m/2)-1≤n≤m-1，n+1为子树的棵数
5. 所有叶子结点都出现在同一层次上，并且不带信息  

__查找__：  
B树上进行查找的基本操作：
- 在B树中找结点
- 在结点中找关键字  

B树上进行查找效率由待查关键字所在结点的层次数l 决定；根据B树定义，第一层至少有1个结点，第二层至少有2个结点；由于除根之外每个非终端结点至少有Math.ceil(m/2)棵子树，则第三层至少有2Math.ceil(m/2))个结点，依次类推，第l+1层至少有2(Math.ceil(m/2))^(l-1)个结点。若m阶B树中具有N个关键字，则叶子结点即查找不成功的结点为N+1。由此有：N+1 ≥ 2* (Math.ceil(m/2))^(l-1)。 *l ≦ 1+logMath.ceil(m/2)((N+1)/2)*  

__插入__：TODO  
__删除__：TODO  

### B+树
一棵m阶B+树是B树的特殊情形，但使用更为广泛，它与B树的不同之处在于：
- 所有关键字都存放在叶结点中，上层的非叶结点的关键字是其子树中最小（或最大）关键字的复写。
- 叶结点包含了全部关键字及指向相应数据记录存放地址的指针，且叶结点本身按关键字从小到大顺序链接。  

每个非叶结点结构有两种方式处理。按下层结点“最大关键字复写”和“最小关键字复写”。  

__插入__：TODO  
__删除__：TODO  

### 散列表（Hash Table）
Hash函数的限制：
1. Hash把大范围映射到小范围；所以，输入的实际值的个数必须和小范围相当或者比它更小。不然冲突就会很多
2. 由于Hash逼近单向函数；所以，可以用它来对数据进行加密
3. 不同的应用对Hash函数有着不同的要求；比如，用于加密的Hash函数主要考虑它和单项函数的差距，而用于查找的Hash函数主要考虑它映射到小范围的冲突率  

称这些产生冲突的散列地址相同的不同关键字为同义词。  

构造散列函数时的几点要求：
- 散列函数应是简单的，能在较短的时间内  计算出结果
- 散列函数的定义域必须包括需要存储的全部关键字，如果散列表允许有 m 个地址时，其值域必须在 0 到 m-1 之间
- 散列函数计算出来的地址应能均匀分布在整个地址空间中 : 若 key 是从关键字集合中随机抽取的一个关键字,  散列函数应能以同等概率取0 到 m-1 中的每一个值  

哈希表处理冲突的方法：
1. 开放定址法 Hi = ( H(key) + di ) % m  i = 1, 2, …, k (k < m)  di 称为增量序列 ，m为哈希表长度  
线性探查法：di = 1, 2, 3, …, m-1  二次探查法：di = 1^2, -1^2, 2^2, -2^2…, + k^2, -k^2 ( k < m / 2)  伪随机探查法：di = 伪随机数序列
2. 再哈希法
3. 链地址法  

## 排序（sorting）
### 插入排序
```
void insertionSort(int[] arr) 
{ 
    for (int i = 1; i < length; i++) 
    { 
        int j = i; 
        while (j > 0 && arr[j] < arr[j - 1])     
        { 
            swap(arr,j,j-1); j--; 
        }
    }
}
```
### 折半插入排序
```
void BInsertSort(SqList &L) {// 对顺序表L作折半插入排序。
    int i,j,high,low,m;
    for (i=2; i<=L.length; ++i) {
        L.r[0] = L.r[i];       // 将L.r[i]暂存到L.r[0]
        low = 1;   high = i-1;
        while (low<=high) {    // 在r[low..high]中折半查找有序插入的位置
            m = (low+high)/2;                            // 折半
            if (LT(L.r[0].key, L.r[m].key)) high = m-1;  // 插入点在低半区
            else  low = m+1;                             // 插入点在高半区
        }
        for (j=i-1; j>=high+1; --j) L.r[j+1] = L.r[j];  // 记录后移
        L.r[high+1] = L.r[0];                           // 插入
    }
} // BInsertSort
```
### 二路插入排序
### 希尔排序 
```
void ShellInsert(SqList &L, int dk) {
// 对顺序表L作一趟希尔插入排序。
    int i,j;
    for (i=dk+1; i<=L.length; ++i) { // L.r[0]作为交换区
        if (LT(L.r[i].key, L.r[i-dk].key)) {
            L.r[0] = L.r[i]; 
            for (j=i-dk; j>0 && LT(L.r[0].key, L.r[j].key); j-=dk){
                L.r[j+dk] = L.r[j]; 
            }
      L.r[j+dk] = L.r[0]; // 插入
    }
} // ShellInsert

void ShellSort(SqList &L, int dlta[], int t) {
    // 按增量序列dlta[0..t-1]对顺序表L作希尔排序
    for (int k=0; k<t; ++k) {
        ShellInsert(L, dlta[k]);
    }
} // ShellSort

```
### 冒泡排序
```
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
        for (i = 0; i < n - 1 - j; i++)
        {
            if(a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
}

```
### 快速排序
TODO





















