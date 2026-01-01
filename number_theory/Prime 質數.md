一道問題如下：

> 請問 1 - 100 的質數是？ 請用程式碼表達：

---

## Method 0 (人工篩選法)

在國中，我們都背過這個質數表：

```cpp
int prime[25] = {2, 3, 5, 7, 
				 11, 13, 17, 19, 
				 23, 29, 
				 31, 37, 
				 41, 43, 47, 
				 53, 59, 
				 61, 67, 
				 71, 73, 79, 
				 83, 89, 
				 97};
```

或是這樣的寫法：

```cpp
int prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 
			      1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 
			      0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 
			      1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
			      1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 
			      0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 
			      1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 
			      1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 
			      0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 
			      0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
```

輸出：

```cpp
for (int i = 0; i < 25; i++)
{
	printf("%d\n", prime[i])
}
```

## Method 1 (Sieve of Eratosthenes)

在還把質數表背起來前；我們有學：

1. 先將 100 開根號  = 10 ，代表我們只需要判斷 10 以內的因數
2. 0, 1 不是質數
3. 將 2 的倍數全部劃掉、接下來 3
	1. 發現 4 已經被劃掉了
4. 同理，劃掉 5 的倍數,
	1. 6 也被劃掉了
5. 同理，劃掉 7 的倍數
	1. 8 9 10也被劃掉了

動畫如下：

![](https://upload.wikimedia.org/wikipedia/commons/b/b9/Sieve_of_Eratosthenes_animation.gif)

因此剩下沒劃掉的都是質數

```cpp
void sieve()
{
    // Initialize: assume all are prime
    memset(prime, true, sizeof(prime));

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i <= 100; i++) 
    {
        if (prime[i]) // if i is still prime
        {
            for (int j = 2; i * j <= 100; j++) 
            {
                prime[i * j] = false;
            }
        }
    }
}
```

輸出：

```cpp
for (int i = 0; i < 100; i++) 
{
	if (prime[i])
	{
		printf("%d\n", i); 
	}
}
```

## Method 3 (最佳化)

其實 method 2 就夠用大部分的情境，但是你也可以盡可能優化它：

這個最佳化版本達成了：

1. ✅ 只處理奇數（外層減半）
2. ✅ 從 i² 開始（避免重複）
3. ✅ 跳過偶數倍（內層減半）

```cpp
void sieve()
{
    // 初始化：假設所有數都是質數
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    
    // 單獨處理質數 2：篩掉所有偶數
    for (int j = 4; j <= 100; j += 2)
    {
        prime[j] = false;
    }
    
    // 只處理奇數質數（從 3 開始，每次 +2）
    for (int i = 3; i * i <= 100; i += 2) 
    {
        if (prime[i]) // 確認 i 還是質數
        {
            // 從 i² 開始篩（更小的倍數已被篩過）
            // 每次加 2i 跳過偶數倍（偶數已被 2 篩過）
            for (int j = i * i; j <= 100; j += i + i) 
            {
                prime[j] = false;
            }
        }
    }
}
```

# 比較

找出 1 到 100000000 的質數：Method 3  的優勢就出來了

```
[11:09:03] [Runner[1]] [Execution has started]
[11:09:04] [Runner[1]] [Execution for test case #1 has finished in 1117ms]
```

```
[11:13:35] [Runner[1]] [Execution has started]
[11:13:36] [Runner[1]] [Execution for test case #1 has finished in 773ms]
```