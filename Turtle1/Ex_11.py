import turtle
def krug(r):
    for _ in range(100):
        turtle.forward(r)
        turtle.right(360/100)

turtle.right(90)
for i in range(0,10):
    krug(1 + i / 5)
    turtle.right(180)
    krug(1 + i / 5)
    turtle.right(180)
