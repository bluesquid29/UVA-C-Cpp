<%*
let content = tp.file.content

// Replace display math \[ \] with $$
content = content.replace(/\\\[/g, '$$$')
content = content.replace(/\\\]/g, '$$$')

// Replace inline math \( \) with $
content = content.replace(/\\\(/g, '$')
content = content.replace(/\\\)/g, '$')

// Update the file
await app.vault.modify(tp.file.find_tfile(tp.file.path(true)), content)
%>


%% Be careful the latex [4pt] %%

