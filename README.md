# cub3D
Ecole-42 cub3D project. We are using ray-casting to make the 2D look more like 3D.

# Setup:

Works only in MacOS OpenGL framework. (miniLibX)

You can compile this project with `make`.

## PHONYS

Here's the arguments `MAKE.bat` and `Makefile` using:

> `fc`, `fclean`, `fclear` -> Clear both object and created products.

> `c`, `clean`, `clear` -> Clear only object files

> `re` -> Remake everything

# Stuffs

There is nothing in the project yet...

## Formula:

Character rotation: $`r_{otation}`$

Character perspective: $`p_{erspective}`$

The distance between ray and chracter: $`p_{hoton}`$

The index of the ray (`[n]` ray): $`i_{ndex}`$

Character `X` coordination: $`x_{character}`$

Character `Y` coordination: $`y_{character}`$

$$m_{od}\left(x,\ y\right)=x-\left(floor\left(\frac{x}{y}\right)\right)\cdot y$$

$$a_{ngle1}=r_{otation}\cdot\frac{\pi}{180}$$

$$a_{ngle2}=\frac{p_{erspective}}{2}\cdot\frac{\pi}{180}$$

$$a_{ngle3}=\left(\frac{i_{ndex}}{\frac{floor\left(p_{erspective}\cdot2\right)}{2}}\cdot+m_{od}\left(a_{ngle2},\ 2\pi\right)\right)-m_{od}\left(a_{ngle2},\ 2\pi\right)$$

$$x\left(i_{index}\right)=p_{hoton}\cdot\sin\left(m_{od}\left(a_{ngle1},\ 2\pi\right)+a_{ngle3}\right)+x_{character}$$

$$y\left(i_{index}\right)=p_{hoton}\cdot\cos\left(m_{od}\left(a_{ngle1},\ 2\pi\right)+a_{ngle3}\right)+y_{character}$$

Url: https://www.desmos.com/calculator/o9hazz0dip
