CC=g++ -std=c++11
CFLAGS=-Wall -g -Wno-unused-variable -pthread
LDFLAGS= -LCore/Libs/GLFW/ -lglfw -LCore/Libs/GL/ -lglew -lfreetype -framework OpenGL
OPTS = -I Core/Libs/IrrKlang/libbirrklang.dylib -pthread


#recursivly finds all cpp files in src
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
ALL_CORE_CPP := $(call rwildcard,Core/,*.cpp)
ALL_PLAYGROUND_CPP := $(call rwildcard,PlayGround/,*.cpp)

all: app

app: $(ALL_CORE_CPP) $(ALL_PLAYGROUND_CPP)
	$(CC) $(CFLAGS) -o $@ $^ $(OPTS) $(LDFLAGS)

clean:
	$(RM) app
	$(RM) *.o