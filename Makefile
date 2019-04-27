add.o:add.cpp
	g++ -c $<
delete.o:delete.cpp
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
main.o:add.cpp delete.cpp edit.cpp view.cpp stat.cpp budget.cpp wonderlist.cpp
	g++ -c $<
project:main.o add.o delete.o edit.o view.o stat.o budget.o wonderlist.o
	g++ $^ -o $@
