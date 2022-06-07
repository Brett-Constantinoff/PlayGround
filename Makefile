CC=g++ -std=c++11 -Wall
LIBS= -lglfw -lglew -lfreetype -framework OpenGL

#recursivly finds all cpp files in src
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
ALL_CORE_CPP := $(call rwildcard,Core/,*.cpp)
ALL_PLAYGROUND_CPP := $(call rwildcard,PlayGround/,*.cpp)

all: app

app: $(ALL_CORE_CPP) $(ALL_PLAYGROUND_CPP)
	$(CC)  -o $@ $^  $(LIBS) 

clean:
	$(RM) app
	$(RM) *.o