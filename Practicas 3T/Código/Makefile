all: practicas3T

practicas3T: main.o CristoFinity.o Element.o Film.o Series.o Song.o Videogame.o User.o UserNormal.o Administrator.o Comment.o Valoration.o
	g++ -o practicas3T main.o CristoFinity.o Element.o Film.o Series.o Song.o Videogame.o User.o UserNormal.o Administrator.o Comment.o Valoration.o
	
main.o: main.cpp
	g++ -c main.cpp

CristoFinity.o: CristoFinity.cpp
	g++ -c CristoFinity.cpp

Element.o: Element.cpp
	g++ -c Element.cpp

Film.o: Film.cpp
	g++ -c Film.cpp

Series.o: Series.cpp
	g++ -c Series.cpp

Videogame.o: Videogame.cpp
	g++ -c Videogame.cpp

Song.o: Song.cpp
	g++ -c Song.cpp

User.o: User.cpp
	g++ -c User.cpp

UserNormal.o: UserNormal.cpp
	g++ -c UserNormal.cpp

Administrator.o: Administrator.cpp
	g++ -c Administrator.cpp

Comment.o: Comment.cpp
	g++ -c Comment.cpp

Valoration.o: Valoration.cpp
	g++ -c Valoration.cpp

clean:
	rm -f practicas3T *.o
