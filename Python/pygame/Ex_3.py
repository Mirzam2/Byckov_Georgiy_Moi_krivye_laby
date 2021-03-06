import pygame
from pygame import image
import random
from random import randint
from pygame import Color, transform
from pygame import surface
from pygame.draw import *
import math
from math import pi

pygame.init()
FPS = 30
screen = pygame.display.set_mode((800, 870))
'''Рисование фона'''  # Можно циклом
rect(screen, (33, 33, 120), (0, 0, 800, 110))
rect(screen, (141, 96, 211), (0, 110, 800, 50))
rect(screen, (205, 135, 222), (0, 160, 800, 100))
rect(screen, (222, 135, 170), (0, 260, 800, 140))
rect(screen, (255, 153, 85), (0, 400, 800, 75))
rect(screen, (0, 102, 128), (0, 475, 800, 900 - 475))

'''Рисование чайки(галки), подаются координаты левого верхнего угла, угол наклона, размеры'''


def chaika(x0, y0, f, dl, h):
    sur = pygame.Surface((dl, h))
    arc(sur, (255, 255, 255), (0, 0, dl // 2, h), 0, pi, width=3)
    arc(sur, (255, 255, 255), (dl // 2, 0, dl // 2, h), 0, pi, width=3)
    sur = transform.rotate(sur, f)
    sur.set_colorkey((0, 0, 0))
    screen.blit(sur, (x0, y0))


'''Рисование большой чайки, подаются координаты левого верхего угла, надо ли отображать, размер(по оси x)'''


def boss(x0, y0, otr, n):
    m = 450 * n // 586
    sur = pygame.Surface((n, m), Color(1, 1, 1))
    k = n / 586  # коэфициент маштабирования
    '''Хвост'''
    polygon(sur, (255, 255, 255), ((113 * k, 285 * k),
            (136 * k, 208 * k), (226 * k, 309 * k), (156 * k, 302 * k)), width=0)
    polygon(sur, (0, 0, 0), ((113 * k, 285 * k),
            (136 * k, 208 * k), (226 * k, 309 * k), (156 * k, 302 * k)), width=1)
    '''Функция рисования клюва, на вход координаты левого верхнего угла, и нужно ли отображать по оси Y'''

    def beak(x, y, s):
        sbeak = pygame.Surface((100, 30), Color(1, 1, 1))
        polygon(sbeak, (255, 221, 85), ((0, 15), (62, 22),
                (76, 5), (40, 10), (4, 0)), width=0)
        polygon(sbeak, (0, 0, 0), ((0, 15), (62, 22),
                (76, 5), (40, 10), (4, 0)), width=2)
        sbeak = transform.rotozoom(sbeak, 0, k)
        sbeak = transform.flip(sbeak, False, s)
        sbeak.set_colorkey((1, 1, 1))
        sur.blit(sbeak, (x, y))

    beak(500 * k, 252 * k, True)
    beak(500 * k, 260 * k, False)

    """Рисование крыла, на вход подаются координаты левого верхнего угла и угол наклона"""
    def wing(x, y, a):
        swing = pygame.Surface((300, 400), Color(1, 1, 1))
        polygon(swing, (255, 255, 255), ((288, 216), (266, 168), (250, 147), (241, 135), (218, 131), (135, 132), (105, 129),
                                         (70, 121), (46, 112), (8, 91), (0, 90), (45, 157), (131, 172), (141, 181), (159, 201), (176, 218), (211, 239),), width=0)
        polygon(swing, (0, 0, 0), ((288, 216), (266, 168), (250, 147), (241, 135), (218, 131), (135, 132), (105, 129),
                                   (70, 121), (46, 112), (8, 91), (0, 90), (45, 157), (131, 172), (141, 181), (159, 201), (176, 218), (211, 239),), width=2)
        swing.set_colorkey((1, 1, 1))
        swing = transform.rotozoom(swing, 0, k)
        swing = transform.rotate(swing, a)
        swing.set_colorkey((1, 1, 1))
        sur.blit(swing, (x, y))

    wing(10 * k, 0, -20)
    wing(0, 35 * k, 10)

    def leg(x, y):
        sleg = pygame.Surface((240, 200), Color(1, 1, 1))

        def cog(x, y):
            sur = pygame.Surface((81, 63), Color(1, 1, 1))
            polygon(sur, (255, 230, 128), ((8, 28), (12, 63), (19, 29), (27, 21), (35, 21),
                    (76, 39), (56, 23), (42, 21), (53, 18), (81, 29), (60, 15), (42, 14), (52, 11), (69, 11), (78, 16), (74, 8), (63, 2), (47, 2), (24, 12)), width=0)
            polygon(sur, (0, 0, 0), ((8, 28), (12, 63), (19, 29), (27, 21), (35, 21),
                    (76, 39), (56, 23), (42, 21), (53, 18), (81, 29), (60, 15), (42, 14), (52, 11), (69, 11), (78, 16), (74, 8), (63, 2), (47, 2), (24, 12)), width=1)
            sur.set_colorkey((1, 1, 1))
            sleg.blit(sur, (x, y))
        cog(130, 100)

        def el(x1, y1, l, h, a):
            sur = pygame.Surface((l, h), Color(1, 1, 1))
            ellipse(sur, (255, 255, 255), (0, 0, l, h), width=0)
            sur = transform.rotate(sur, a)
            sur.set_colorkey((1, 1, 1))
            sleg.blit(sur, (x1, y1))
        el(0, 0, 94, 52, -50)
        el(45, 75, 106, 27, -20)

        sleg.set_colorkey((1, 1, 1))
        sleg = transform.rotozoom(sleg, 0, k)
        sur.blit(sleg, (x, y))
    leg(265 * k, 256 * k)
    leg(240 * k, 290 * k)

    '''Рисование туловища и головы'''

    ellipse(sur, (255, 255, 255), (200 * k, 240 * k, 205 * k, 95 * k), width=0)
    ellipse(sur, (255, 255, 255), (362 * k, 256 * k, 104 * k, 46 * k), width=0)
    ellipse(sur, (255, 255, 255), (440 * k, 243 * k, 75 * k, 46 * k), width=0)
    ellipse(sur, (0, 0, 0), (484 * k, 255 * k, 15 * k, 12 * k), width=0)
    sur.set_colorkey((1, 1, 1))
    sur = transform.flip(sur, otr, False)
    sur = transform.rotozoom(sur, 0, k)
    screen.blit(sur, (x0, y0))


'''Рисование рыбы, подаются координаты левого верхнего угла, угол наклона, размеры'''


def fish(x0, y0, a, l):
    k = l / 220
    sfish = pygame.Surface((220, 115), Color(1, 1, 1))
    polygon(sfish, (102, 99, 112), ((160, 60),
            (171, 58), (196, 73), (168, 88)), width=0)
    arc(sfish, (71, 136, 147), (65, 33, 148, 50), 0.4, 2.74, 30)
    arc(sfish, (71, 136, 147), (65, 13, 148, 50), 3.44, 6, 30)
    polygon(sfish, (71, 136, 147), ((67, 45),
            (14, 80), (4, 35)), width=0)  # хвост рыбы
    polygon(sfish, (102, 99, 112), ((135, 33), (94, 0), (164, 15),
            (172, 24), (171, 35)), width=0)  # верхний плавник
    polygon(sfish, (102, 99, 112), ((97, 59),
            (80, 79), (112, 84), (114, 62)), width=0)  # нижний плавник
    circle(sfish, (2, 57, 147), (170, 47), 7, width=0)  # глаз
    circle(sfish, (5, 64, 85), (170, 47), 5, width=0)

    sfish = transform.rotate(sfish, a)
    sfish = transform.rotozoom(sfish, 0, k)
    sfish.set_colorkey((1, 1, 1))
    screen.blit(sfish, (x0, y0))


for x0, y0, r, l in [(0, 500, False, 500), (500, 100, True, 300), (300, 300, False, 250)]:
    boss(x0, y0, r, l)
spi_fish = [(500, 500, 0, 200), (420, 320, 90, 200), (420, 560, -90, 200), (500, 450, 45, 100),
            (260, 500, 180, 200), (500, 570, -45, 100), (350, 440, 135, 100), (350, 560, -135, 100)]
for x0, y0, a, l in spi_fish:
    fish(x0, y0, a, l)
big = (250, 40)
for x0, y0, ang in [(100, 10, 7), (388, 192, 0), (130, 280, -20)]:
    chaika(x0, y0, ang, big[0], big[1])
small = (50, 20)
for x0, y0, ang in [(400, 50, 10), (450, 20, -10), (400, 100, -20), (400, 150, 20), (randint(100, 500), randint(100, 500), randint(-45, 45))]:
    chaika(x0, y0, ang, small[0], small[1])
for i in range(15):
    chaika(randint(0, 800), randint(0, 400), randint(-30, 30), 60, 20)


pygame.display.update()
clock = pygame.time.Clock()
finished = False

while not finished:
    clock.tick(FPS)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True

pygame.quit()
