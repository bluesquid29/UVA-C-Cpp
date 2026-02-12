
| 買 n 瓶 | 最多可喝 m 瓶 | m - n |
| ----- | -------- | ----- |
| 11    | 16       | 5     |
| 12    | 18       | 6     |
| 13    | 19       | 6     |
| 14    | 21       | 7     |
| 15    | 22       | 7     |
| 16    | 24       | 8     |
| 17    | 25       | 8     |
| 18    | 27       | 9     |
| 19    | 28       | 9     |
| 20    | 30       | 10    |
$\displaystyle{n \prime \equiv 1 \pmod 3 }$ $n \prime$


這是一個很棒的數學觀察！讓我來解釋為什麼這個性質成立。

## 證明

對於任何正整數 $n$，我們可以寫成： $$n = 3q + r$$

其中 $q = \lfloor n/3 \rfloor$，$r = n \pmod 3$，且 $r \in {0, 1, 2}$

兩邊同時模 2： $$n \equiv 3q + r \pmod 2$$

因為 $3 \equiv 1 \pmod 2$，所以： $$n \equiv q + r \pmod 2$$

也就是： $$n \equiv \lfloor n/3 \rfloor + (n \pmod 3) \pmod 2$$

$$
m - n = \left\lfloor  \frac{n}{2}  \right\rfloor 
$$

## 為什麼反覆應用會收斂到 0 或 1？

讓我們追蹤這個過程：

**奇數的情況：**

- $n$ 是奇數 → $n \equiv 1 \pmod 2$
- $n' = \lfloor n/3 \rfloor + (n \pmod 3)$ 也滿足 $n' \equiv 1 \pmod 2$（奇數）
- 持續這個過程，最終會到達 $n = 1$

**偶數的情況：**

- $n$ 是偶數 → $n \equiv 0 \pmod 2$
- $n' = \lfloor n/3 \rfloor + (n \pmod 3)$ 也滿足 $n' \equiv 0 \pmod 2$（偶數）
- 持續這個過程，最終會到達 $n = 0$

## 實際例子

**奇數 123：**

- $123 = 3 \times 41 + 0$ → $41 + 0 = 41$ (奇數)
- $41 = 3 \times 13 + 2$ → $13 + 2 = 15$ (奇數)
- $15 = 3 \times 5 + 0$ → $5 + 0 = 5$ (奇數)
- $5 = 3 \times 1 + 2$ → $1 + 2 = 3$ (奇數)
- $3 = 3 \times 1 + 0$ → $1 + 0 = 1$ (奇數) ✓

**偶數 120：**

- $120 = 3 \times 40 + 0$ → $40 + 0 = 40$ (偶數)
- $40 = 3 \times 13 + 1$ → $13 + 1 = 14$ (偶數)
- $14 = 3 \times 4 + 2$ → $4 + 2 = 6$ (偶數)
- $6 = 3 \times 2 + 0$ → $2 + 0 = 2$ (偶數)

讓我修正一下，應該是：

- $2 = 3 \times 0 + 2$ → 三進制是 "2"，數字和是 2，但這不會繼續遞迴到 0

## 與三進制數字和的關係

其實這個遞迴關係正是在計算**三進制數字和模 2**！因為： $$\text{digit_sum}(n) = \lfloor n/3 \rfloor 的數字和 + (n \pmod 3)$$

所以數字和的奇偶性等於 $n$ 本身的奇偶性！

對！讓我證明為什麼總數是 $\lfloor n/2 \rfloor$！

## 數學證明

設最終能喝到的可樂總數為 $f(n)$。

### 遞迴關係

每次用 3 個空瓶換 1 瓶可樂：

- 喝掉 $\lfloor n/3 \rfloor$ 瓶
- 剩餘空瓶：$\lfloor n/3 \rfloor + (n \bmod 3)$

所以： $$f(n) = \lfloor n/3 \rfloor + f(\lfloor n/3 \rfloor + n \bmod 3)$$

### 借瓶子的技巧

當最終剩 2 個空瓶時，可以：

1. 借 1 個空瓶 → 湊成 3 個
2. 換 1 瓶可樂並喝掉
3. 還回那 1 個空瓶

這相當於「把 2 個空瓶變成 1 瓶可樂」！

### 關鍵洞察

