#########################################################################
# @File Name:    Makefile
# @Author:     shaozengguang
# @Mail:       shaozg1101@126.com
# @Created Time: 五, 03/25/2016, 19时06分55秒
# @Copyright:    GPL 2.0
# @Description:  
#########################################################################
CC=gcc
CFLAGS= -Wall -c
TARGET=random

$(TARGET): random.o 
	$(CC) -o $(TARGET) random.o  

.PHONY: clean
clean:	
	rm -f random.o random
