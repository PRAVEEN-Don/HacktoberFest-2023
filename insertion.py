def insertion_sort(arr):
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
        key = arr[i]  # The element to be inserted
        j = i - 1

        # Move elements of arr[0..i-1], that are greater than key,
        # to one position ahead of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key  # Insert the key at the correct position

# Example usage:
if __name__ == "__main__":
    data = [12, 11, 13, 5, 6]
    print("Unsorted array:", data)
    insertion_sort(data)
    print("Sorted array:", data)
