import turtle
import math

def mnog(i, a):
    for _ in range(i):
        turtle.forward(a)
        turtle.right(360 / i)

n = 15

for i in range(3,13):
    turtle.seth(0)
    turtle.penup()
    turtle.goto(0,0)
    turtle.forward(i * n)
    turtle.right(180 - 90 * (i - 2) / i )
    turtle.pendown()
    a = (i) * n * 2  * math.sin(math.pi / i)
    mnog(i,a)
#сказали что пойдёт
