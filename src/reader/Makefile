CFLAGS = 

reader: reader.o
	g++ $(CFLAGS) reader.o -o reader

%.o : %.cpp
	g++ $(CFLAGS) -c $<

clean:
	-rm *.o
	-rm reader
