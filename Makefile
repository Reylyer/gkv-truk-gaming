file = mainglfw
ext = cpp

CXX64COMPILERPATH = S:\Program\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
CXX32COMPILERPATH = C:\MinGW\bin

# 
create_dir:
	@if not exist bin mkdir bin
	@if not exist obj mkdir obj

glew: create_dir
	$(CXX64COMPILERPATH)\g++.exe -Wall -c src\glewv\main.cpp -o obj\mainglfw.obj -I'src/include'
	$(CXX64COMPILERPATH)\g++.exe -Wall obj\mainglfw.obj -o bin\mainglfw.exe -L'src/lib' -lopengl32 -lglew32s -lglfw3 -lgdi32 
	.\bin\mainglfw.exe

glut: create_dir
	$(CXX32COMPILERPATH)\g++.exe -Wall -c src\glutv\main.cpp -o obj\mainglut.obj -I'src/include'
	$(CXX32COMPILERPATH)\g++.exe -Wall obj\mainglut.obj -o bin\mainglut.exe -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32
	.\bin\mainglut.exe

p: create_dir
	$(CXX32COMPILERPATH)\g++.exe -Wall -c p\src\main.cpp -o obj\main.obj -I'src/include'
	$(CXX32COMPILERPATH)\g++.exe -Wall obj\main.obj -o bin\main.exe -lglut32 -lglu32 -lopengl32 -lwinmm -lgdi32
	.\bin\main.exe