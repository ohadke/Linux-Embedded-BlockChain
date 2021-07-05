CFLAGS = -Wall = -lm
CC = c99 
OS := $(shell uname) ifneq (,$(findstring CYGWIN_NT,$(OS))) EXT = .exe else EXT = endif
PROG = program$(EXT)
LIBS = -lpthread -lz -libBlockChain.so
all : $(PROG) 
 
BlockChain.out:   BlockChain.h BlockChain.c
				gcc -c BlockChain.c -o BlockChain.out
				gcc -shared -o libBlockChain.so BlockChain.out
globals: globals.h
				
server.out: globals server.h server.c 	BlockChain.out
				gcc  -c server.c -o server.out -pthread
miner.out: globals	miner.h miner.c 	BlockChain.out
				gcc -c  miner.c -o miner.out -pthread
main.out: BlockChain.out miner.out server.out main.c
				gcc -c main.c -o main.out  -pthread
$(PROG): main.out
				gcc main.out miner.out server.out BlockChain.out  -o $(PROG) -lz -pthread -L libBlockChain.so
				 	
clean:
	rm -f *.out *.so program