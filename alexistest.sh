#!/bin/bash

# Function to generate a random number between -1000 and 1000
generate_random_number() {
  echo $((RANDOM % 2001 - 1000))
}

# Set the desired number of random unique numbers
x=100

while true; do
  # Array to store unique numbers
  numbers=()

  # Generate x random unique numbers
  while [ ${#numbers[@]} -lt $x ]; do
    rand_num=$(generate_random_number)
    # Check if the number is not already in the array
    if [[ ! " ${numbers[@]} " =~ " $rand_num " ]]; then
      numbers+=($rand_num)
    fi
  done

  # Print the array of random unique numbers

  # Run your program with the random unique numbers as arguments
  result=$(./push_swap "${numbers[@]}" | ./checker_linux "${numbers[@]}")
  count=$(./push_swap "${numbers[@]}" | wc -l)

  if [ $count -gt 700 ]; then
    echo "Random unique numbers: ${numbers[@]}"
    break
  fi

  # Check if the result is not "OK"
  if [ "$result" != "OK" ]; then
    echo "Checker result: $result"
    break  # Exit the loop if the result is not "OK"
  fi
done