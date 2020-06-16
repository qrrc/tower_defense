# Tower defense game project.

This is a student project for object oriented C++ programming course at Faculty of Economic Sciences, University of Warsaw.

## Dependencies:

Allegro 5

Installation of Allegro 5 on macOS:

```
brew install allegro
```

## Compilation:

```
git clone https://github.com/qrrc/tower_defense.git
cd tower_defense
g++ -o main.out -std=c++11 -lallegro -lallegro_main -lallegro_primitives -lallegro_font -lallegro_ttf main.cpp cpu.cpp drawer.cpp effect.cpp enemy.cpp others.cpp turret.cpp
```
## Run:

```
./main.out
```

## How to play:

Press H for shortcuts. Place turrets when you can afford it. Launch enemy weaves and hold on as long as you can.
