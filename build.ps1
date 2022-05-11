$CXX64COMPILERPATH = "S:\Program\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin" + ";"


$Env:Path = (Get-Item .).FullName + "\dlls;" + $Env:Path
$Env:Path = $CXX64COMPILERPATH + $Env:Path
g++ -Wall -c src\main.cpp -o obj\main.obj -I'src/include'
g++ -Wall obj\main.obj -o bin\main.exe -L'src/lib' -lglew32s -lglfw3 -lgdi32 -lopengl32
.\bin\main.exe