def find_max(arr):
    # Check if the array is empty
    if len(arr) == 0:
        return None  # Return None if array is empty
    
    # Initialize max_element to the first element in the array
    max_element = arr[0]
    
    # Loop through the array to find the maximum element
    for num in arr:
        if num > max_element:
            max_element = num
    
    return max_element

# Example usage:
array = [10, 50, 30, 70, 20]
max_number = find_max(array)
print(f"The maximum number in the array is: {max_number}")
