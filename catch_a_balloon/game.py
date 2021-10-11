import pygame
from pygame.draw import *
from random import randint, random
pygame.init()

FPS = 30
size_x, sixe_y = 800, 800
screen = pygame.display.set_mode((size_x, sixe_y))

RED = (255, 0, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
GREEN = (0, 255, 0)
MAGENTA = (255, 0, 255)
CYAN = (0, 255, 255)
BLACK = (0, 0, 0)
COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]

number_of_balls = 100
speed = 10
ball = list()


class Ball:
    def __init__(self, x1, x2, y1, y2):
        self.x = randint(x1, x2)
        self.y = randint(y1, y2)
        self.r = randint(1, 10)
        self.vx = random() * speed * 2 - speed
        self.vy = random() * speed * 2 - speed
        self.color = COLORS[randint(0, 5)]

    def move(self, t):
        self.x += self.vx * t
        self.y += self.vy * t

    def vyvod(self):
        circle(screen, self.color, (self.x, self.y), self.r)


for i in range(number_of_balls):
    ball.append(Ball(100, 700, 100, 700))
    ball[i].vyvod()

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button==1:
            for i in len(ball):
                if (ball[i].x-event.pos[0] ** 2 + (ball[i].y - event.pos[1]) ** 2) <= ball[i].r**2:
                   ooooo = ball.pop(i) 
    pygame.display.update()
    screen.fill((255, 255, 255))
    rect(screen, BLACK, (100, 100, 600, 600))

    for i in range(len(ball)):
        ball[i].vyvod()
        ball[i].move(1)


pygame.quit()
