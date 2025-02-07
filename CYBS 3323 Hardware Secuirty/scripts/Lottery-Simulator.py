import random

def play_powerball():
    # Generate 5 random numbers between 1 and 69 for the white balls
    white_balls = random.sample(range(1, 70), 5)
    
    # Sort the white balls for readability
    white_balls.sort()
    
    # Generate 1 random number between 1 and 26 for the red PowerBall
    powerball = random.randint(1, 26)
    
    # Print the generated lottery numbers
    print("Your PowerBall numbers are:")
    print("White Balls:", white_balls)
    print("PowerBall (Red):", powerball)

# Play one game
play_powerball()

