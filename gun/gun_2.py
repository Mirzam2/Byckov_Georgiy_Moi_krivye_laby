import math
import random
from random import choice
from pygame import transform
import pygame
from pygame.cursors import sizer_x_strings
from pygame.draw import *
import pygame.freetype


FPS = 30

RED = 0xFF0000
BLUE = 0x0000FF
YELLOW = 0xFFC91F
GREEN = 0x00FF00
MAGENTA = 0xFF03B8
CYAN = 0x00FFCC
BLACK = (0, 0, 0)
WHITE = 0xFFFFFF
GREY = 0x7D7D7D
GAME_COLORS = [RED, BLUE, YELLOW, GREEN, MAGENTA, CYAN]

WIDTH = 800
HEIGHT = 600


class Ball:
    def __init__(self, screen: pygame.Surface, x=40, y=450):
        """ Конструктор класса ball

        Args:
        x - начальное положение мяча по горизонтали
        y - начальное положение мяча по вертикали
        """
        self.screen = screen
        self.x = x
        self.y = y
        self.r = 10
        self.g = -5
        self.vx = 0
        self.vy = 0
        self.color = choice(GAME_COLORS)
        self.live = 120

    def move(self):
        """Переместить мяч по прошествии единицы времени.

        Метод описывает перемещение мяча за один кадр перерисовки. То есть, обновляет значения
        self.x и self.y с учетом скоростей self.vx и self.vy, силы гравитации, действующей на мяч,
        и стен по краям окна (размер окна 800х600).
        """
        self.vy += self.g
        if not(0 < self.x - self.r + self.vx < WIDTH):
            self.vx = - self.vx / 2
        if not(0 < self.y - self.r - self.vy < HEIGHT - 50):
            self.vy = - self.vy / 2
        self.live -= 1
        self.x += self.vx
        self.y -= self.vy

    def draw(self):
        pygame.draw.circle(
            self.screen,
            self.color,
            (self.x, self.y),
            self.r
        )


class Lazer(Ball):
    def __init__(self, screen: pygame.Surface, x=40, y=450):
        super().__init__(screen, x=x, y=y)
        self.g = 0

    def draw(self):
        super().draw()
        pygame.draw.polygon(self.screen, (255, 255, 255), ((self.x - self.r, self.y), (self.x,
                            self.y - self.r), (self.x + self.r, self.y), (self.x, self.y + self.r)), width=2)
        pygame.draw.polygon(self.screen, (0, 0, 0), ((self.x - self.r * math.cos(math.pi / 4), self.y - self.r *
                            math.cos(math.pi / 4)), (self.x - self.r * math.cos(math.pi / 4), self.y + self.r * math.cos(math.pi / 4)),
            (self.x + self.r * math.cos(math.pi / 4),
             self.y + self.r * math.cos(math.pi / 4)),
            (self.x + self.r * math.cos(math.pi / 4), self.y - self.r * math.cos(math.pi / 4))), width=2)


class Square(Ball):
    def __init__(self, screen: pygame.Surface, x=40, y=450):
        super().__init__(screen, x=x, y=y)
        self.g = 5

    def draw(self):
        super().draw()
        pygame.draw.polygon(self.screen, (255, 255, 255), ((self.x - self.r, self.y), (self.x,
                            self.y - self.r), (self.x + self.r, self.y), (self.x, self.y + self.r)), width=4)


class Gun:
    def __init__(self, screen, x=20, y=450):
        self.screen = screen
        self.f2_power = 40
        self.f2_on = 0
        self.an = 1
        self.type_bullet = 1
        self.x = x
        self.y = y
        self.r = 50
        self.color = GREY
        self.cord = 0

    def fire2_start(self, event):
        self.f2_on = 1

    def fire2_end(self, event):
        """Выстрел мячом.

        Происходит при отпускании кнопки мыши.
        Начальные значения компонент скорости мяча vx и vy зависят от положения мыши.
        """
        global balls
        if self.cord < self.x:
            self.flag = -1
        else:
            self.flag = 1
        self.x0 = self.flag * math.cos(self.an) * self.f2_power + self.x
        self.y0 = self.flag * math.sin(self.an) * self.f2_power + self.y
        if self.type_bullet == 1:
            self.type_bullet = 2
            self.new_ball = Square(self.screen, self.x0, self.y0)
        elif self.type_bullet == 2:
            self.type_bullet = 1
            self.new_ball = Ball(self.screen, self.x0, self.y0)
        self.new_ball.r += 5
        self.an = math.atan2(
            (event.pos[1] - self.new_ball.y), (event.pos[0] - self.new_ball.x))
        self.new_ball.vx = self.f2_power * math.cos(self.an)
        self.new_ball.vy = - self.f2_power * math.sin(self.an)
        balls.append(self.new_ball)
        self.f2_on = 0
        self.f2_power = 40

    def targetting(self, event):
        """Прицеливание. Зависит от положения мыши."""
        try:
            if event:
                self.cord = event.pos[0]
                self.an = math.atan(
                    (event.pos[1]-self.y) / (event.pos[0]-self.x))
        except ZeroDivisionError:
            pass
        if self.f2_on:
            self.color = RED
        else:
            self.color = GREY

    def draw(self):
        '''Прорисовка пушки'''
        circle(screen, BLACK, (self.x, self.y), self.r * self.f2_power / 100)
        if self.cord < self.x:
            self.flag = -1
        else:
            self.flag = 1
        line(screen, self.color, (self.x, self.y), (self.flag * math.cos(self.an) *
             self.f2_power + self.x, self.flag * math.sin(self.an) * self.f2_power + self.y), width=7)

    def power_up(self):
        '''Накапливание силы'''
        if self.f2_on:
            if self.f2_power < 100:
                self.f2_power += 1
                self.color = GREY
            else:
                self.color = RED
        else:
            self.color = GREY

    def hittest(self, obj):
        """Функция проверяет сталкивалкивается ли данный обьект с целью, описываемой в обьекте obj.

        Args:
            obj: Обьект, с которым проверяется столкновение.
        Returns:
            Возвращает True в случае столкновения мяча и цели. В противном случае возвращает False.
        """
        if (self.x - obj.x) ** 2 + (self.y - obj.y) ** 2 <= (self.r * self.f2_power / 100 + obj.r) ** 2:
            obj.live = 0
            return True
        else:
            return False


