all:
	clear
	gcc -H src/main.c -lSDL2 -lSDL2_image
# 	mkdir -p build/
# 	gcc build/*.o -lSDL2 -lSDL2_image