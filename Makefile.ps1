g++ -Wall -c src\main.cpp -o obj\main.obj -I'src/include'
g++ -Wall obj\main.obj -o bin\main.exe -L'src/lib' -lglew32s -lglfw3 -lgdi32 -lopengl32
.\bin\main.exe