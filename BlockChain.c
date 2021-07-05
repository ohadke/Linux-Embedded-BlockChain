#include"BlockChain.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
BlockChain getEmptyBlockChain(){
	BlockChain chain;
	chain.head = chain.tail = NULL;
	chain.size = 0;
	return chain;
}
void addBlockToChain(BlockChain* chain, Block newBlock){
	BlockNode* node = (BlockNode*)malloc(sizeof(BlockNode));
	node->value = newBlock;
	node->next = NULL;
	if(chain->tail != NULL)
		chain->tail->next = node;
	chain->tail = node;
	(chain->size)++;
}
void freeBlockChain(BlockChain* chain){
	BlockNode* current = chain->head;
	BlockNode* prev;
	while(current != NULL){
		prev = current;
		current = current->next;
		free(prev);
	}
	chain->head = chain->tail = NULL;
	chain->size = 0;
}
Block getLastBlock(BlockChain* chain){
	return chain->tail->value;
}
BlockDataForHash getDataForHash(Block block){
	BlockDataForHash data;
	data.height = block.height;
	data.timestamp = block.timestamp;
	data.prev_hash = block.prev_hash;
	data.nonce = block.nonce;
	data.relayed_by = block.relayed_by;
	return data;
}

int getBlockChainSize(BlockChain chain)
{
	return chain.size;
}

unsigned int calcHash(BlockDataForHash data )
{
	int len = sizeof(BlockDataForHash);
    char buffer[sizeof(BlockDataForHash)+1];
    memset(buffer, 0x00, sizeof(BlockDataForHash)+1);
    memcpy(buffer, &data, sizeof(BlockDataForHash)); 
	return crc32(0,buffer,len);
}

int isValidHash(unsigned int hash,int difficulty)
{
	int mask=1;
	int steps = ((sizeof(hash)*8) -difficulty);
	mask = mask << steps;
	if(mask>hash)
	{
		return 1;
	}
	return 0;
}
		
