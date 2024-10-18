from turtle import Screen, Turtle
from paddle import Paddle, Boundary
from ball import Ball
from scoreboard import Scoreboard
import time

# Setup screen
screen = Screen()
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.title("Pong")
screen.tracer(0)

# Get points to win from user
points = screen.textinput(prompt="Kitne Points ka Khelega?", title="Batao bhaiii")

# Create paddles, ball, and scoreboard
paddle = Boundary()
paddle.boundary()
ball = Ball()
scoreboard = Scoreboard()

r_paddle = Paddle((350, 0))  # Right paddle
l_paddle = Paddle((-350, 0))  # Left paddle

# Control the paddles
screen.listen()
screen.onkey(r_paddle.go_up, "Up")
screen.onkey(r_paddle.go_down, "Down")
screen.onkey(l_paddle.go_up, "w")
screen.onkey(l_paddle.go_down, "s")

# Game loop
is_game_on = True

while is_game_on:
    time.sleep(0.05)  # Control game speed
    screen.update()    # Update the screen
    ball.move()        # Move the ball

    # Check for game over condition
    if scoreboard.l_score > int(points) or scoreboard.r_score > int(points):
        is_game_on = False
        turtle = Turtle()
        turtle.color("white")
        turtle.hideturtle()
        turtle.write("Game Over", align="center", font=("Courier", 80, "normal"))

    # Detect collision with the wall
    if ball.ycor() > 280 or ball.ycor() < -280:
        ball.bounce_y()

    # Detect collision with the paddles
    if (ball.distance(r_paddle) < 50 and ball.xcor() > 320) or (ball.distance(l_paddle) < 50 and ball.xcor() < -320):
        ball.bounce_x()

    # R_paddle misses the ball
    if ball.xcor() > 380:
        ball.reset_position()
        scoreboard.l_point()  # Left paddle scores

    # L_paddle misses the ball
    if ball.xcor() < -380:
        ball.reset_position()
        scoreboard.r_point()  # Right paddle scores

# Exit on click
screen.exitonclick()
