# Graphundrum
Don't have access to Visual Studio?  or just prefer to use gcc?

OpenGL with SDL2 for cygwin and rpi

This project sets up 32 bit compile
for SDL and OpenGL using glew for windows, and GLES2 for rpi.

#For cygwin:
if you want 64 bit, change mingw64-i686 with mingw64-x86_64.

You are responsible for installing cygwin with:
###mingw64-i686-gcc-g++
###mingw64-i686-glew
###mingw64-i686-SDL2
###mingw64-i686-SDL2_image

You need to add the mingx bin folder to your path: in your .bashrc add:
PATH=$PATH:/usr/i686-w64-mingw32/sys-root/mingw/bin

#For rpi:
You 'can' use SDL2 that ships with rasbian, but I recomend you do NOT,
as it is compiled against x11 and runs super slow.  If you want it to run 
at normal speeds,  I recomend you compile SDL2 yourself with the configure 
options of:
####./configure --disable-video-x11 --disable-video-opengl --disable-video-mir

also make sure you have libudev and libevdev, without these your inputs wont work
####sudo apt-get install libudev-dev
####sudo apt-get install libevdev-dev


and you'll get a surface that writes directly to your display bypassing x11.