FLAGS = -pedantic-errors -std=c++11

RandomWord.o: RandomWord.cpp gp.h
	g++ $(FLAGS) -c $<

DisplayClassic.o: DisplayClassic.cpp gp.h
	g++ $(FLAGS) -c $<

ClassicMode.o: ClassicMode.cpp gp.h
	g++ $(FLAGS) -c $<

ScoringMode.o: ScoringMode.cpp gp.h
	g++ $(FLAGS) -c $<

DisplayScoring.o: DisplayScoring.cpp gp.h
	g++ $(FLAGS) -c $<

MainPage.o: MainPage.cpp gp.h
	g++ $(FLAGS) -c $<

Menu.o: Menu.cpp gp.h
	g++ $(FLAGS) -c $<

Main.o: Main.cpp gp.h
	g++ $(FLAGS) -c $<

main: Main.o ClassicMode.o DisplayScoring.o ScoringMode.o RandomWord.o DisplayClassic.o MainPage.o Menu.o
	g++ $(FLAGS) $^ -o $@    // combine the made ones and make main to run the program

clean:
	rm -f main Main.o ClassicMode.o DisplayScoring.o ScoringMode.o MainPage.o RandomWord.o DisplayClassic.o Menu.o    // clean the made ones

.PHONY: clean
