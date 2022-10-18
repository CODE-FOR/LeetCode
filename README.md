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