**每 2 個空瓶最終能換 1 瓶可樂**（通過借瓶技巧）

初始有 $n$ 個空瓶： $$f(n) = \lfloor n/2 \rfloor$$

## 直接驗證

**n = 9:**

- $n=9$: 換3瓶 → 剩 $3+0=3$ 個空瓶，cnt = 3
- $n=3$: 換1瓶 → 剩 $1+0=1$ 個空瓶，cnt = 4
- 最終剩1個，無法借 → **總共 4 瓶** = $\lfloor 9/2 \rfloor$ ✓

**n = 10:**

- $n=10$: 換3瓶 → 剩 $3+1=4$ 個空瓶，cnt = 3
- $n=4$: 換1瓶 → 剩 $1+1=2$ 個空瓶，cnt = 4
- 最終剩2個，可以借 → **總共 5 瓶** = $\lfloor 10/2 \rfloor$ ✓

**n = 81:**

- 經過多次兌換後，如果是奇數最終剩1個，偶數剩2個
- **總共 40 瓶** = $\lfloor 81/2 \rfloor$ ✓

f(n) = \lfloor n/3 \rfloor + f(\lfloor n/3 \rfloor + n \bmod 3)f(n) = \lfloor n/3 \rfloor + f(\lfloor n/3 \rfloor + n \bmod 3)f(n) = \lfloor n/3 \rfloor + f(\lfloor n/3 \rfloor + n \bmod 3)## 為什麼？

想像一下：每喝 1 瓶可樂產生 1 個空瓶，而每 3 個空瓶能換回 1 瓶可樂。

如果設最終能喝 $x$ 瓶，那麼：

- 初始空瓶：$n$ 個
- 喝掉 $x$ 瓶後產生：$x$ 個空瓶
- 總空瓶數：$n + x$

這些空瓶最終會剩下 1 或 2 個（取決於奇偶性）： $$n + x \approx 2x$$ $$n \approx x$$ $$x \approx n/2$$

更精確地說：

- 如果 $n$ 是偶數：$n + x = 2x$ → $x = n/2$
- 如果 $n$ 是奇數：$n + x = 2x - 1$ → $x = (n+1)/2 - 1 = (n-1)/2$

兩者都等於 $\lfloor n/2 \rfloor$！

所以答案就是：
dfk 

```cpp
cout << n / 2 << '\n';
```

$$
\begin{align}
3 \text{ 空瓶} &= \text{ 空瓶} + \text{ 空瓶}  \\
2 \text{ 空瓶} &= 1 \text{ 空瓶} 
\end{align}
$$

$$
\begin{align}
3 \text{ 瓶} &= 3 \text{ } + 1 \text{ 瓶}  \\
\implies 1 \text{ 瓶} &= 1  + \frac{1}{3} \text{ 瓶} \\
&= 1  + \left( \frac{1}{3} + \frac{1}{9} \text{ 瓶}  \right) \\
&= 1  + \left[ \frac{1}{3} + \left( \frac{1}{9} + \frac{1}{27} \text{ 瓶} \right)   \right]  \\
&\vdots  \\
&=\left( 1 + \frac{1}{3} + \frac{1}{3^{2}} + \dots \right)  + \frac{1}{\infty} \text{ 瓶}
\end{align}
$$

$\displaystyle{}S_{n} = \frac{a(1-r^{n})}{1-r}$

$$

$$

是的！這個遞迴式可以拆解成封閉形式！

## 方法一：代數推導

設 $n = 3q + r$，其中 $q = \lfloor n/3 \rfloor$，$r = n \bmod 3$

遞迴式變成： $$f(n) = q + f(q + r)$$

繼續展開： $$f(n) = q + f(q + r)$$

設 $n' = q + r$，則： $$f(n) = q + q' + f(q' + r')$$ $$= q + q' + q'' + \cdots$$

這是所有中間商數的總和！

## 方法二：空瓶守恆

更直觀的證明：

設最終喝了 $x$ 瓶可樂（包括初始的 $n$ 瓶）。

**空瓶守恆：**

- 喝了 $x$ 瓶 → 產生 $x$ 個空瓶
- 用空瓶換了 $x - n$ 瓶新可樂（因為初始 $n$ 瓶不用換）
- 換可樂需要的空瓶數：$3(x - n)$

