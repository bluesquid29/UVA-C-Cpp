<%*
const content = tp.file.content
const lines = content.split("\n")

const result = lines
  .filter(line => /^#+\s+/.test(line))
  .map(line => {
    const level = line.match(/^#+/)[0].length
    const text = line.replace(/^#+\s+/, "")
    const indent = "\t".repeat(level - 1)
    return `${indent}- ${text}`
  })

tR += result.join("\n")
%>

