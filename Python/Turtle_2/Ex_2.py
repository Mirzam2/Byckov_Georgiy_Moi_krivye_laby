from random import *
import turtle

font = list()
inp = open('D:\Проги\ФОПФ\Turtle_2\input.txt', 'r')
font = inp.readlines()
for i in range(len(font)):
    font[i] = font[i].rstrip()
    font[i] = font[i].split()
    for j in range(len(font[i])):
        font[i][j] = int(font[i][j])
inp.close()


def pech(s):
    x0 = turtle.xcor()
    y0 = turtle.ycor()
    turtle.penup()
    turtle.goto(font[s][0] + x0, font[s][1] + y0)
    turtle.pendown()
    for i in range(0, len(font[s]), 2):
        turtle.goto(font[s][i] + x0, font[s][i + 1] + y0)
    turtle.penup()
    turtle.goto(x0 + 1.5 * 10, y0)
    turtle.pendown()


x = '141700'
for i in range(len(x)):
    pech(int(x[i]))
x = input()
