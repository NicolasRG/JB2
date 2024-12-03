blackjack2: main.cpp
	echo "build .o files"
	clang++ -std=c++20 main.cpp  bjerror.cpp card.cpp deck.cpp hand.cpp -c
	echo "build a.out file"
	clang++ -std=c++20 main.o  bjerror.o card.o deck.o hand.o        	
	./a.out