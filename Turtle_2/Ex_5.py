import turtle
from random import randint

turtle.speed(10)

n = 50   # кол-о черепах
t = 100   # кол-о иттераций
xb = 300  # границы
yb = 300
vmax = 10

sp = list()
turtle.penup()
turtle.goto(xb, yb)
turtle.pendown()
turtle.goto(-xb, yb)
turtle.goto(-xb, -yb)
turtle.goto(xb, -yb)
turtle.goto(xb, yb)
turtle.hideturtle()

'''Генерация положения и скоростей частиц газа'''
pool = [turtle.Turtle() for i in range(n)]
for unit in pool:
    unit.shape('circle')
    unit.penup()
    unit.goto(randint(-xb, xb), randint(-yb, yb))
    sp.append([randint(-100, 100) / vmax, randint(-100, 100) / vmax])

'''Само моделирование'''
for _ in range(t):
    i = 0
    for unit in pool:
        if abs(unit.xcor()) >= xb:
            sp[i][0] = -sp[i][0]
        if abs(unit.ycor()) >= yb:
            sp[i][1] = -sp[i][1]
        unit.goto(unit.xcor() + sp[i][0], unit.ycor() + sp[i][1])
        i += 1
