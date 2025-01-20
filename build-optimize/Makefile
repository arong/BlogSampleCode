all: precompile profile

precompile:
	clang++ main.cpp -stdlib=libc++ -E > prep_main.cpp
	wc -l main.cpp
	wc -l prep_main.cpp

profile:
	clang++ -stdlib=libc++ -ftime-trace -c main.cpp

clean:
	rm -f *.json *.out *.o
