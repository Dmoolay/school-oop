executable_1: assignment3.o Person.o Pupil.o Worker.o  Teacher.o Tutor.o AdministrationPersonal.o Manager.o Secretary.o Class.o Layer.o School.o VecAnalyser.o
	g++ assignment3.o Person.o Pupil.o Worker.o  Teacher.o Tutor.o AdministrationPersonal.o Manager.o Secretary.o Class.o Layer.o School.o VecAnalyser.o -o executable_1

assignment3.o: assignment3.cpp
	g++ -c assignment3.cpp

Person.o: Person.cpp
	g++ -c Person.cpp

Pupil.o: Pupil.cpp
	g++ -c Pupil.cpp

Worker.o: Worker.cpp
	g++ -c Worker.cpp

Teacher.o: Teacher.cpp
	g++ -c Teacher.cpp

Tutor.o: Tutor.cpp
	g++ -c Tutor.cpp

AdministrationPersonal.o: AdministrationPersonal.cpp
	g++ -c AdministrationPersonal.cpp

Manager.o: Manager.cpp
	g++ -c Manager.cpp

Secretary.o: Secretary.cpp
	g++ -c Secretary.cpp

Class.o: Class.cpp
	g++ -c Class.cpp

School.o: School.cpp
	g++ -c School.cpp

VecAnalyser.o: VecAnalyser.cpp
	g++ -c VecAnalyser.cpp

clean:
	rm *.o executable_1