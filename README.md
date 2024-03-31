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

# Sending rays

It is actually quite easy. We are just going to send a bunch of ray one by one.

One a ray hits to a wall, we are going to save the distance between ray and our character and send the next ray with different angle.

Let's start with simple:

* $`r_{otation}`$ Rotation of our character (Degree)

* $`p_{hoton}=0`$ Distance between the photon and character. It starts from 0, we'll going to increase it directly to find the distance between the wall and character

* $`x_{coordinate}`$ Character X coordinate

* $`y_{coordinate}`$ Character Y coordinate

$$\theta_{rotation}=m_{od}\left(r_{otation}\cdot\frac{\pi}{180}+0.0001,\ 2\pi\right)$$

We converted degree to theta. A value that $`\cos\left(\theta\right)`$ and $`\sin\left(\theta\right)`$ can understand.

$$x_{ray}=p_{hoton}\cdot\cos\left(\theta_{rotation}\right)+x_{coordinate}$$

$$y_{ray}=p_{hoton}\cdot\sin\left(\theta_{rotation}\right)+y_{coordinate}$$

<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/cub3D/4.gif">

Good we can now able to send a ray.

Now let's implement a perspection and fit the number of rays according to our perspective.

We are going to create some new variables for that:

* $`p_{erspective}`$ Let's set it 50 or 60 degree

* $`i_{ndex}`$ The `[index]` of ray. Limit: $`\left\{ 0 < i_{ndex} < p_{erspective}\cdot m_{ultipy} \right\}`$

* $`m_{ultipy}=1`$ Increase the ray numbers inside of the perspective. A basic additional variable. Limit: $`\left\{1 < m_{ultipy} < \infty\right\}`$

Let's chage our perspective degree to some magic numbers that $`\cos\left(\theta\right)`$ and $`\sin\left(\theta\right)`$ can understand again.

$$\theta_{perspective}=m_{od}\left(\frac{p_{erspective}}{2}\cdot\frac{\pi}{180}+0.0001,\ 2\pi\right)$$

Let's calculate which index must be position between our perspective:

$$\theta_{view}=\left(\frac{i_{ndex}}{\frac{floor\left(p_{erspective}\cdot m_{ultipy}\right)}{2}}\cdot\theta_{perspective}\right)-\theta_{perspective}$$

Then let's add this perspectie to our formula, we are just going to add $`\theta_{rotation}`$ with $`\theta_{view}`$:

$$x_{ray}=p_{hoton}\cdot\cos\left(\theta_{rotation}+\theta_{view}\right)+x_{coordinate}$$

$$y_{ray}=p_{hoton}\cdot\sin\left(\theta_{rotation}+\theta_{view}\right)+y_{coordinate}$$

<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/cub3D/5.gif">

* [**You can also simulate it in Desmos calculator**](https://www.desmos.com/calculator/ehlq27ohbt)

# Fish eye problem

Now we need to fix the fish eye effect. It is happening because of the difference distance between rays cause we're sending our rays from a single spot.

<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/cub3D/fish-1.png">

<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/cub3D/fish-2.png">

Let's write a formula from zero to solve that too:

* $`x_{coordinate}`$ character X coordinate

* $`y_{coordinate}`$ character Y coordinate

* $`\theta_{rotation}`$ the rotation angle

* $`y_{parallel}`$ The distance between ray shooter

* $`p_{hoton}=0`$ Distance between the photon and ray shooter ($`y_{parallel}`$). It starts from 0, we'll going to increase it directly to find the distance between the wall and character

* $`m_{ultipy}=1`$ Increase the ray numbers inside of the perspective. Limit: $`\left\{1 < m_{ultipy} < \infty\right\}`$

This is almost work same but with $`y_{parallel}`$ in the code, you can now also add a ray shooting point parallelly in to formula instead of sending the rays from a single point.

$$x_{ray}=x_{coordinate}+p_{hoton}\cdot\cos\left(\theta_{rotation}\right)-\left(y_{parallel}\cdot\sin\left(\theta_{rotation}\right)\right)$$

$$y_{ray}=y_{coordinate}+p_{hoton}\cdot\sin\left(\theta_{rotation}\right)+\left(y_{parallel}\cdot\cos\left(\theta_{rotation}\right)\right)$$

<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/cub3D/g1.png">

Good! Now all we need is settle the $`y_{parallel}`$ automatically by $`i_{ndex}`$ and $`p_{erspective}`$! And about the $`p_{erspective}`$, we don't need to chane it to $`\theta_{perspective}`$ anymore.

Now our new variables are:

* $`p_{erspective}`$ Let's set it 50 or 60 degree

* $`i_{ndex}`$ The `[index]` of ray. Limit: $`\left\{ 0 < i_{ndex} < p_{erspective}\cdot 4 \right\}`$

And let's calculate our new view system with perspective.

$$y_{parallel}=\frac{\left(\frac{i_{ndex}}{\frac{p_{erspective}\cdot m_{ultipy}}{2}}\cdot p_{erspective}\right)-p_{erspective}}{100}$$

Most of the other things are same. We just made $`y_{parallel}`$ automatic via some magic formulas we used.

$$x_{ray}=x_{coordinate}+p_{hoton}\cdot\cos\left(\theta_{rotation}\right)-\left(y_{parallel}\cdot\sin\left(\theta_{rotation}\right)\right)$$

$$y_{ray}=y_{coordinate}+p_{hoton}\cdot\sin\left(\theta_{rotation}\right)+\left(y_{parallel}\cdot\cos\left(\theta_{rotation}\right)\right)$$

<img src="https://raw.githubusercontent.com/TeomanDeniz/TeomanDeniz/main/images/repo_projects/cub3D/3.gif">

* [**You can also simulate it in Desmos calculator**](https://www.desmos.com/calculator/wbvov4tq84)
