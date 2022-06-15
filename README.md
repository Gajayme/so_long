# so_long (school 21 project)

Small 2D game made with the miniLibX (the graphic library of the 42 school).

---
### Index

* [Game rules](#Game_rules)
* [Run the game](#Run_the_game)
* [Control](#Control)
* [Maps](#Maps)
* [Contacts](#Contacts)
* 

![ezgif com-crop](https://user-images.githubusercontent.com/90501558/173867719-af9413cc-7839-43f2-ad21-f9bb15d99a28.gif)

---
### Run_the_game

To play you can use ``make`` or ``make all`` to generate _so_long_ file, then you can execute it with one of map as a parametr:

**``./so_long maps/any_map``**

All of makefile rules:

| Rule | Function |
| - | - |
| ``make`` | Generete game without enemies |
| ``make all`` | Same as just make |
| ``make bonus`` | Generete game with enemies and some animation|
| ``make clean`` | Deletes all object files |
| ``make fclean`` | Deletes the object files and the _solong_ file |
| ``make re`` | makes ``fclean`` and ``make`` again (without enemies) |

``there could be warnings while creating _so_long_ file, but they are on the conscience of the developers :)``

---
### Game_rules

The main idea of the game is very simple: all you have to do is collect all "booze" bottles and reach 24-hours liquor store!
You can't escape without collecting all of the bottles. If you play ``bonus`` vesrion there are police patrols cars, you should avoid.

---
### Control

#### Control
Control buttons is classic ``WASD`` to move and ``esc`` to close window.

---
### Maps

All my maps are stored in ``maps`` folder. All of them are playable, except ``map_inv.ber``.

#### Map symbols meaning
| Symbol | Meaning |
| - | - |
| ``1`` | The wall |
| ``0`` | Empty space |
| ``C`` | Collectable item |
| ``P`` | Start |
| ``E`` | Finish |

#### Creating your own map
If you want, you can create your own map by changing one of my or creating new one.
There are some rules you should ming, creating a map:

1. **map must be surrounded bu _1_**
2. **there must be ONE _P_ symbol**
3. **there must be AT LEAST one _C_ symbol**
4. **there must be AT LEAST one _E_ symbol**
5. **there mustn't be any other symbols**
6. **all lines must be the same length**
7. **of course map width and height couldn't be less then 3**
8. **If you are playing _bonus_ ver. map should be big enough to spawn some enemies (8 * * or more)**

---
### Contacts
Feel free to clone this project, check the code or contact me if you have any question or suggestions:

* 21 Login:   **gajayme**
* Email:    **DonBazilikos@gmail.com**

Good luck and ave a good time! 🐬🐬🐬