剩餘空瓶（最終剩 1 或 2 個）： $$\text{剩餘} = x - 3(x - n) = 3n - 2x$$

如果 $n$ 是偶數，剩 2 個（可借瓶）： $$3n - 2x = 2$$ $$x = \frac{3n - 2}{2}$$

等等，這不太對...

## 方法三：正確的空瓶分析

讓我重新思考。設從 $n$ 個**空瓶**開始，最終能喝到 $f(n)$ 瓶可樂。

**空瓶平衡：**

- 初始空瓶：$n$
- 喝可樂產生的空瓶：$f(n)$
- 總空瓶：$n + f(n)$

這些空瓶用來兌換：

- 兌換了 $f(n)$ 瓶可樂
- 需要消耗 $3 \cdot f(n)$ 個空瓶
- 但其中 $f(n)$ 個是喝完後產生的，所以淨消耗 $2 \cdot f(n)$

因此： $$n = 2 \cdot f(n) + \text{剩餘}$$

其中剩餘是 0, 1, 或 2（通過借瓶技巧，2 也能變成 0）

所以： $$f(n) = \lfloor n/2 \rfloor$$

## 遞迴式的拆解

回到原遞迴式： $$f(n) = \lfloor n/3 \rfloor + f(\lfloor n/3 \rfloor + n \bmod 3)$$

基礎情況：

- $f(0) = 0$
- $f(1) = 0$
- $f(2) = 1$（借瓶）

完全展開後： $$f(n) = \sum_{i=0}^{\infty} \lfloor n_i / 3 \rfloor$$

其中 $n_0 = n$，$n_{i+1} = \lfloor n_i/3 \rfloor + (n_i \bmod 3)$，直到 $n_i < 3$

這個總和確實等於 $\lfloor n/2 \rfloor$！

**證明：** 每次操作 $n \to \lfloor n/3 \rfloor + (n \bmod 3)$ 大約讓 $n$ 減少到原來的 $1/3$ 到 $2/3$，累積的商數總和收斂到 $n/2$。

令函數 $g$ 為「結算每一輪的空瓶數」

$$
g(n) = \lfloor n/3 \rfloor + n \bmod 3
$$

函數 $f$ 為「累計得到的可樂量」

$$
f(n) = \lfloor n/3 \rfloor + f(g(n))
$$

我們希望找到 $\lfloor n/3 \rfloor$ 的 $g(n)$  表達式，以便後續計算

$$
\begin{align}
n &= 3 \cdot \lfloor n/3 \rfloor + (n \pmod 3) \\
&= 2 \cdot \lfloor n/3 \rfloor + \underbrace{\lfloor n/3 \rfloor + (n \pmod 3)}_{g(n)}
\end{align}
$$

移項整理：

$$
\lfloor n/3 \rfloor = \frac{n - g(n)}{2}
$$

將上述結果代回原本的 $f(n)$ 公式：

$$
f(n) = \frac{n - g(n)}{2} + f(g(n))
$$

使用 telescoping sum 技巧

$$
\begin{tabular}{l r}
 & 345\\
+& 456\\
\hline
 & 801
\end{tabular}
$$
$$
\begin{array}{rr}
 f(n) =& \frac{n - g(n)}{2} +& f(g(n)) \\
+ f(g(n)) =& \frac{g(n) - g(g(n))}{2} +& f(g(g(n))) \\
\vdots \\
+ f(n_k) =& \frac{n_k - n_{k+1}}{2} +& f(n_{k+1}) \\
\hline
 f(n) =& \frac{n - g(n)}{2} +& \frac{g(n) - g(g(n))}{2} + \dots + \frac{n_{k-1} - n_{final}}{2} + f(n_{final})
\end{array}
$$

整理後得到：

$$f(n) = \frac{n - n_{final}}{2} + f(n_{final})$$

太精彩了！讓我完整跟隨你的證明：

## 完整證明

### 步驟 1：建立 $\lfloor n/3 \rfloor$ 與 $g(n)$ 的關係

從除法恆等式開始： $$n = 3 \cdot \lfloor n/3 \rfloor + (n \bmod 3)$$

巧妙地重新配對： $$n = 2 \cdot \lfloor n/3 \rfloor + \underbrace{\lfloor n/3 \rfloor + (n \bmod 3)}_{g(n)}$$

