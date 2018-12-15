
CMP = g++
CLASS = player
CLASS2 = invader
CLASS3 = laser
CLASS4 = invaderClump
CLASS5 = button
MAIN = project
EXEC = spaceyboi

$(EXEC): $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(MAIN).o
	$(CMP) $(CLASS).o $(CLASS2).o $(CLASS3).o $(CLASS4).o $(CLASS5).o $(MAIN).o gfx2.o -lX11 -std=c++11 -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -std=c++11 -o $(CLASS).o

$(CLASS2).o: $(CLASS2).cpp $(CLASS2).h
	$(CMP) -c $(CLASS2).cpp -std=c++11 -o $(CLASS2).o

$(CLASS3).o: $(CLASS3).cpp $(CLASS3).h
	$(CMP) -c $(CLASS3).cpp -std=c++11 -o $(CLASS3).o

$(CLASS4).o: $(CLASS4).cpp $(CLASS4).h
	$(CMP) -c $(CLASS4).cpp -std=c++11 -o $(CLASS4).o

$(CLASS5).o: $(CLASS5).cpp $(CLASS5).h
	$(CMP) -c $(CLASS5).cpp -std=c++11 -o $(CLASS5).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h $(CLASS2).h $(CLASS3).h $(CLASS4).h $(CLASS5).h
	$(CMP) -c $(MAIN).cpp -std=c++11 -o $(MAIN).o

clean:
	rm $(MAIN).o
	rm $(CLASS).o
	rm $(CLASS2).o
	rm $(CLASS3).o
	rm $(CLASS4).o
	rm $(CLASS5).o
	rm $(EXEC)

