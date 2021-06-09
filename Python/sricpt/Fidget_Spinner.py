import pygame
import sys
from math import *

# Initialization of Pygame Window
pygame.init()

width = 500
height = 500

display = pygame.display.set_mode((width, height))
clock = pygame.time.Clock()
pygame.display.set_caption("Fidget Spinner Simulation")

while spin:
    for event in pygame.event.get():
        