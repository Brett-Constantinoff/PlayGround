# PlayGround Engine
### NOTE: This project is supported for MacOS only (for now)

This project is designed to be a small scale rendering engine using OpenGL

# Requirements

In order to successfully compile and link the neccessary files both GLFW and GLEW must be 
installed and the required dylib files must be in your linker path

To install GLFW and GLEW use homebrew following the commands:
- ```brew install glfw```
- ```brew install glew```

You can also install and build both GLFW and GLEW yourself by visiting:
- https://www.glfw.org/
- http://glew.sourceforge.net/

Or go directly to their github: 
- https://github.com/glfw/glfw
- https://github.com/nigels-com/glew

Once these libraries are installed, verify that the dylib files are in the path your linker will
look usually /usr/local/lib and /usr/local as well as ensure the neccessary header files are located in your compiler's include path which is usually /usr/local/include


# Optional Requirements

To download freetype you can use homebrew with the following commands
- ```brew install freetype```

To download and build freetype yourself visit:
- https://sourceforge.net/projects/freetype/files/

Whether you choose to use homebrew or build freetype yourself, you need to include the 'freetype'
directory as well as the 'ft2build.h' header file in your compiler include path as two separate 
entities ('ft2build' is located within the 'freetpe' directory)

### NOTE: 'freetype' and 'ft2build.h' must be included in your computers include path as two separate entities, otherwise there will be header file conflicts

# Build

To build run ```git clone git@github.com:Brett-Constantinoff/OpenGL-Base.git```

If you decide not to download freetype remove '-lfreetype' from the makefile, otherwise 
the compiler will not be able to link the freetype library and you will get a linking error

In the root directory run ```make all``` and wait for the project to build

Once the project is done building and has generated an executable run ```./app```

To clean the project use ```make clean```


# Acknowledgements

Inspiration for this project came from https://github.com/TheCherno/OpenGL, this repository is designed specifically 
for windows and I wanted to create the same thing but for MacOS with some of my own modifications.
