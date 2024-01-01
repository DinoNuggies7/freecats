all:
	clear
	gcc src/main.c -H -lSDL2 -lSDL2_image

win:
	clear
	x86_64-w64-mingw32-gcc -H src/main.c -o FREECATS.EXE -static-libgcc -Wl,-Bstatic -lpthread -lcomctl32 -lpsapi -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -mwindows -Wl,--dynamicbase -Wl,--nxcompat -Wl,--high-entropy-va -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lsetupapi -lversion -luuid -Wl,-Bdynamic
