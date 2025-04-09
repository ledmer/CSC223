# Ruby Notes for Experienced Programmers

These are concise notes for programmers transitioning to Ruby. Focus is on idiomatic Ruby, syntax quirks, and useful language features.

---

## 📦 Basics

### Data Types
- `Integer`, `Float`, `String`, `Symbol`, `Boolean`, `Array`, `Hash`, `Range`
- `nil` is Ruby's null.

```ruby
name = "Alice"
age = 30
active = true
```

### Symbols vs Strings
```ruby
:name == :name  # true
"name" == "name"  # true
:name == "name"  # false
```

Use symbols as lightweight, immutable identifiers (like enums or keys).

---

## 🔁 Control Flow

```ruby
if x > 5
  puts "Big"
elsif x == 5
  puts "Exactly"
else
  puts "Small"
end
```

### Unless
```ruby
puts "No access" unless logged_in
```

### Ternary
```ruby
age > 18 ? "Adult" : "Minor"
```

---

## 🔄 Loops

```ruby
while x > 0
  puts x
  x -= 1
end

for i in 1..5
  puts i
end

5.times { puts "Hi" }
```

---

## 🛠️ Methods

```ruby
def greet(name = "stranger")
  "Hello, #{name}"
end
```

### Return is optional
```ruby
def square(x)
  x * x  # implicitly returned
end
```

---

## 📚 Collections

### Arrays
```ruby
arr = [1, 2, 3]
arr.each { |n| puts n }
arr.map { |n| n * 2 }
```

### Hashes
```ruby
person = { name: "Bob", age: 25 }
puts person[:name]
```

---

## 🧵 Blocks, Procs, Lambdas

```ruby
def run_block
  yield if block_given?
end

run_block { puts "Hello from block" }

square = ->(x) { x * x }
square.call(4)
```

---

## 🧱 OOP in Ruby

### Classes and Objects

```ruby
class Animal
  def initialize(name)
    @name = name
  end

  def speak
    "#{@name} makes a sound"
  end
end

dog = Animal.new("Fido")
puts dog.speak
```

- Instance vars: `@name`
- Class vars: `@@count`
- Class methods: `self.method_name`

---

## 🔍 Modules and Mixins

```ruby
module Flyable
  def fly
    puts "Flying!"
  end
end

class Bird
  include Flyable
end
```

- Modules = Namespaces + Mixins

---

## 🗂️ Files and Serialization

```ruby
File.open("data.txt", "w") { |f| f.puts "Hello file" }

data = File.read("data.txt")
```

Use `Marshal.dump` / `Marshal.load` or `YAML`.

---

## 🔢 Enumerable

- Works on arrays, hashes, ranges
- Common methods:
  - `each`, `map`, `select`, `reject`, `any?`, `all?`, `none?`, `reduce`

```ruby
[1,2,3].map { |n| n * 2 }  # => [2,4,6]
```

---

## 🔁 Recursion & Data Structures

Ruby supports recursion like Python, no TCO (tail call optimization) by default.

Linked lists, trees, etc., are implemented manually or via gems.

---

## 🧪 Testing

Use `RSpec` for TDD/BDD-style testing.

```ruby
describe MyClass do
  it "does something" do
    expect(subject.method).to eq("value")
  end
end
```

---

## ⚙️ Development Tips

- Use `irb` or `pry` for REPL.
- Use `rubocop` for linting.
- Use `byebug` for debugging.
- Use `rspec` for tests.---

## 💎 Gems in Ruby

Gems are Ruby's way of packaging and distributing libraries or programs. Think of them as Python packages (pip) or Node modules (npm).

### Installing a Gem
Use the command line:

```bash
gem install gem_name
```

Example:

```bash
gem install colorize
```

### Using a Gem
After installation, require it in your code:

```ruby
require 'colorize'

puts "Hello".colorize(:red)
```

### Gemfile and Bundler
For managing dependencies in a project, use a `Gemfile` with [Bundler](https://bundler.io/):

```ruby
# Gemfile
source "https://rubygems.org"

gem "colorize"
```

Install all listed gems:

```bash
bundle install
```

Run your script using Bundler:

```bash
bundle exec ruby your_script.rb
```

Use this approach for any serious Ruby project.

------

## 🌀 Ruby Syntax Quirks

Here are a few syntax and language features that may be strange if you're coming from Python or C++.

### 1. **End Keyword for Blocks and Methods**
In Ruby, most blocks and methods end with `end` rather than curly braces or indentation (as in Python and C++).

```ruby
def greet(name)
  "Hello, #{name}"
end
```

### 2. **Parentheses are Optional in Method Calls**
Ruby allows you to omit parentheses when calling methods with arguments.

```ruby
puts "Hello, world!"   # No parentheses
greet "Alice"          # No parentheses
```

In contrast to Python or C++, this is more flexible, but sometimes you need to add parentheses for clarity.

### 3. **Array and Hash Access with Brackets**
Ruby allows accessing array and hash values with either brackets `[]` or the dot notation for symbols.

```ruby
hash = { name: "Alice", age: 25 }

puts hash[:name]    # Access with symbol
puts hash["name"]   # Will work, but less common
```

In C++, you would have to use `[]` for both.

### 4. **The `self` Keyword**
In Ruby, `self` refers to the current object or context. In contrast to Python (`self` is explicit in method signatures), `self` is implicit in method calls:

```ruby
class MyClass
  def say_hello
    "Hello from #{self}"
  end
end
```

Here, `self` is implicitly referring to the current instance.

### 5. **Single-Quoted Strings vs Double-Quoted Strings**
Single quotes do not interpolate variables, while double quotes do:

```ruby
name = "Alice"
puts 'Hello, #{name}'   # => Hello, #{name}
puts "Hello, #{name}"   # => Hello, Alice
```

### 6. **The `unless` Keyword**
Ruby uses `unless` as a negated `if`, which doesn't have a direct equivalent in most languages:

```ruby
puts "You're not allowed" unless user_logged_in?
```

This can be thought of as: `if not user_logged_in?`.

### 7. **Range Operator**
Ruby has a special range operator `..` (inclusive) and `...` (exclusive) to create ranges.

```ruby
(1..5)  # 1, 2, 3, 4, 5  (inclusive)
(1...5) # 1, 2, 3, 4    (exclusive)
```

In Python and C++, ranges work a bit differently (and C++ lacks built-in range syntax).

### 8. **The `begin` and `rescue` Keywords**
Ruby has built-in exception handling with `begin` and `rescue`, similar to `try`/`catch` in C++, but Ruby doesn't require parentheses for catching multiple exceptions.

```ruby
begin
  # risky code
  10 / 0
rescue ZeroDivisionError
  puts "Cannot divide by zero"
end
```

### 9. **Multiple Assignments**
Ruby allows multiple assignments in a single line:

```ruby
x, y, z = 1, 2, 3
puts x, y, z  # => 1, 2, 3
```

This is a bit more flexible than Python's tuple unpacking or C++'s initialization.

### 10. **The `&&` and `||` Operators as Short-circuiting**
Ruby's logical operators `&&` and `||` work like in C++, but they can return the value of one of the operands instead of just `true` or `false`.

```ruby
result = true && "This is true"  # result is "This is true"
result = false || "This is false"  # result is "This is false"
```

In Python, you'd use `and`/`or`, but the result would always be `True` or `False`.

---