#!/bin/ruby

require 'json'
require 'stringio'

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries)
    # Hash with values
    hash = Hash.new
    # Greater value in the hash
    greaterValue = 0;
    # Execute all queries sums
    queries.each{ |q|
        # For each value inside the range
        for i in q[0]..q[1]
            # Define hash key if not defined
            if(hash[i] == nil)
                hash[i] = 0;
            end
            # Sum value in the current index and check the new value is the grater
            hash[i] += q[2];
            if(hash[i] > greaterValue)
                greaterValue = hash[i];
            end
        end
    }
    # Return the greater value
    return greaterValue;
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

nm = gets.rstrip.split

n = nm[0].to_i

m = nm[1].to_i

queries = Array.new(m)

m.times do |i|
    queries[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = arrayManipulation n, queries

fptr.write result
fptr.write "\n"

fptr.close()
