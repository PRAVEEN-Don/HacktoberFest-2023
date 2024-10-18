import random

def jump(nums):
    jumps = 0 
    current_end = 0  
    farthest = 0  
    for i in range(len(nums) - 1):  
        farthest = max(farthest, i + nums[i]) 
        # When we reach the end of the current jump range
        if i == current_end:
            jumps += 1  
            current_end = farthest  

           
            if current_end >= len(nums) - 1:
                break

    return jumps  

def generate_levels(n):
    """ Generate an array of size n with random jump lengths. """
    return [random.randint(1, 5) for _ in range(n)]

def play_game():
    print("Welcome to the Jump Game II!")
    num_levels = int(input("Enter the number of levels (greater than 1): "))
    if num_levels < 2:
        print("Please enter a number greater than 1.")
        return

    levels = generate_levels(num_levels)
    print("\nYour levels (max jump lengths):")
    print(levels)

    min_jumps = jump(levels)

    print("\nCalculating the minimum number of jumps to reach the last index...")
    print(f"Minimum number of jumps needed: {min_jumps}\n")

   
    player_guess = int(input("Guess the minimum number of jumps needed: "))
    
    if player_guess == min_jumps:
        print("Congratulations! You guessed correctly!")
    else:
        print(f"Oops! The correct answer was {min_jumps}. Better luck next time!")

if __name__ == "__main__":
    play_game()
