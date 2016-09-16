all: ImageBuffer.c
	gcc ImageBuffer.c -o ppmrw

clean:
	rm -rf ImageBuffer *~
