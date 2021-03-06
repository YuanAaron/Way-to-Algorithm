* [Upper Folder - 上一级目录](../../)
* [Source Code - 源码](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/CompleteKnapsack.hpp)
* [Test Code - 测试](https://github.com/zhaochenyou/Way-to-Algorithm/blob/master/src/DynamicProgramming/KnapsackDP/CompleteKnapsack.cpp)

--------

### Complete Knapsack
### 完全背包
<div>
问题：
<p id="i">你面前摆放着\(n\)种珠宝，每种都有无穷多个，已知珠宝\(s_i\)的价值是\(v_i\)，重量是\(w_i\)。给你一个背包，你可以自由挑选珠宝装到背包中，但背包可以装载的最大重量为\(t\)。求背包能够装载珠宝的最大价值\(v\)。 </p>
解法：
<p id="i">设\(f(i,j)\)为背包中放入前\(i\)件物品，重量不大于\(j\)的最大价值，其中\(i \in [1,n]\)，\(j \in [0,t]\)。有如下状态转移方程： </p>
\[
f(i,j) =
\begin{cases}
0 & (初始化)i \in [0,n],j \in [0,t] \\
max(f(i-1,j),f(i-1,j-k \times w_i) + k \times v_i) & i,j \gt 0,k \geq 0,j \geq k \times w_i
\end{cases}
\]
<p id="i">\((1)\)将\(f(i,j)\)全部初始化为\(0\)； </p>
<p id="i">\((2)\)对于第\(i\)件珠宝\(s_i\)，背包的剩余重量（还能装载的重量）为\(W\)，可以装进\(k\)个该珠宝（其中\(k \geq 0\)，且\(W \geq k \times w_i\)），那么背包的价值增大\(k \times v_i\)，剩余重量减小\(k \times w_i\)，即\(f(i,j) = f(i-1,j-k \times w_i) + k \times v_i\)；若不装入背包，则一切维持不变，即\(f(i,j) = f(i-1,j)\)。选择这两种情形中的最大值； </p>
<p id="i">\(f(n,t)\)即为\(n\)个珠宝中重量不超过\(t\)的最大价值。该算法的时间复杂度是\(O(n \times t^2)\)，因为状态转移方程中的参数\(k\)的规模与背包最大重量\(t\)线性相关。 </p>
</div>
