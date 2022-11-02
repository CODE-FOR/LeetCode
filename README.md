# LeetCode题目记录

## PART1 动态规划

### 152.乘积最大子数组
[link](https://leetcode.cn/problems/maximum-product-subarray/)

#### 1.从前缀的角度考虑

可以参考[53.最大子数组和](https://leetcode.cn/problems/maximum-subarray/)的前缀和解法和思路，会遇到问题，当`prefix[i]`和`prefix[j]`都等于`0`时，无法通过除法计算`product-subarray[i][j]`

#### 2.动态规划

同样可以参考上面题目的动态规划思路，但是要对正负情况分类讨论。

- 当前数字为负数时

  $maxProductSubarray[i]=minProductSubarray[i-1]>1\;?\;nums[i]\;:\;minProductSubarray[i-1]*nums[i]$

- 当前数字为正数时

  $maxProductSubarray[i]=maxProductSubarray[i-1]<1\;?\;nums[i]\;:\;maxProductSubarray[i-1]*nums[i]$

因此需要记录`max`和`min`的子序列乘积。

`min`的情况相当简单，负数时，将该负数取反，计算正数情况下的最大值，再取反即得到最小值；正数时同理。


### 198.打家劫舍

[link](https://leetcode.cn/problems/house-robber/)

#### 1.动态规划

**动态规划的核心**：找到可能的前驱(找到可能的后继)，然后自底向上。

题目的核心点在于不能连续盗取相邻的房屋，因此在到达房屋$i$时:
- 盗窃$i$，说明没有盗窃$i-1$
- 不盗窃$i$，盗不盗窃$i-1$都可以

于是有
$$
    \left\{
    \begin{array}{lr}
    dp[i][0] = max(dp[i-1][0],dp[i-1][1]) \\ 
    dp[i][1] = dp[i-1][0] + a[i]
    \end{array}
    \right.
$$

### 212.打家劫舍II

[link](https://leetcode.cn/problems/house-robber-ii/)

#### 1.动态规划

和[打家劫舍](##198.打家劫舍)的区别仅在于首尾是否连接

- 当盗窃最后一家时，说明没有盗窃第一家
- 当不盗窃最后一家时，第一家盗不盗窃无所谓

因此$dp[last][0]$的计算方式不变，$dp[last][1]$则抛弃第一家，从第二家开始考虑既不用考虑首位相接的问题，可以按照之前的计算方式计算。


### 221.最大正方形

[link](https://leetcode.cn/problems/maximal-square/submissions/)

#### 1.动态规划

关键在于如何**切分正方形**。

![image-split-square](./assets/4c781645c96f76446dd9a29b7dc5044.jpg)

可以看出
$$
  dp[i][j]=1+min
  \left\{
  \begin{array}{lr}
  dp[i-1][j-1]\\
  dp[i][j-1]\\
  dp[i-1][j]
  \end{array}
  \right.
$$


## PART2 数据结构

### 203.移除链表元素

[链接](https://leetcode.cn/problems/remove-linked-list-elements/)

可以通过使用`dummy_head`来简化边缘判断的操作。

$dummy\_head \rightarrow real\_head$

### 19.删除链表的倒数第 N 个结点

[链接](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

没有什么能节省时间复杂度的方法，遍历一次获取长度。

### 21.合并两个有序链表

[链接](https://leetcode.cn/problems/merge-two-sorted-lists/)

### 206.反转链表

[链接](https://leetcode.cn/problems/reverse-linked-list/)

注意反转链表的最后一个元素是原链表的第一个元素，如果原链表的长度超过1，说明第一个元素有后继，一定要让原第一个(反转后最后一个)元素的`next`为空，否则形成一个循环节。

```mermaid
graph LR;

first-->second
second-->first

```

### 92.反转链表II

[链接](https://leetcode.cn/problems/reverse-linked-list-ii/)

#### 1.一次遍历的方法

整体思想是：在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置。下面的图展示了整个流程。

<img src="./assets/1615105242-ZHlvOn-image.png" style="zoom:50%;"/>


### 24.两两交换链表中的节点

交换的关键在于$\rightarrow next$,改变`指针`本身不能完成链表结点顺序的交换，关键在于改变前后链接的关系。

### 430.扁平化多级双向链表

[链接](https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list)

#### 1.使用stack

在找到含`child`的节点时就将该节点的`next(非空)`纳入`stack`中。相当于将递归方法使用栈实现。

### 445.两数相加II

[链接](https://leetcode.cn/problems/add-two-numbers-ii/solution/)

#### 1.使用stack

没有什么难点，理解cin不会超过1的原理即可，使用数学归纳法: 
> 第一位加法，假设最后两位都是9，和是18，cin为1，也就是说在最开始cin最大是1
> 假设cin最大不超过1，每一位计算最大为9+9+1=19,cin依然没超过1


### 23.合并K个升序链表

[链接](https://leetcode.cn/problems/merge-k-sorted-lists/)

#### 1.使用优先队列

结合`链表`与优先队列的特点，`链表`的一大特点就是根据当前节点不借助任何其他信息就可以得到其后继节点！！！
因此可以通过`优先队列`有效节省寻找当前开头最小的队列的问题，而且不会丢失后继。
