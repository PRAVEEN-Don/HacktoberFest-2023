from turtle import Screen, Turtle

class Paddle(Turtle):
    def __init__(self, position):
        super().__init__()
        self.position = position
        self.shape("square")
        self.color("white")
        self.shapesize(stretch_wid=5, stretch_len=1)  # Adjust paddle size
        self.penup()
        self.goto(self.position)

    def go_up(self):
        new_y = self.ycor() + 20  # Move up by 20 pixels
        self.goto(self.xcor(), new_y)

    def go_down(self):
        new_y = self.ycor() - 20  # Move down by 20 pixels
        self.goto(self.xcor(), new_y)


class Boundary(Turtle):
    def __init__(self):
        super().__init__()
        self.color("white")
        self.penup()
        self.hideturtle()

    def boundary(self):
        self.goto(0, 300)  # Start at the top of the screen
        self.pendown()
        self.setheading(270)  # Set direction downwards
        for _ in range(30):  # Draw dashed boundary line
            self.forward(10)  # Move forward
            self.penup()      # Lift the pen to create a gap
            self.forward(10)  # Move forward
            self.pendown()    # Put the pen down to draw again


# Setup for the game
screen = Screen()
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.title("Pong Game")

# Create paddles
right_paddle = Paddle((350, 0))  # Right paddle
left_paddle = Paddle((-350, 0))   # Left paddle

# Create boundary
boundary = Boundary()
boundary.boundary()

# Keep the screen open
screen.exitonclick()
