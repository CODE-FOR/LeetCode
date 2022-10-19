# LeetCode题目记录

## 152.乘积最大子数组
[link](https://leetcode.cn/problems/maximum-product-subarray/)

### 1.从前缀的角度考虑

可以参考[53.最大子数组和](https://leetcode.cn/problems/maximum-subarray/)的前缀和解法和思路，会遇到问题，当`prefix[i]`和`prefix[j]`都等于`0`时，无法通过除法计算`product-subarray[i][j]`

### 2.动态规划

同样可以参考上面题目的动态规划思路，但是要对正负情况分类讨论。

- 当前数字为负数时

  $maxProductSubarray[i]=minProductSubarray[i-1]>1\;?\;nums[i]\;:\;minProductSubarray[i-1]*nums[i]$

- 当前数字为正数时

  $maxProductSubarray[i]=maxProductSubarray[i-1]<1\;?\;nums[i]\;:\;maxProductSubarray[i-1]*nums[i]$

因此需要记录`max`和`min`的子序列乘积。

`min`的情况相当简单，负数时，将该负数取反，计算正数情况下的最大值，再取反即得到最小值；正数时同理。


## 198.打家劫舍

[link](https://leetcode.cn/problems/house-robber/)

### 1.动态规划

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

## 212.打家劫舍II

[link](https://leetcode.cn/problems/house-robber-ii/)

### 1.动态规划

和[打家劫舍](##198.打家劫舍)的区别仅在于首尾是否连接

- 当盗窃最后一家时，说明没有盗窃第一家
- 当不盗窃最后一家时，第一家盗不盗窃无所谓

因此$dp[last][0]$的计算方式不变，$dp[last][1]$则抛弃第一家，从第二家开始考虑既不用考虑首位相接的问题，可以按照之前的计算方式计算。


## 221.最大正方形

[link](https://leetcode.cn/problems/maximal-square/submissions/)

### 1.动态规划

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