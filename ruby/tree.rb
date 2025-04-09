
class Person
    attr_accessor :name, :children
  
    def initialize(name)
      @name = name
      @children = []
    end
  
    def add_child(child)
      @children << child
    end
  end
  
  class FamilyTree
    attr_accessor :root
  
    def initialize(ancestor_name)
      @root = Person.new(ancestor_name)
    end
  
    def find_person(name, node = @root)
      return node if node.name.downcase == name.downcase
      node.children.each do |child|
        found = find_person(name, child)
        return found if found
      end
      nil
    end
  
    def add_relative(parent_name, child_name)
      parent = find_person(parent_name)
      if parent
        parent.add_child(Person.new(child_name))
        puts "✅ Added #{child_name} as a child of #{parent_name}"
      else
        puts "❌ Parent '#{parent_name}' not found in the family tree."
      end
    end
  
    def print_tree(node = @root, indent = 0)
      puts "#{' ' * indent}- #{node.name}"
      node.children.each { |child| print_tree(child, indent + 2) }
    end
  
    def show_descendants(name)
      person = find_person(name)
      if person
        puts "📜 Descendants of #{person.name}:"
        print_tree(person)
      else
        puts "❌ Person '#{name}' not found."
      end
    end
  end
  
#main
  
  tree = FamilyTree.new("Alex")
  
  loop do
    puts "\n🧬 Family Tree Menu"
    puts "1. Add relative"
    puts "2. Show full tree"
    puts "3. Show descendants of a person"
    puts "4. Exit"
    print "> "
    choice = gets.chomp
  
    case choice
    when "1"
      print "Enter parent name: "
      parent = gets.chomp
      print "Enter child's name: "
      child = gets.chomp
      tree.add_relative(parent, child)
    when "2"
      puts "\n🌳 Family Tree:"
      tree.print_tree
    when "3"
      print "Enter person's name: "
      name = gets.chomp
      tree.show_descendants(name)
    when "4"
      puts "👋 Bye!"
      break
    else
      puts "❗ Invalid option"
    end
  end
  
