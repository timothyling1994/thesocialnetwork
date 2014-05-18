CPPFLAGS=-std=c++11 -Wall -g 
# -Werror -std=c++11
#  valgrind --tool=memcheck ./memory
CC=g++-4.8 # or g++-4.8

all: main wall userlist wallpost user wallpostComment

main: main.cpp
	${CC} main.cpp -o $@ ${CPPFLAGS}

wall: wall.cpp
	${CC} wall.cpp -o $@ ${CPPFLAGS}
	
userlist: userlist.cpp
	${CC} userlist.cpp -o $@ ${CPPFLAGS}
	
wallpost: wallpost.cpp
	${CC} wallpost.cpp -o $@ ${CPPFLAGS}
	
user: user.cpp
	${CC} user.cpp -o $@ ${CPPFLAGS}
	
wallpostComment: wallpostComment.cpp
	${CC} wallpostComment.cpp -o $@ ${CPPFLAGS}


.PHONY: clean

clean:
	-@rm *.o main wall userlist wallpost user wallpostComment 2>/dev/null || true 


