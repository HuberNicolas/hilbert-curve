build:
	gcc -Wfatal-errors \
	-std=c99 \
	./*.c \
	-I"E:\LibSDL\include" \
	-L"E:\LibSDL\lib" \
	-lmingw32 \
	-lSDL2main \
	-lSDL2 \
	-o src.exe
