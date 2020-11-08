
.SILENT: 
.PHONY: test clean detectsystem

server=`cat build/server`

objectfile=build/objectfile.cmd
ifconfig=build/ifconfig.cmd
scp=build/scp.cmd
submit=build/submit.cmd
matricola=`pwd | sed s/.*\\\///g`
tests=./build/methods

all: main

detectsystem:
	echo "\n\nInizio test: `date +%H:%M:%S`"
	echo "build/*.o" >$(objectfile)
	#echo "ifconfig | grep HWaddr | sed s/.*HWaddr/$(matricola)/" >$(ifconfig)
	echo "ifconfig | grep -n1 HWaddr | grep 'inet addr' | sed 's/.*inet addr:/$(matricola) /' | sed 's/Bcast.*//'" >$(ifconfig)
	echo "scp" >$(scp)
	echo "build/submitlin" >$(submit)
	chmod +x $(ifconfig) $(submit)

clean:
	rm -f *~ *.o *.tar.gz compile compile.exe main main.exe signature build/*.cmd build/*.h build/*.cpp
	killall -q -v compile; echo ""

main: *.cpp *.h
	echo "Compilazione..."
	g++ -std=c++0x *.cpp -o main
	echo "fatto."

run: main
	echo "Esecuzione programma..."
	./main
	echo "fatto."

submit: test
	echo "Elenco dei file consegnati: "
	ls *.h *.cpp | grep -v main.cpp
	echo "Elenco completo file: "
	ls -Rlt | awk '{print $$6, $$7, $$8, $$9}' | awk NF
	echo "FINITO: `date +%H:%M:%S`\n\n"

compile: detectsystem *.cpp *.h
	echo "Compilazione per test..."
	cp *.h *.cpp build
	rm build/main.cpp
	g++ -std=c++0x build/*.cpp `cat $(objectfile)` -o compile
	echo "fatto."

test: compile
	$(tests)
	echo "FINITO: `date +%H:%M:%S`\n\n"
