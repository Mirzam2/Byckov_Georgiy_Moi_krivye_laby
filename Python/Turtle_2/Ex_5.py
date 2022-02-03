from random import randint
import turtle
turtle.tracer(10, 1)


turtle.speed(0)

n = 50   # колво черепах
t = 1000000
xb = 300  # границы
yb = 300
vmax = 50  # во сколько уменьшается скорости
r = 10  # расстояние , когда отталкиваются

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
    unit.resizemode('user')
    unit.shapesize(0.5, 0.5)
    unit.shape('circle')
    unit.penup()
    unit.goto(randint(-xb, xb), randint(-yb, yb))
    sp.append([randint(-100, 100) / vmax, randint(-100, 100) / vmax])

'''Само моделирование'''
for _ in range(t):
    i = 0
    for unit in pool:

        '''Проверка на столкновение с другими частицами'''
        for j in range(i, n):
            if ((pool[i].xcor() - pool[j].xcor()) ** 2 + (pool[i].ycor() - pool[j].ycor()) ** 2) <= r ** 2:
                sp[i][1], sp[j][1] = sp[j][1], sp[i][1]
                sp[i][0], sp[j][0] = sp[j][0], sp[i][0]
        '''Проверка на столкновение со стенами'''
        if abs(unit.xcor() + sp[i][0]) >= xb:
            sp[i][0] = -sp[i][0]
        if abs(unit.ycor() + sp[i][1]) >= yb:
            sp[i][1] = -sp[i][1]
        '''Движение'''
        unit.goto(unit.xcor() + sp[i][0], unit.ycor() + sp[i][1])
        i += 1