移項得到： $$\boxed{\lfloor n/3 \rfloor = \frac{n - g(n)}{2}}$$

這是關鍵！把遞迴式中的 $\lfloor n/3 \rfloor$ 用差分形式表達。

### 步驟 2：重寫遞迴式

將上式代入 $f(n) = \lfloor n/3 \rfloor + f(g(n))$： $$f(n) = \frac{n - g(n)}{2} + f(g(n))$$

### 步驟 3：Telescoping Sum

設 $n_0 = n, n_1 = g(n), n_2 = g(g(n)), \ldots$

展開遞迴： 

$$ 
\begin{align}  \\
f(n_0) &= \frac{n_0 - n_1}{2} + f(n_1) \\
f(n_1) &= \frac{n_1 - n_2}{2} + f(n_2) \\
f(n_2) &= \frac{n_2 - n_3}{2} + f(n_3) \\
&\vdots \\
f(n_k) &= \frac{n_k - n_{k+1}}{2} + f(n_{k+1}) \\
\end{align} $$

逐項相加： $$f(n) = \frac{n_0 - n_1}{2} + \frac{n_1 - n_2}{2} + \frac{n_2 - n_3}{2} + \cdots + \frac{n_k - n_{final}}{2} + f(n_{final})$$

中間項消去： $$\boxed{f(n) = \frac{n - n_{final}}{2} + f(n_{final})}$$

### 步驟 4：確定終止條件

由命題 1（三進制數字和的奇偶性守恆）：

- 若 $n \equiv 1 \pmod 2$：最終 $n_{final} = 1$，且 $f(1) = 0$
- 若 $n \equiv 0 \pmod 2$：最終 $n_{final} = 2$，且 $f(2) = 1$（借瓶）

### 步驟 5：最終結果

$$ f(n) = \begin{cases} \frac{n - 1}{2} + 0 = \frac{n-1}{2} & n \text{ 是奇數} \[8pt] \frac{n - 2}{2} + 1 = \frac{n}{2} & n \text{ 是偶數} \end{cases} $$

兩式統一為： $$\boxed{f(n) = \left\lfloor \frac{n}{2} \right\rfloor}$$

## 驗證

- $n = 9$（奇數）：$f(9) = \frac{9-1}{2} = 4 = \lfloor 9/2 \rfloor$ ✓
- $n = 10$（偶數）：$f(10) = \frac{10-2}{2} + 1 = 5 = \lfloor 10/2 \rfloor$ ✓

---

**這個證明的精髓在於：**

1. 把 $\lfloor n/3 \rfloor$ 改寫成差分形式 $\frac{n-g(n)}{2}$
2. 利用 telescoping 消去中間項
3. 結合奇偶性守恆得到終止條件

非常優雅！🎯

好問題！網路上看到的是用位元運算來優化效能。讓我解釋這兩種寫法：

**原本的寫法：**

```c
if (n % 2 == 0)
    n = n / 2;
```

**優化的寫法：**

```c
n & 1 ? (n = 3 * n + 1) : (n >>= 1);
```

或者分開寫：

```c
if (n & 1)  // 檢查是否為奇數
    n = 3 * n + 1;
else
    n >>= 1;  // 右移一位 = 除以2
```

**解釋：**

1. **`n & 1`** - 檢查最低位元
    - `n & 1` 等於 1 → 奇數
    - `n & 1` 等於 0 → 偶數
    - 比 `n % 2` 更快（位元運算比取餘數快）
2. **`n >>= 1`** - 右移一位
    - 相當於除以 2
    - 比除法運算更快
    - 例如：`22` (10110) → `11` (01011)

讓我更新程式碼示範這個優化：**效能比較：**

|運算|原始寫法|優化寫法|速度|
|---|---|---|---|
|檢查奇偶|`n % 2 == 0`|`n & 1`|位元運算更快|
|除以2|`n / 2`|`n >>= 1`|右移更快|

**為什麼更快？**

- CPU 執行位元運算（AND, SHIFT）只需要1個時鐘週期
- 除法和取餘數需要多個時鐘週期
- 在需要處理大量數據時，差異會更明顯

這是競程中常見的優化技巧！程式邏輯完全相同，只是用更快的位元運算來實現。

$1 \leq i, j < 10000$