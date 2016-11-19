output: PM.o Database.o View.o SA.o customer.o Arm.o Head.o Battery.o Locomotor.o Torso.o boss.o contoller.o Robotpart.o main.o
	g++ Database.o PM.o View.o SA.o customer.o Arm.o Head.o Battery.o Locomotor.o Torso.o boss.o contoller.o Robotpart.o main.o -o output

Robotpart.o: Robotpart.cpp Robotpart.h
	g++ -c Robotpart.cpp

contoller.o: contoller.cpp controller.h
	g++ -c contoller.cpp

Database.o: Database.cpp Database.h
	g++ -c Database.cpp

PM.o: PM.h PM.cpp
	g++ -c PM.cpp

View.o: View.h View.cpp
	g++ -c View.cpp

SA.o: SA.h SA.cpp
	g++ -c SA.cpp

customer.o: customer.h customer.cpp
	g++ -c customer.cpp

Arm.o: Arm.h Arm.cpp
	g++ -c Arm.cpp

Head.o: Head.h Head.cpp
	g++ -c Head.cpp

Battery.o: Battery.h Battery.cpp
	g++ -c Battery.cpp

Locomotor.o: Locomotor.h Locomotor.cpp
	g++ -c Locomotor.cpp

Torso.o: Torso.h Torso.cpp
	g++ -c Torso.cpp

boss.o: boss.h boss.cpp
	g++ -c boss.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	rm *.o output
