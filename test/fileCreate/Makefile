test: main-HTML.o createHTML.o saveFile.o
	g++ main-HTML.o createHTML.o saveFile.o -lboost_locale -lboost_filesystem -lboost_system

main-HTML.o: main-HTML.cc
	g++ -c main-HTML.cc

createHTML.o: createHTML.cc
	g++ -c createHTML.cc

saveFile.o: saveFile.cc
	g++ -c saveFile.cc
