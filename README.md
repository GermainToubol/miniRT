# Introduction
Create a small raytracer able to render a small set of geometrical objects, like
spheres, planes and cylinder.

![earth and moon in the sky][earth_moon]
![many geometric forms][geometric]

# Features

# Use
## Compile and use
You have a bundle of 3 version of the project, but I still recommand to use
either the bonus version (complete and fast) or the antialliazing version
(complete and slow).

``` bash
make -j bonus abonus
```

Then launch the program as

``` bash
./miniRT_bonus [filename.rt]
./demo/demo.sh
```

## Configure
I will describe here only the bonus and the abonus versions as they use the same
format and allow more flexibility.

| tag    | description   | format                      |
|--------|---------------|-----------------------------|
| ca     | camera        | pos dir fov                 |
| A      | ambiant light | intensity color             |
| l      | light         | pos intensity color         |
| sp     | sphere        | pos radius color            |
| cy     | cylinder      | pos dir radius length color |
| pl     | plane         | pos dir color               |
| tr     | triangle      | pos pos pos color           |
| hb     | hyperboloid   | pos dir radius length color |
| \_te\_ | texture       | path                        |
| \_bm\_ | bumpmap       | path                        |

Any object has 3 optionnal parameters describing the texture (replacing the
color), the bumpmap and the checkboard status.

from _demo/cylinder.rt_:
```
ca 0,0,0     1,0,0  70

A           0.2    255,255,255
l 0,-3,9    1.0    255,255,255

pl 0,0,-2   0,0,1  255,255,255

cy 5,2,0 1,0,0.2  1 1 255,255,255 0 0
hb 7,-3,4 0,0,1 1  1 255,255,255 0 0 1
cy 4,0,-2 -0.2,0,1 2 2 255,255,255 0 0 1

_te_ ressources/textures/earthmap.tiff
_bm_ ressources/bumpmaps/earthbump1k.tiff
```

## From inside:
_The interactions are mapped on an qwerty keyboard._
You can run this program, as you would have a camera on your shoulder an be able
to go around in the scene, thus you are able to:
 - move in the camera plane with the arrow keys
 - zoom in/out with zx
 - look around with wasd
 - rotate with qe
 - all this can be done with the mouse: left clic -> camera pitch / right clic
   -> camera move / scroll -> zoom
 - esc to quit

A really nice feature is the menu (tab key) you can chose an element/a propery
with the arrow keys, change it by hitting the number bar (not the numpad),
change the element category with Ctrl+l/r arrowkey. Just kit enter to validate
and tab to escape the menu.

# Some pictures
Try the colors:

![sphere form different colors with many spotlights][lights]

Without/with antialiazing:

![scene without antialiazing][no_aa] ![scene with antialiazing][with_aa]

# Thanks
Special thanks to [JamesGarrigou](https://github.com/JamesGarrigou "Romain") for
his really nice parsing and the amazing menu he added to be able to change any
property while the program is rendering.

[earth_moon]: /ressources/screenshots/planete.png "Rendering of the earth and the moon"
[geometric]: /ressources/screenshots/geometric.png
[no_aa]: /ressources/screenshots/noantiall.png.png "No antialiazing"
[with_aa]: /ressources/screenshots/antiall100.png "100 ray per pixel"
