---
<%*
// 1. 取得父資料夾名稱 (例如 "10666-The_Eurocup_is_Here!")
let folderName = tp.file.folder(false);

// 2. 切分 ID 與 標題
let parts = folderName.split('-');
let probID = parts[0] || "00000";

// 3. 處理標題：取出 '-' 後面文字，並將底線 '_' 替換為空格 ' '
let rawTitle = parts.slice(1).join('-') || "Untitled";
let probTitle = rawTitle.replace(/_/g, ' ');
-%>
problem_id: <% probID %>
title: <% probTitle %>
cpe_rank: 
exam_dates: []
exam_numbers: []
Algo/Data: []
Ad_Hoc: []
Topic: []
solved: 0
---
# Reference

- 舊版本無 CPE 頁面保存
- zero
- https://onlinejudge.org/external/101/10170.pdf
- vjudge

# 題解

| Method        | $\color{Lime}{\text{AC}}$ |
| ------------- | ------------------------- |
| Brute force   | 120 ms                    |

# I/O