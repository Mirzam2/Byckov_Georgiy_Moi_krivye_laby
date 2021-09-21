import turtle

n = int(input())
turtle.left(90)
turtle.shape('turtle')
for _ in range(n):
    turtle.forward(100)
    turtle.stamp()
    turtle.backward(100)
    turtle.right(360/n)
