---
<%*
// 取得父資料夾名稱，例如 "10127-Ones"
let folderName = tp.file.folder(false);
// 用 '-' 分割，前面是 ID，後面是 Title
let parts = folderName.split('-');
let probID = parts[0] || "Unknown";
let probTitle = parts[1] || "Untitled";
-%>
problem_id: <% probID %>
title: "<% probTitle %>"
cpe_rank: 
exam_dates: []
topics: []
status: Unsolved
---