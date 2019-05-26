# 斐波那契数列

## 定义

Fib[0] = 0, Fib[1] = 1
对 i>=2, Fib[i] = Fib[i - 1] + Fib[i - 2]

## 通项公式
Fib[n] = 1/sqrt(5) * [((1+sqrt(5))/2)^n - ((1-sqrt(5))/2)^n]

## 斐把那契数列性质

1. gcd(Fib[n], Fib[n-1]) = 1
2. Fib[n + m] = Fib[n-1]Fib[m] +  Fib[n]Fib[m+1]
```m=1,m=2成立,数学归纳m>=3的情况```
3. gcd(Fib[n+m],Fib[n]) = gcd(Fib[n],Fib[m])
```通过性质2证明```
4. gcd(Fib[n], Fib[m]) = F[gcd(n, m)]
```通过性质3证明```

## 模周期性

对斐波那契进行取模，会得到一个周期数列

### 性质

设p是奇质数
当5是p的二次剩余时有 g(p) | p - 1
当5时p的二次非剩余时有 g(p) | 2(p + 1)

g(p^k) = g(p) * p^(k-1)

设 g(n) 表示 斐波那契数列对n取模后的数列的最小周期

n = p1^k1 \* p2^k2 \* ... \* pm^km
g(n) = lcm(g(p1^k1), g(p2^k2), ... , g(pm^km))