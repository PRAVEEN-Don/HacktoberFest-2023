from turtle import Turtle

class Scoreboard(Turtle):
    def __init__(self):
        super().__init__()
        self.color("white")
        self.penup()
        self.hideturtle()
        self.l_score = 0  # Initialize left player score
        self.r_score = 0  # Initialize right player score
        self.update_score()

    def update_score(self):
        self.clear()  # Clear the previous score
        self.goto(-100, 200)  # Position for left score
        self.write(self.l_score, align="center", font=("Courier", 80, "normal"))
        self.goto(100, 200)  # Position for right score
        self.write(self.r_score, align="center", font=("Courier", 80, "normal"))

    def l_point(self):
        self.l_score += 1  # Increment left score
        self.update_score()  # Update the score display

    def r_point(self):
        self.r_score += 1  # Increment right score
        self.update_score()  # Update the score display
