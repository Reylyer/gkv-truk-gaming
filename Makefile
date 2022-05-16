file = mainglfw
ext = cpp


# change thisss
CXX64COMPILERPATH = S:\Program\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
CXX32COMPILERPATH = C:\MinGW\bin

CXX64FLAGS = -lopengl32 -lglew32s -lglfw3 -lgdi32 
CXX32FLAGS = -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32

# 
create_dir:
	@if not exist bin mkdir bin
	@if not exist obj mkdir obj

glew: create_dir
	$(CXX64COMPILERPATH)\g++.exe -Wall -c src\main.cpp -o obj\mainglew.obj -I'include'
	$(CXX64COMPILERPATH)\g++.exe -Wall obj\mainglew.obj -o bin\mainglew.exe -L'lib' $(CXX64FLAGS)
	.\bin\mainglew.exe

glut: create_dir
	$(CXX32COMPILERPATH)\g++.exe -Wall -c src\glutv\main.cpp -o obj\mainglut.obj -I'include'
	$(CXX32COMPILERPATH)\g++.exe -Wall obj\mainglut.obj -o bin\mainglut.exe $(CXX32FLAGS)
	.\bin\mainglut.exe

p: create_dir
	$(CXX32COMPILERPATH)\g++.exe -Wall -c p\src\main.cpp -o obj\main.obj -I'include'
	$(CXX32COMPILERPATH)\g++.exe -Wall obj\main.obj -o bin\main.exe $(CXX32FLAGS)
	.\bin\main.exe

freeglut: create_dir
	$(CXX64COMPILERPATH)\g++.exe -v -Wall -c src\main.cpp -o obj\main.obj -I'include' -std=c++17
	$(CXX64COMPILERPATH)\g++.exe -v -Wall obj\main.obj -o  bin\main.exe -L'lib' -lfreeglut_static -lglu32 -lglew32s -lopengl32 -lwinmm -lgdi32
	.\bin\main.exe

trug: create_dir
	$(CXX64COMPILERPATH)\g++.exe -v -Wall -c src\mytruck.cpp -o obj\mytruck.obj -I'include'
	$(CXX64COMPILERPATH)\g++.exe -v -Wall obj\mytruck.obj -o  bin\mytruck.exe -L'lib' -lfreeglut_static -lglew32s -lglu32 -lopengl32 -lwinmm -lgdi32
	.\bin\mytruck.exe