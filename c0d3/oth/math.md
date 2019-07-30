### $A=${$x|0<ax+1 \le 5$} , $B=${$x|-\frac{1}{2}<x\le2$}

**(1)$A\subseteq B$**

​	则不等式$0<ax+1\le 5$的解集是集合$B$的子集

​	解不等式
$$
\left\{

\begin{aligned}

0<ax+1\\

ax+1<5

\end{aligned}

\right.
$$

 1. $a==0$

    显然不行.

 2. $a>0$

    解得$x\in (-\frac{1}{a},\frac{4}{a}]$，结合集合$B$中$x\in (-\frac{1}{2},2])$

    那么可以推出：
    $$
    \begin{cases}
    -\frac{1}{a}\ge-\frac{1}{2}\\
    \frac{4}{a}\le2
    \end{cases}
    $$
    解得$a\ge2$

	3. $a<0$

    解得$x\in[\frac{4}{a},-\frac{1}{a})$，类似地，可以得到：
    $$
    \begin{cases}
    \frac{4}{a}\ge -\frac{1}{2}\\
    -\frac{1}{a} \le2
    \end{cases}
    $$
    解得$a<-8$

综上，解得$a\in (-\infty,8)\cap[2,\infty)$

**(2)$B\subseteq A$**

​	类似(1)，分情况讨论：

 1. a>0，有
    $$
    \begin{cases}
    -\frac{1}{a}\le -\frac{1}{2}\\
    \frac{4}{a}\ge2
    \end{cases}
    $$
    $\therefore a\in (0,2]$

	2. $a==0$

    当然是可以der~

	3. $a<0$
    $$
    \begin{cases}
    \frac{4}{a}\le-\frac{1}{2}\\
    -\frac{1}{a}>2
    \end{cases}
    $$
    $\therefore -\frac{1}{2}<a<0$

综上，$a\in (-\frac{1}{2},2]$

~~啊写起来好累...~~