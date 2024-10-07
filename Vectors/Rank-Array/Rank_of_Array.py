#algorithm

#Step 1: Create a sorted list of unique elements from the input order list

#Step 2: Create a mapping (dictionary) where each unique value is assigned a rank

#Step 3: Return a new list where each element in the input list order is replaced by its corresponding rank

#code

def rank_order(order):
    sorted_order = sorted(set(order))
    rank_map = {}  # Create an empty dictionary to store value-to-rank mappings
    # Loop through the sorted unique elements, getting their index (rank) and value
    for rank, value in enumerate(sorted_order):
        # Assign rank (which is index+1) to the corresponding value
        rank_map[value] = rank + 1
    return [rank_map[num] for num in order]

if __name__ == "__main__":
    n = int(input())  # Number of elements in the array
    order = list(map(int, input().split()))  # Input the array elements in one line separated by spaces
    result = rank_order(order)
    print(" ".join(map(str, result)))
