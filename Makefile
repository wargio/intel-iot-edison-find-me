all:
	g++ -o triang triang.cpp
	g++ -o suDai net.cpp
	make -C lcd-src
	cp lcd-src/lcd-src lcd
	make -C button-src
	cp button-src/button-src button

clean:
	rm -rf triang suDai lcd button
	make clean -C lcd-src
	make clean -C button-src
