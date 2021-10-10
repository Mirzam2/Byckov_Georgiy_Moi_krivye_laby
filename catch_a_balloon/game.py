import pygame
from pygame.draw import *
from random import randint, random
pygame.init()

FPS = 2
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


def generate_balls(number_of_balls: int, x1, y1, x2, y2):
    def new_ball():
        '''рисует новый шарик '''
        x = randint(x1, x2)
        y = randint(y1, y2)
        r = randint(10, 100)
        vx = random() * 20 - 10
        vy = random() * 20 - 10
        color = COLORS[randint(0, 5)]
        balls.append((color, (x, y), r, vx, vy))
    global balls
    balls = list()
    for i in range(number_of_balls):
        new_ball()


def vyvod(n):
    for i in range(n):
        circle(screen, balls[i][0], balls[i][1], balls[i][2], width=0)


generate_balls(100, 100, 100, 700, 700)
vyvod(100)

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True

    pygame.display.update()
    screen.fill(BLACK)

pygame.quit()
