CC = g++
CFLAGS = -std=c++11 -Wall
TARGET = Jogo.exe
  
BUILD_DIR = ./build
SRC_DIR = ./src
PROGRAM_DIR = ./program
INCLUDE_DIR = ./include


jogo: ${BUILD_DIR}/jogador.o ${BUILD_DIR}/config.o ${BUILD_DIR}/Jogo.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD}/*.o

${BUILD_DIR}/jogador.o: ${INCLUDE_DIR}/jogador.h ${SRC_DIR}/jogador.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/jogador.cpp -o ${BUILD}/jogador.o

${BUILD_DIR}/config.o: ${INCLUDE_DIR}/config.h ${SRC_DIR}/config.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/config.cpp -o ${BUILD}/config.o

${BUILD_DIR}/Jogo.o: ${INCLUDE_DIR}/Jogo.h ${SRC_DIR}/Jogo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/Jogo.cpp -o ${BUILD}/Jogo.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/config.h ${INCLUDE_DIR}/jogador.h ${INCLUDE_DIR}/Jogo.h ${PROGRAM_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${PROGRAM_DIR}/main.cpp -o ${BUILD}/main.o