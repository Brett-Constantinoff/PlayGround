# OpenGL-Base

This project is designed to be a starting point for writing opengl code on the MacOS operating system

# Requirements

In order to successfully compile and link the neccessary files both GLFW and GLEW must be 
installed and the required dylib files must be in your linker path

To install GLFW and GLEW use homebrew following the commands:
```brew install glfw```
```brew install glew```

For further information about glfw and glew visit:
https://www.glfw.org/
http://glew.sourceforge.net/

# Optional Requirements

To download the freetype library visit 
https://sourceforge.net/projects/freetype/files/

When you download the freetype navigate to freetype-version -> include where you will see 
a directory called 'freetype' and a header filed called 'ft2build.h'. 

### NOTE: 'freetype' and 'ft2build.h' must be included in your computers include path as two separate entities, otherwise there will be header file conflicts

# Build

### NOTE: This project template structure is intented for MacOS only

To build run ```git clone git@github.com:Brett-Constantinoff/OpenGL-Base.git```

If you decide not to download freetype remove '-lfreetype' from the makefile, otherwise 
the compiler will not be able to link the freetype library and you will get a linking error

In the root directory run ```make all``` and wait for the project to build

Once the project is done building and has generated an executable run ```./app```

To clean the project use ```make clean```
