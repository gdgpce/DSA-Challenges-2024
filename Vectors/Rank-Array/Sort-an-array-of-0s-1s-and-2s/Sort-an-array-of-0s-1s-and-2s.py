def sort_array(arr):
    low, mid = 0, 0
    high = len(arr) - 1

    # Traverse the array to sort elements into 0s, 1s, and 2s
    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]  # Swap 0 to the low section
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1  # 1 is in the correct place, just move mid pointer
        else:
            arr[mid], arr[high] = arr[high], arr[mid]  # Swap 2 to the high section
            high -= 1

def main():
    # Example usage
    arr = [0, 2, 1, 2, 0, 1]
    sort_array(arr)

    # Display the sorted array
    print("After sorting:", *arr)

# Call main function
if __name__ == "__main__":
    main()
