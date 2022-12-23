default: ccmd

ccmd: main.o send-command.o connect.o
	@clang main.o send-command.o -o ccmd

main.o: main.c send-command.h
	@clang main.c -c

send-command.o: send-command.c
	@clang send-command.c -c

connect.o: connect.c
	@clang connect.c -c

clean:
	@rm -f *.o ccmd && clear

run:
	@./ccmd
