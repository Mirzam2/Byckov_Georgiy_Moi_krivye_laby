import turtle
turtle.shape('turtle')
turtle.speed(10)
def star (n):
    a = (180  * (n-2) / n)
    turtle.right(90-a / 6)
    for _ in range(n):
        turtle.forward(100)
        turtle.right(180 - a / 3)
    turtle.left(90-a / 6)
star(5)
turtle.penup()
turtle.goto(200, 0)
turtle.pendown()
star(11)
x = input()