class Enemy(Gun):
    def __init__(self, screen, x=400, y=400):
        super().__init__(screen, x=x, y=y)

    def fire2_end(self, event):
        self.new_ball = Lazer(self.screen, self.x, self.y)
        self.new_ball.r += 5
        self.new_ball.vx = -self.f2_power / 10
        balls.append(self.new_ball)
        self.an = math.pi
        self.f2_on = 0
        self.f2_power = 40

    def draw(self):
        image_enemy = pygame.image.load(
            r'D:\Проги\Byckov_Georgiy_Moi_krivye_laby\gun\Enemy.png')
        image_enemy = transform.rotozoom(image_enemy, 0, self.r / 200)
        screen.blit(image_enemy, (self.x - 75, self.y - 75))
        


class Target:
    def __init__(self):

        self.points = 0
        self.live = 1
        self.new_target()

    def new_target(self):
        """ Инициализация новой цели. """
        self.x = random.randint(600, 780)
        self.y = random.randint(300, 450)
        self.r = random.randint(5, 50)
        self.color = RED

    def hit(self, points=1):
        """Попадание шарика в цель."""
        self.points += points

    def draw(self):
        circle(screen, self.color, (self.x, self.y), self.r)

    def hittest(self, obj):
        """Функция проверяет сталкивалкивается ли данный обьект с целью, описываемой в обьекте obj.

        Args:
            obj: Обьект, с которым проверяется столкновение.
        Returns:
            Возвращает True в случае столкновения мяча и цели. В противном случае возвращает False.
        """
        if (self.x - obj.x) ** 2 + (self.y - obj.y) ** 2 <= (self.r + obj.r) ** 2:
            obj.live = 0
            return True
        else:
            return False


class People(Target):
    def hittest(self, obj):
        if (-obj.r <= obj.x - self.x <= 232 * self.r / 235 + obj.r) and (-obj.r <= obj.y - self.y <= 288 * self.r / 235 + obj.r):
            obj.live = 0
            return True
        else:
            return False

    def move(self):
        if not(0 <= self.y <= HEIGHT):
            self.speed *= -1
        self.y += self.speed

    def new_target(self):
        self.x = random.randint(500, 600)
        self.y = random.randint(200, 450)
        self.r = random.randint(50, 70)
        self.speed = random.random() * 30 - 15

    def draw(self):
        image = pygame.image.load(
            r'D:\Проги\Byckov_Georgiy_Moi_krivye_laby\gun\George_Floyd.png')
        image = transform.rotozoom(image, 0, self.r / 235)
        screen.blit(image, (self.x, self.y))


def end():
    pass


pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
balls = []

clock = pygame.time.Clock()
gun_main = Gun(screen)
gun2 = Enemy(screen, 500, 450)
target = Target()
finished = False
people = People()
timer = 0
while not finished:
    screen.fill(WHITE)

    people.draw()
    my_font = pygame.freetype.SysFont(
        'Times New Roman', 25)  # задание параметров текста
    my_font.render_to(screen, (20, 20),
                      "Количество очков " + str(target.points + people.points), BLACK)
    gun_main.draw()
    gun2.draw()
    target.draw()
    for b in balls:
        b.draw()
    pygame.display.update()

    clock.tick(FPS)
    timer += 1
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            finished = True
        elif event.type == pygame.MOUSEBUTTONDOWN:
            gun_main.fire2_start(event)
            gun2.fire2_start(event)
        elif event.type == pygame.MOUSEBUTTONUP:
            gun_main.fire2_end(event)
            gun2.fire2_end(event)
        elif event.type == pygame.MOUSEMOTION:
            gun_main.targetting(event)
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                gun_main.y -= 10
                gun2.y -= 10
            elif event.key == pygame.K_DOWN:
                gun_main.y += 10
                gun2.y += 10
    if timer % 60 == 0:
        gun2.fire2_end(event)
    people.move()
    for i in range(len(balls)-1, -1, -1):
        b = balls[i]
        b.move()
        if people.hittest(b) and people.live:
            people.live = 1
            people.hit(5)
            people.new_target()
        if target.hittest(b):
            target.live = 1
            target.hit()
            target.new_target()
        if gun_main.hittest(b):
            finished = True
        if b.live <= 0:
            balls.pop(i)

    gun_main.power_up()
    gun2.power_up()
pygame.quit()
