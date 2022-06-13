vpath %.c src 
SOURCES=input.c\
	game.c\
	graphicsGL.c\
	main.c
	
	

OBJECTS=$(patsubst %.c, src/obj/%.o, $(SOURCES))
OBJECTSPI=$(patsubst %.c, src/obj_pi/%.o, $(SOURCES))
INCLUDES=-Iinclude 
LIBS=-Llibs 
CFLAGS=-Wall -g -lm -lSDL2 -lSDL2_image 
RPI=-L/opt/vc/lib -lGLESv2 -Drpi `sdl2-config --cflags --libs`
CYGWIN=-lglew32 -lopengl32 -Dcygwin -DSDL_MAIN_HANDLED
MINGCXX=i686-w64-mingw32-g++
MINGCC=i686-w64-mingw32-gcc
CXX=g++
CC=gcc

All: 
	@echo Please use the following for your platform:
	@echo make cyg 
	@echo make pi

cyg: Graphundrum

pi: Graphundrum_pi

Graphundrum: $(OBJECTS) 
	$(MINGCC) -o $@ $(OBJECTS) $(CFLAGS) $(CYGWIN) $(INCLUDES) $(LIBS)
Graphundrum_pi: $(OBJECTSPI)
	$(CC) -o $@ $(OBJECTSPI) $(CFLAGS) $(RPI) $(INCLUDES) $(LIBS)

$(OBJECTS): | src/obj
$(OBJECTSPI): | src/obj_pi

src/obj:
	@mkdir -p $@
src/obj_pi:
	@mkdir -p $@

src/obj/%.o: %.c
	$(MINGCC) $(CFLAGS) $(CYGWIN) $(INCLUDES) $(LIBS) -c $< -o $@
src/obj_pi/%.o: %.c
	$(CC) $(CFLAGS) $(RPI) $(INCLUDES) $(LIBS) -c $< -o $@

# cleanup
clean:
	@echo Please use the following for your platform:
	@echo make cleancyg
	@echo make cleanpi

cleancyg:
	rm -rf $(OBJECTS)
	rm -rf Graphundrum
	rmdir src/obj

cleanpi:
	rm -rf $(OBJECTSPI)
	rm -rf Graphundrum_pi
	rmdir src/obj_pi

# EOF
