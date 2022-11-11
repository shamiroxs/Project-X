windows:
	g++ -static main.cpp -o asc

linux:  
	g++ main.cpp -o asc 

clean:
	rm -f asc.* 