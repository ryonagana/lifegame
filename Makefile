CC=g++
CFLAGS=-Wall -Wextra -g
CP=cp
RM=rm -f

LIBS =  -lallegro\
        -lallegro_image\
	-lallegro_font\
	-lallegro_ttf\
	-lallegro_audio\
	-lallegro_acodec\
	-lallegro_primitives\
	-lallegro_dialog \
	-lm


INCPATH=-I.\
	-I/usr/include\
	-I/usr/local/include\
	-I/opt/liballegro-5.2.7/include
	
LIBPATH=-L/usr/lib\
	-L/usr/local/lib\
	-L/opt/liballegro-5.2.7/lib


BIN=lifeGame



all:
	$(CC) $(CFLAGS) $(INCPATH) $(LIBPATH)  -o $(BIN) config.cpp bigTextLabel.cpp button.cpp informationPanel.cpp hall.cpp gameScreenContext.cpp main.cpp $(LIBS)

