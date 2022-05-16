# gkv-truk-gaming
ya read dis? gud

semua code masukin di src dengan entry point di main.cpp

kalo mau compile run

pakai make
```
make freeglut
```

atau powershell

```
.\build.ps1
```

tested di x86_64-win32-seh-rev0 MinGW-W64 8.1.0

# IMPORTANT NOTE
- Ini run pakai freeglut agar bisa menggunakan glew yang bisa menggunakan fitur modern. Untuk sekarang fitur modern belum digunakan karena perlu menggunakan shader yang sedikit ribet untuk dipelajari.
- Menggunakan freeglut meningkatkan performa hingga 3x lipat.
- Semua library di link secara static, jadi ga perlu copy dll ke sysWOW64. Yang pakai dll kemungkinan cuman opengl.dll, dan harusnya udah ada di sysWOW64.
- Di dalam build.ps1 ada CXX64COMPILERPATH, kalau ada masalah seperti undefined reference atau segmentation fault(error -big_num_integer) kemungkinan besar gcc kamu menggunakan 32 bit. Belum install 64 bit? gas install.
