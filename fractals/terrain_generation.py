import turtle
import random

def generate_terrain():
    # Set up the turtle
    turtle.speed(0)
    turtle.hideturtle()
    turtle.penup()
    turtle.goto(-200, -200)
    turtle.pendown()

    # Generate terrain
    for _ in range(400):
        turtle.forward(1)
        turtle.right(random.randint(0, 45))
        turtle.forward(random.randint(0, 10))
        turtle.left(random.randint(0, 45))
        turtle.forward(random.randint(0, 10))

    # Hide the turtle
    turtle.hideturtle()

# Call the terrain generation function
generate_terrain()

# Keep the window open
turtle.done()