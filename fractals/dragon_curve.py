import turtle

def dragon_curve(order, length, angle, direction):
    if order == 0:
        turtle.forward(length)
    else:
        turtle.left(angle * direction)
        dragon_curve(order - 1, length, angle, 1)
        turtle.right(angle * direction)
        dragon_curve(order - 1, length, angle, -1)

# Set up the turtle
turtle.speed(0)
turtle.penup()
turtle.goto(-200, 0)
turtle.pendown()

# Generate the Dragon Curve
order = 10  # Change this to adjust the complexity of the curve
length = 5  # Change this to adjust the length of each segment
angle = 90  # Change this to adjust the turning angle
direction = 1  # Change this to adjust the initial direction

dragon_curve(order, length, angle, direction)

# Hide the turtle
turtle.hideturtle()

# Keep the window open
turtle.done()