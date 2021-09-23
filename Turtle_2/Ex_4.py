import turtle

turtle.speed(10)
vx = 10
vy = 50
g = - 10
dt = 0.005

turtle.goto(100, 0)
turtle.goto(-100, 0)
turtle.goto(-100, 1)

x = turtle.xcor()
y = turtle.ycor()
while abs(vy) > 0:
    if y <= 0:  # проверка на соприкосновение с землей
        vy = - vy / 2
    x += vx * dt
    y += vy * dt
    vy = vy + g * dt
    turtle.goto(x, y)
