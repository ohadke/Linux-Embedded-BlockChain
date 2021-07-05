#ifndef __BLOCKCHAIN__
#define __BLOCKCHAIN__
#include<stdlib.h>
#include<stdio.h>
#include <zlib.h>
#include <time.h>

typedef struct Block{
	int height;
	int timestamp;
	unsigned int hash;
	unsigned int prev_hash;
	int difficulty;
	int nonce;
	int relayed_by;
}Block;

typedef struct BlockDataForHash{
	int height;
	int timestamp;
	unsigned int prev_hash;
	int nonce;
	int relayed_by;
}BlockDataForHash;

typedef struct BlockNode{
	struct BlockNode* next;
	struct Block value;
	int size;
}BlockNode;
typedef struct BlockChain{
	BlockNode* head;
	BlockNode* tail;
	int size;
}BlockChain;

BlockChain getEmptyBlockChain();
void addBlockToChain(BlockChain* chain, Block newBlock);
void freeBlockChain(BlockChain* chain);
Block getLastBlock(BlockChain* chain);
void createGenesisBlock(BlockChain *chain);
int isValidBlock();
int isValidHash(unsigned int hash,int difficulty);
int getBlockChainSize();
unsigned int calcHash(BlockDataForHash data);
BlockDataForHash getDataForHash(Block block);
#endif