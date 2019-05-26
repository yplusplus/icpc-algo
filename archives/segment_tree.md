# 线段树

## 普通线段树

## 持久化线段树

## 一些技巧

### 扫描线

矩形面积并、周长并

### 线段树合并

当确定了元素个数n或者key的范围[1, U]，那么建出的线段树形态是固定且唯一的。
当对相同形态的线段树进行参数相同的更新或者查询，所访问到的线段树节点也是一致的。

因此，我们可以通过以下过程来合并两个相同形态的线段树：
```python
def merge(a, b):
    if not a: return b
    if not b: return a
    if isleaf(a) and isleaf(b): return merge_leaf(a, b)
    return connect(merge(a.left, b.left), merge(a.right, b.right))
```

为了方便确定一个线段树节点是否为空，可以采用动态开辟节点。
如果`merge_leaf`和`connect`的时间复杂度都是O(1)，那么容易看出merge的时间复杂度是common_nodes(a, b), common_nodes(a, b)表示a和b两个线段树的公共节点数。

由此可以得到一个有用的结论：
若有n棵单元素的线段树，经过n-1次merge合并成一颗n个元素的线段树的时间复杂度是O(nlogn)。
证明：
每次调用merge都会减少common_nodes(a, b)个节点，而总节点数只有nlogn个，所以合并成一棵线段树的时间复杂度只有O(nlogn)。

于是我们可以写出一种以合并操作为核心的线段树：
关键操作：
+ make_leaf
+ connect
+ merge
+ merge_leaf
+ split：按某一个元素为基准分裂成两颗线段树

对于split操作，因为线段树进行单点操作只会访问到严格O(logn)个线段树节点，所以能在O(logn)完成split操作，并且会新增common_nodes(a, b)个节点，a和b分别是分裂后的两个线段树。

对于很大一部分需要维护有序序列的情况，一般是用平衡树的启发式合并来解决，时间复杂度是O(nlog^2n)。
如果关键字不是很大并且预先知道范围，可以利用线段树合并做到O(nlogn)或者O(nlogU)。

### 线段树优化区间建图

利用一个区间只会对应于logn级别个线段树节点这个性质。

### 李超树
