#define FREEGLUT_STATIC
#define GLEW_STATIC

#include <cmath>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../Common/World_Objects/world_object.hpp"
#include "../Common/Loader/bmp_loader.hpp"
#include "../Common/Loader/shader_loader.hpp"

#include <iostream>
#include <string.h>
#include <iomanip>
#include <chrono>
#include "global_vars.hpp"
#include "controls.hpp"
#include "engine.hpp"

#define M_PI        3.13159265358979323846
#define onii        using
#define oniichan    using
#define suki        std::cout
#define hentai      std::endl
#define kirai       std::setprecision
#define kimoi       std::setw
#define kowaii      std::fixed
#define kakkoii     std::defaultfloat
#define chan        namespace
#define mendokusai  std::chrono

Suzanne *suzanne;

oniichan suki;
oniichan hentai;
oniichan kirai;
oniichan kimoi;
oniichan kowaii;
oniichan kakkoii;
onii chan mendokusai;


void draw_asphalt();
void Reshape(int w1, int h1);

void display() {
    auto start = high_resolution_clock::now();
    movePlayer(x_step, z_step);
    orientCamera();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    draw_asphalt();
    suzanne->draw();
   

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << fixed;
    setprecision(5);
    cout << "yaw "    << setw(4) << yaw << " ";
    cout << "pitch " << setw(4) << pitch;
    cout << " | ";
    cout << setw(12) << vx << " ";
    cout << setw(12) << vy << " ";
    cout << setw(12) << vz;
    cout <<  " | ";
    cout << defaultfloat;
    setprecision(2);
    cout << running  << " ";
    cout << setw(6) << x_step << " ";
    cout << setw(6) << z_step;
    cout <<  " | ";
    cout << "X " << setw(12) << x << " ";
    cout << "Z " << setw(12) << z;
    cout << " | ";
    cout << endl;

    glutSwapBuffers();  
}


//

void initGL() {
    glClearColor(0., .5, 0.5, 1.0);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glColorMaterial(GL_FRONT, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);

    glEnable(GL_DEPTH_TEST);
    glutSetCursor(GLUT_CURSOR_NONE);


    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);

    glewExperimental = true;
    GLenum err = glewInit();
    std::cout << glewGetErrorString(err) << "\n";

    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    suzanne = new Suzanne("./Common/obj/suzanne.obj", 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIN_SIZE[0], WIN_SIZE[1]);
    glutCreateWindow("SUS truck");
    glutIgnoreKeyRepeat(0); // Mengabaikan key repeat (saat tombol keyboard dipencet terus)

    glutKeyboardFunc(pressKey);
    glutKeyboardUpFunc(releaseKey);

    glutDisplayFunc(display);
    glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus
    glutReshapeFunc(Reshape);
    
    glutPassiveMotionFunc(fpsGaming); //fps gaming
    initGL();
    glutMainLoop(); 
    return 0;
} 


void draw_asphalt(){
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
        glRotatef(-90, 1, 0, 0);
        glTranslatef(0, 0.01, 0);
        glRectf(-5, -50, 5, 150);
    glPopMatrix();
}



void Reshape(int w1, int h1) {
    // Fungsi reshape
    float ratio;
    if (h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    mposx = w/2;
    mposy = h/2;
    ratio = w / (float)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + vx, y + vy, z + vz,
        0., 1., 0.);
}