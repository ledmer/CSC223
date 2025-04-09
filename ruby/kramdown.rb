require 'kramdown'

markdown = File.read('example.md')
html = Kramdown::Document.new(markdown).to_html

File.open('output.html', 'w') { |file| file.write(html) }

puts "Converted markdown to HTML and saved to output.html"
