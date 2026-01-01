<%*
const file = tp.config.active_file;
const now = tp.date.now("YYYY-MM-DD HH:mm");
await app.fileManager.processFrontMatter(file, (fm) => {
  fm["last_modified"] = now;
});
-%>