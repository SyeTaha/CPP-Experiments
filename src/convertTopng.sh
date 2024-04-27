#!/bin/bash

# Function to handle Ctrl+C
cleanup() {
    echo
    echo "Conversion interrupted. Cleaning up..."
    exit 1
}

# Register the cleanup function to handle Ctrl+C
trap cleanup INT

# Define the directory where ppm files are located
# Starting from root directory
directory="."

# Count the total number of ppm files
total=$(find "$directory" -type f -name "*.ppm" | wc -l)
count=0

# Iterate over each ppm file in the directory
while IFS= read -r file; do
    # Convert ppm file to png
    convert "$file" "${file%.ppm}.png" && rm "$file"
    
    # Increment progress count
    ((count++))
    
    # Print progress message with carriage return
    echo -ne "Converted $count out of $total files\r"
done < <(find "$directory" -type f -name "*.ppm")

# Print newline after completion
echo
