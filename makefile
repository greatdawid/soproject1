all: 
	g++ -o project main.cpp screen.cpp  ball.cpp -lncurses -fpermissive -pthread

clean :
	 rm project
