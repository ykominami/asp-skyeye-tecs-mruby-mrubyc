# Array test for following methods:
#   size
#   count
#   empty?

a = []
puts a.size
puts a.count

a = [1,2,3]
puts a.size
puts a.count

puts a[0]
puts a[2]
puts a[4]

if a.empty? then puts 0 else puts 1 end
a = []
if a.empty? then puts 0 else puts 1 end
