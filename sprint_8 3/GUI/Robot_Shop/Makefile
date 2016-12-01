#This Makefile is donated to the Public Domain
#$(fltk-config --cxxflags) -I/usr/local/include -I/usr/local/include/FL/images -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
CXX = g++
CXXOPTS = -std=c++11

all: executable
rebuild: clean all

debug: CXXFLAGS += -g
debug: executable

executable: PM.o Database.o View.o SA.o customer.o Arm.o Head.o Battery.o Locomotor.o Torso.o boss.o contoller.o Robotpart.o main.o
	$(CXX) $(CXXOPTS) -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/freetype2 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -g -O2 -fvisibility-inlines-hidden -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT -o 'main' 'PM.o' 'main.o' 'Database.o' 'SA.o' 'customer.o' 'Arm.o' 'Head.o' 'Battery.o' 'Locomotor.o' 'Torso.o' 'boss.o' 'contoller.o' Robotpart.o 'View.o' -Wl,-Bsymbolic-functions -lfltk -lX11
#$(CXX) $(CXXOPTS) `fltk-config --use-forms --use-gl --use-images --ldstaticflags --cxxflags` -o 'rrs' 'Database.o' 'PM.o' 'Head.o' 'View.o' 'SA.o' 'Battery.o' 'customer.o' 'Arm.o' 'Locomotor.o' 'Torso.o' 'boss.o' 'contoller.o' 'Robotpart.o' 'main.o'

contoller.o: contoller.cpp controller.h
	$(CXX) -c `fltk-config --cxxflags` --compile $(CXXOPTS) contoller.cpp
#	$(CXX) -c `fltk-config --use-forms --use-gl --use-images --ldstaticflags --cxxflags` $(CXXOPTS) contoller.cpp

Robotpart.o: Robotpart.cpp Robotpart.h
	$(CXX) -c $(CXXOPTS) Robotpart.cpp

Database.o: Database.cpp Database.h
	$(CXX) -c $(CXXOPTS) Database.cpp

PM.o: PM.h PM.cpp
	$(CXX) -c $(CXXOPTS) PM.cpp

View.o: View.h View.cpp
	$(CXX) -c $(CXXOPTS) View.cpp

SA.o: SA.h SA.cpp
	$(CXX) -c $(CXXOPTS) SA.cpp

customer.o: customer.h customer.cpp
	$(CXX) -c $(CXXOPTS) customer.cpp

Arm.o: Arm.h Arm.cpp
	$(CXX) -c $(CXXOPTS) Arm.cpp

Head.o: Head.h Head.cpp
	$(CXX) -c $(CXXOPTS) Head.cpp

Battery.o: Battery.h Battery.cpp
	$(CXX) -c $(CXXOPTS) Battery.cpp

Locomotor.o: Locomotor.h Locomotor.cpp
	$(CXX) -c $(CXXOPTS) Locomotor.cpp

Torso.o: Torso.h Torso.cpp
	$(CXX) -c $(CXXOPTS) Torso.cpp

boss.o: boss.h boss.cpp
	$(CXX) -c $(CXXOPTS) boss.cpp

main.o: main.cpp
	$(CXX) -c $(CXXOPTS) main.cpp

clean:
	-rm -f *.o
div:
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
	# 'X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-'
	# '-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X'
