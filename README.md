# Simple Edge detecion in C++

This project contributes to the world of computer vision through exploration, a topic that's been thoroughly covered in a comprehensive article titled ["Edge Alchemy: Transforming Images through Sobel, Prewitt, and Roberts"](https://blog.salvatorelabs.com/edge-alchemy-transforming-images-through-sobel-prewitt-and-roberts/). We're delving into the intricacies of image processing, particularly in edge detection, aiming to reveal hidden structures in images.

To use the project and experience its magical image processing capabilities, you'll need to install the `lib-turbojpeg` library on your system. This library is essential for handling JPEG image compression and decompression efficiently. Here's a step-by-step guide to installing `lib-turbojpeg` using Homebrew:

### Step 1: Install Homebrew (if not already installed)

If you don't have Homebrew installed on your macOS system, you can install it by opening your Terminal and executing the following command:

``` /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" ```

### Step 2: Install lib-turbojpeg

Once Homebrew is installed, you can easily install `lib-turbojpeg` by running the following command in your Terminal:

```brew install jpeg-turbo```

Homebrew will fetch the necessary files and libraries and install `lib-turbojpeg` on your system.

### Step 3: Verify the Installation

To verify that `lib-turbojpeg` is installed correctly in the directory `/opt/homebrew/Cellar/jpeg-turbo/2.1.5.1/` if is in another directory modify the `Header Search Paths` and `Library Search Paths` accordingly

### You're Ready to Go!

With `lib-turbojpeg` installed on your system, you can now use the project and explore its magical image processing capabilities to create captivating and dreamy visuals. Have fun experimenting with Gaussian blur and unleashing your creativity to craft mesmerizing masterpieces!

[![Watch the video](https://img.youtube.com/vi/tUR2h4mnPqc/maxresdefault.jpg)](https://youtu.be/tUR2h4mnPqc)

### Sobel Filter
![Sobel](https://github.com/salvatore356/edge-detection/blob/main/imgs/sobel.jpg?raw=true)

### Prewitt Filter
![Prewitt](https://github.com/salvatore356/edge-detection/blob/main/imgs/prewitt.jpg?raw=true)

### Roberts Filter
![Roberts](https://github.com/salvatore356/edge-detection/blob/main/imgs/roberts.jpg?raw=true)
