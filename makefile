a.out: ListA.o random.o driver.o
	c++ ListA.o random.o driver.o

ListA.o: ListA.cpp ListA.h
	c++ -c ListA.cpp
	
random.o: random.cpp random.h
	c++ -c random.cpp

driver.o: driver.cpp ListA.o
	c++ -c driver.cpp

