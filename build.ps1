$CXX64COMPILERPATH = "S:\Program\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin" + ";"


$Env:Path = (Get-Item .).FullName + "\dlls;" + $Env:Path
$Env:Path = $CXX64COMPILERPATH + $Env:Path
g++ -v -Wall -c src\main.cpp -o obj\main.obj -I'include' -std=c++17
g++ -v -Wall obj\main.obj -o  bin\main.exe -L'lib' -lfreeglut_static -lglu32 -lglew32s -lopengl32 -lwinmm -lgdi32
.\bin\main.exe