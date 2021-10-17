import pygame
import pygame.freetype
from pygame.draw import *
from random import randint, random
pygame.init()
FPS = 30
size_x, size_y = 1400, 800  # размеры экрана
wall = 100  # толщина стенок
screen = pygame.display.set_mode((size_x, size_y))

RED = (255, 0, 0)
BLUE = (0, 0, 255)
YELLOW = (255, 255, 0)
GREEN = (0, 255, 0)
MAGENTA = (255, 0, 255)
CYAN = (0, 255, 255)
BLACK = (0, 0, 0)
COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]
my_font = pygame.freetype.SysFont(
    'Times New Roman', 35)  # задание парамтров текста
number_of_unit = 50  # количество объектов
speed = 10  # максимальная скорость мячей
score = 0  # счётчик пойманных мячей
unit = list()
x1, x2, y1, y2 = wall, size_x - wall, wall, size_y - wall


class Ball:
    def __init__(self, x1, x2, y1, y2):
        self.x = randint(x1, x2)
        self.y = randint(y1, y2)
        self.r = randint(5, 50)
        self.vx = random() * speed * 2 - speed
        self.vy = random() * speed * 2 - speed
        self.color = COLORS[randint(0, 5)]

    def move(self, t):
        '''
        Функция движения
        '''
        self.x += self.vx * t
        self.y += self.vy * t

    def vyvod(self):
        '''Рисование шарика'''
        circle(screen, self.color, (self.x, self.y), self.r)

    def sten(self, x1, x2, y1, y2, t):
        '''Отражение от стен'''
        if self.x - self.r + self.vx * t <= x1:
            self.vx = random() * speed
            self.vy = random() * speed * 2 - speed
        if self.x + self.r + self.vx * t >= x2:
            self.vx = -random() * speed
            self.vy = random() * speed * 2 - speed
        if self.y + self.r + self.vy * t >= y2:
            self.vx = random() * speed * 2 - speed
            self.vy = -random() * speed
        if self.y - self.r + self.vy * t <= y1:
            self.vx = random() * speed * 2 - speed
            self.vy = random() * speed

    def blast(self, x, y):
        if ((self.x - x) ** 2 + (self.y - y) ** 2) <= self.r ** 2:
            self.Del = unit.pop(i)
            return(1)
        else:
            return(0)


class Square:
    def __init__(self, x1, x2, y1, y2):
        self.x = randint(x1, x2)
        self.y = randint(y1, y2)
        self.r = randint(5, 100)
        self.a = 1
        self.vx = random() * speed * 2 - speed
        self.vy = random() * speed * 2 - speed
        self.ax = random() * self.a * 2 - self.a
        self.ay = random() * self.a * 2 - self.a
        self.color = COLORS[randint(0, 5)]

    def move(self, t):
        '''
        Функция движения

        '''
        self.vx += self.ax * t
        self.vy += self.ax * t
        self.x += self.vx * t
        self.y += self.vy * t

    def vyvod(self):
        '''Рисование квадрата'''
        rect(screen, self.color, (self.x - self.r /
             2, self.y - self.r / 2, self.r, self.r))

    def sten(self, x1, x2, y1, y2, t):
        '''Отражение от стен'''
        self.flag = False
        if self.x - self.r / 2 + self.vx * t <= x1:
            self.vx = random() * speed
            self.vy = random() * speed * 2 - speed
            self.flag = True
        if self.x + self.r / 2 + self.vx * t >= x2:
            self.vx = -random() * speed
            self.vy = random() * speed * 2 - speed
            self.flag = True
        if self.y + self.r / 2 + self.vy * t >= y2:
            self.vx = random() * speed * 2 - speed
            self.vy = -random() * speed
            self.flag = True
        if self.y - self.r / 2 + self.vy * t <= y1:
            self.vx = random() * speed * 2 - speed
            self.vy = random() * speed
            self.flag = True
        if self.flag:
            self.ax = random() * self.a * 2 - self.a
            self.ay = random() * self.a * 2 - self.a

    def blast(self, x, y):
        '''Хлопание шариков'''
        if abs(self.x - x) <= self.r and abs(self.y - y) <= self.r:
            self.Del = unit.pop(i)
            return(1)
        else:
            return(0)


# генерация массива с юнитами
number_of_balls = randint(0, number_of_unit)
number_of_squers = number_of_unit - number_of_balls
for i in range(number_of_balls):
    unit.append(Ball(wall, size_x - wall, wall, size_y - wall))
for i in range(number_of_squers):
    unit.append(Square(wall, size_x - wall, wall, size_y - wall))

pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN and event.button == 1:
            for i in range(len(unit)-1, -1, -1):
                score += unit[i].blast(event.pos[0], event.pos[1])
    pygame.display.update()
    screen.fill((255, 255, 255))
    rect(screen, BLACK, (x1, y1, (x2-x1), (y2-y1)))
    my_font.render_to(screen, (20, 20), "score:" + str(score), BLACK)
    for i in range(len(unit)):
        unit[i].vyvod()
        unit[i].move(1)
        unit[i].sten(x1, x2, y1, y2, 1)

pygame.quit()
