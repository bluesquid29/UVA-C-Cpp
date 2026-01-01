<%*
const content = tp.file.content
const lines = content.split("\n")

const result = lines
  .filter(line => /^#+\s+/.test(line))
  .map(line => {
    const level = line.match(/^#+/)[0].length
    const text = line.replace(/^#+\s+/, "").trim()
    const indent = "\t".repeat(level - 1)

    // link text = heading text, no duplication
    return `${indent}- [[#${text}]]`
  })

tR += result.join("\n")
%>

