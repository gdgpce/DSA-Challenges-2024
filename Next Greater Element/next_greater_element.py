
def find_next_greater (nums):
    """
    Find the second greater number for each element in the list.

    For each element in the input list, this function finds the second number 
    that is greater than the current element. If no second greater number 
    exists, -1 is appended to the result.

    Args:
        nums (list): A list of integers.

    Returns:
        list: A list containing the second greater number for each element, 
              or -1 if no such number exists.
    """

    final_list = []

    # Iterate through each element in nums using its index
    for i, value in enumerate(nums):
        found_first = False  # Flag to check if the first greater number is found
        found_second = False # Flag to check if the second greater number is found
        # Check the elements that come after the current element
        for num in nums[i+1:]:
            if num > value:
                if not found_first: # Check if the first greater number has been found
                    found_first = True
                else:
                    final_list.append(num)
                    found_second = True  # Mark that the second greater number is found
                    break
        # If no second greater number was found, append -1
        if not found_second:        
            final_list.append(-1)
    return final_list

