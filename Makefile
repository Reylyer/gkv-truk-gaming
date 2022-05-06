file = main
ext = cpp


# 
a:
	@if not exist bin mkdir bin
	@if not exist obj mkdir obj
	g++ -Wall -c src\$(file).$(ext) -o obj\$(file).obj -I'src/include'
	g++ -Wall obj\$(file).obj -o bin\$(file).exe -L'src/lib' -lglew32s -lglfw3 -lgdi32 -lopengl32
	.\bin\$(file).exe
