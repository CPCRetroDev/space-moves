# Space Moves / Toni Ramírez

### Winner of #CPCRetroDev 2015 Game Creation Contest

This is the source code for the game Space Moves, by Toni Ramirez. 

## Requirements

In order to be able to compile this code, you need:
* [CPCtelera 1.3](https://github.com/lronaldo/cpctelera/releases/tag/v1.3) installed

Alternatively, you may use [CPCtelera 1.4](https://github.com/lronaldo/cpctelera/releases/tag/v1.4), modifying source code:
* Files `game.c` and `video/draw.c` call the function `cpct_getRandomUniform_u8`. Change this calls to function `cpct_getRandom_lcg_u8`.

## Compilation instructions

Once you have [CPCtelera](https://github.com/lronaldo/cpctelera) installed in your system, open a terminal, enter `space-moves` folder and type in `make`.

Compilation will take around 30 minutes due to optimization modifiers used in `cfg/build_config.mk`. Depending on available RAM in your system, you may reduce compilation time a little bit by using `make -j4` (you may adjust the 4 to the desired number of threads).

## Credits
* Code by [Toni Ramírez](http://twitter.com/amstradgamer)
* Music by [McKlain](http://www.mcklain.com/)
* CPCtelera by [CPCtelera Authors](http://lronaldo.github.io/cpctelera/files/authors-txt.html#Authors)
* Original Gfx by [Dinamic](https://es.wikipedia.org/wiki/Dinamic_Software)
* itoa function by [Varios Authors](http://www.strudel.org.uk/itoa/)
* Loading Screen by [Gennadiy Kondratyev](http://www.123rf.com/profile_crokogen)
* Score image based on RikeLee by [Yichuan Li](http://rikelee.cgsociety.org/) 

All assets have been used with permission from their respective authors. Assets remain property of their original authors. Code is distributed under GNU GENERAL PUBLIC LICENSE v3.0.
