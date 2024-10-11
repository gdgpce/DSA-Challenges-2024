#algorithm
#A variable idx is initialized to 0
#The loop continues while there are more than one friend left in the circle
#the formula (idx + k - 1) % len(friends) is used to eliminate friends
#The friend at the computed idx is eliminated using pop() and the process is repeated
#when only one friend remains, that friend is the winner and the function returns this friend

#code
def findTheWinner(n: int, k: int) -> int:
    # Initialize the list of friends numbered from 1 to n
    friends = list(range(1, n + 1))

    # Start at index 0, which corresponds to friend 1
    idx = 0

    # Continue until only one friend remains
    while len(friends) > 1:
        # Calculate the index of the friend to eliminate
        # (idx + k - 1) is where we count k friends clockwise, wrapping around using modulo
        idx = (idx + k - 1) % len(friends)

        # Remove the friend from the circle
        friends.pop(idx)

    # Return the last remaining friend, which is the winner
    return friends[0]

# Call the main function
if __name__ == "__main__":
    # Input: n (number of friends) and k (step count)
    n = int(input("Enter the number of friends (n): "))
    k = int(input("Enter the step count (k): "))

    # Call the function to find the winner
    winner = findTheWinner(n, k)

    # Output: Display the winner
    print(f"The winner is friend number {winner}")
