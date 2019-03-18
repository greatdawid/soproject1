all: 
	g++ -o project main.cpp screen.cpp Allballs.cpp ball.cpp -lncurses -fpermissive -pthread

clean :
	 rm project
