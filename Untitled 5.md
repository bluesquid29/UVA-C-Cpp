## C++ 陣列類型比較

|           | C-Style Array                           | `std::array`                | `std::vector`               |
| --------- | --------------------------------------- | --------------------------- | --------------------------- |
| **大小**    | 固定（編譯期決定）                               | 固定（編譯期決定）                   | 動態（執行期可變）                   |
| **記憶體效率** | 較高                                      | 較高                          | 較低（擴容時可能 2 倍成長）             |
| **複製**    | 需逐元素或用 `std::copy()`                    | 直接賦值：`a2 = a1;`             | 直接賦值：`v2 = v1;`             |
| **傳入函式**  | 退化為指標（失去 size 資訊），或用 `std::span`        | 傳值，或用 `std::span`           | 傳值，或用 `std::span`           |
| **取得大小**  | `sizeof a / sizeof *a` 或 `std::size(a)` | `a.size()` 或 `std::size(a)` | `v.size()` 或 `std::size(v)` |
| **適用情境**  | 快速存取、不常增加刪減元素                           | 同 C 陣列但更安全、易複製與傳遞           | 需要動態增刪元素時                   |

---

### 重點說明

**C-Style Array 的陷阱**

```cpp
void Foo(int arr[]) {
    // sizeof(arr) 是指標大小，不是陣列大小！
    int sz = sizeof arr / sizeof *arr; // ❌ 錯誤
}
```

傳入函式後 size 資訊消失，這是最常見的 bug 來源。

**`std::array`：C 陣列的安全替代**

```cpp
std::array<int, 5> a1 = {1, 2, 3, 4, 5};
std::array<int, 5> a2 = a1; // ✅ 直接複製
std::println("{}", a1.size()); // 5
```

大小是型別的一部分：`array<int, 5>` 和 `array<int, 6>` 是**不同型別**。

**`std::vector`：動態擴容機制**

```cpp
vector<int> v;
v.reserve(100); // 預先配置，避免多次 reallocation
```

每次超出容量時容量 ×2，頻繁 push_back 但未 reserve 會造成效能損耗。

---

### 競賽選用建議

- 大小固定、追求效能 → **C-Style Array** 或 `std::array`
- 需要動態增刪、或大小不確定 → **`std::vector`**
- 傳函式且需保留 size → 優先 `std::array` 或 `std::vector`