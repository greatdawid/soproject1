all: 
	g++ -o project main.cpp screen.cpp  ball.cpp -lncurses -pthread

clean :
	 rm project
