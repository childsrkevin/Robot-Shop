CXX = g++
CXXOPTS = -std=c++11

all: executable
rebuild: clean all

debug: CXXFLAGS += -g
debug: executable

executable: main.o View.o
	$(CXX) $(CXXOPTS) -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -o 'main' 'main.o' 'View.o' -Wl,-Bsymbolic-functions -lfltk -lX11

main.o: View.h 
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) main.cpp

View.o: View.cpp View.h
	$(CXX) -c $(CXXOPTS) $(fltk-config -cxxflags) View.cpp

clean:
	-rm -f *.o main

div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
