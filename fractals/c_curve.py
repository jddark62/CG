import turtle

def c_curve(t, length, depth):
    if depth == 0:
        t.forward(length)
    else:
        c_curve(t, length/2, depth-1)
        t.right(90)
        c_curve(t, length/2, depth-1)
        t.left(90)

# Create a turtle object
t = turtle.Turtle()

# Set the speed of the turtle
t.speed(0)

# Set the initial position of the turtle
t.penup()
t.goto(-200, 0)
t.pendown()

# Call the c_curve function to draw the C-curve
c_curve(t, 400, 10)

# Hide the turtle
t.hideturtle()

# Keep the turtle window open
turtle.done()