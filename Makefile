add.o:add.cpp
	g++ -c $<
deleted.o:deleted.cpp
	g++ -c $<
edit.o:edit.cpp
	g++ -c $<
view.o:view.cpp
	g++ -c $<
stat.o:stat.cpp
	g++ -c $<
budget.o:budget.cpp
	g++ -c $<
wonderlist.o:wonderlist.cpp
	g++ -c $<
main.o:add.cpp deleted.cpp edit.cpp view.cpp stat.cpp budget.cpp wonderlist.cpp
	g++ -c $<
project:main.o add.o deleted.o edit.o view.o stat.o budget.o wonderlist.o
	g++ $^ -o $@
