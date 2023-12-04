#!/bin/bash

# Function to generate 5 random non-repeating numbers
generate_random_numbers() {
  shuf -i 1-100 -n 5 | tr '\n' ' '
}

while true; do
  # Generate random numbers and pass them to the first program
  random_numbers=$(generate_random_numbers)
  output=$(./push_swap $random_numbers | ./checker $random_numbers)

  # Check if the output of the second program is "KO"
  if [ "$output" == "KO" ]; then
    echo "Exiting loop as Second Program output is 'KO'"
	echo $random_numbers
    break
  fi

  # Add a delay if needed
  sleep 1
done
