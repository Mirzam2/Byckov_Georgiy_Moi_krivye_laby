import turtle
turtle.shape('turtle')
turtle.speed(100)
for i in range(10):
    turtle.penup()
    turtle.backward(10)
    turtle.left(90)
    turtle.forward(10)
    turtle.right(90)
    turtle.pendown()
    for _ in range(4):
        turtle.forward(i*20)
        turtle.right(90)

x = input()
