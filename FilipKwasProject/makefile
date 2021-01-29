compiler=g++
standard=-std=c++17
optimisation=-O3
errors=-pedantic-errors
# optimisation=
# debug=-g
debug= -ggdb

.PHONY: clean

__ : main
	 ./main -i "inputTest.txt" -o "outputTest.txt"
	            
	            
main : main.o functions.o
	$(compiler) $(standard) $(debug) $(optimisation) $(errors) -o $@ $^          
	            
main.o : main.cpp
	$(compiler) $(standard) $(debug) $(optimisation) $(errors) -c -o $@ $^ 

functions.o : functions.cpp
	$(compiler) $(standard) $(debug) $(optimisation) $(errors) -c -o $@ $^ 
		
	
	
	
clean : 	
	for f in `ls *.o` ; do  if [ -f $$f ] ; then rm $$f  ; fi;   done;
	if [ -f main ] ; then rm main ; fi ;