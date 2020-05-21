<!-- TOC -->

- [Matlab中的常用API](#matlab中的常用api)
    - [diff](#diff)
    - [](#)

<!-- /TOC -->

# Matlab中的常用API

## diff

* 求差分：

<a href = "https://blog.csdn.net/u013018721/article/details/37766187">链接</a>

* 求导：

``` matlab
syms x y
f = x*con(y)
diff(f,x,1) >> ans = cos(y)
diff(f,x,2) >> ans = 0
```

总结：当使用diff求倒数时，第一个是函数，第二个是对哪个参数求导，第三个是求几阶倒数
## 
