# 42: fract-ol with bonus - 3x Outstanding Project
<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/fract-olm.png" alt="Achievement Image"><br>
</p>

## Overview

The `fract-ol` project at 42 school is an exciting exploration into fractal rendering. In this project, students create a graphical application to visualize various types of fractals. The goal is to develop a program that allows users to interactively explore and zoom into intricate fractal patterns, providing both an aesthetic and educational experience.

### YouTube Video: Click to watch
[![fractol](https://img.youtube.com/vi/WbDIdicwiAk/0.jpg)](https://www.youtube.com/watch?v=WbDIdicwiAk&autoplay=1)

## Table of Contents

- [Getting Started](#getting-started)
- [Usage](#usage)

## Getting Started

To begin working on the `fract-ol` project, follow these steps:

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/brmoretti/42_fract-ol.git
    ```

2. Navigate to the project directory:

    ```bash
    cd 42_fract-ol
    ```

4. Build the application:

    ```bash
    make
    ```
When executing `make`, it will automatically clone and compile the dependencies <a href="https://github.com/codam-coding-college/MLX42">MLX42</a> from Codam and my <a href="https://github.com/brmoretti/42_libft_extra">libft_extra</a>.

## Usage

To run the `fractol` application, execute the following command:

```bash
./fractol [fractal] [additional_arguments]
```
You can choose one of the three fractals below:
- `mandelbrot`: Visualize the Mandelbrot set. No additional arguments allowed.

- `julia`: Explore the Julia set. You can specify two additional arguments for the real and imaginary portions of the complex number. If they are not provided, the program start with arbitrary standard values. **Left-click** before zooming or using arrow keys to select these values directly from the screen.

  ```bash
  ./fractol julia [real_part] [imaginary_part]
  ```
- `bship`: Experience the Burning Ship fractal.

### Color schemes

All fractal sets support **right-click** at any time to change **color schemes**.

### Additional controls

- `z` **key**: Increase the number of iterations. Improves resolution and decreases speed.

- `x` **key**: Decrease the number of iterations. Improves speed and decreases resolution.

- `=` **key**: Zoom in.

- `-` **key**: Zoom out.

- **Arrow keys**: Move around the fractal.

- **Mouse scroll**: Zoom in or out, following the mouse position.

