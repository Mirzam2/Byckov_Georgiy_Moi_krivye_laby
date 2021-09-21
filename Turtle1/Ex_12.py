import turtle
def dyga(r):
    for _ in range(100):
        turtle.forward(r/10)
        turtle.right(180/100)

turtle.left(90)
for i in range(0,10):
    dyga(10)
    dyga(1)
