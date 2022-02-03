import turtle
import math
turtle.shape('turtle')
def dyga(r):
    for _ in range(100):
        turtle.forward(r)
        turtle.right(180/100)

def cryg(r):
    for _ in range(100):
        turtle.forward(r)
        turtle.right(2*180/100)

turtle.width(10000000)
turtle.forward(1)
turtle.goto(0,0)
turtle.width(1)

turtle.fillcolor('yellow')
turtle.begin_fill()
cryg(5)
turtle.end_fill()

turtle.penup()
turtle.goto(-20,-50)
turtle.pendown()
turtle.fillcolor('blue')
turtle.begin_fill()
cryg(0.5)
turtle.end_fill()

turtle.penup()
turtle.goto(20,-50)
turtle.pendown()
turtle.fillcolor('blue')
turtle.begin_fill()
cryg(0.5)
turtle.end_fill()

turtle.penup()
turtle.goto(0,-80)
turtle.pendown()
turtle.width(5)
turtle.left(90)
turtle.forward(10)
turtle.backward(40)
turtle.stamp()

turtle.penup()
turtle.backward(10)
turtle.right(90)
turtle.forward(30)
turtle.right(90)
turtle.color('red')
turtle.pendown()
dyga(math.pi / 10 * 3)
turtle.pendown()

x = input()
