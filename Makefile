hellowin:
	./utils/write-scripts-into-constants.sh
	x86_64-w64-mingw32-gcc -o sample.exe main.c script-constants/script-constants.c helpers.c