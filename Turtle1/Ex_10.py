import turtle

def krug():
    for _ in range(100):
        turtle.forward(1)
        turtle.right(360/100)

for _ in range(3):
    krug()
    turtle.right(180)
    krug()
    turtle.right(120)
