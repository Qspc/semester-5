#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

GLboolean FOLLOW = GL_FALSE;       // Variabel untuk mengecek apakah mouse sudah klik di kotak apa belum

float red=100, green=100;
float x=0;

class Rectangle{    // Buat kelas rectangle
public:
    double x=72.7, y=533.5;
    double prevY = 0;
    int red = 0, green = 0, blue = 0;
    int size = 20;  // def size

    void display()
    {
        glBegin(GL_POLYGON);    // Buat kotak
            glColor3ub(red, green, blue);   // Define warna
            // Define koordinat untuk kotak
            glVertex2f(-size + x,  size + y);
            glVertex2f( size + x,  size + y);
            glVertex2f( size + x, -size + y);
            glVertex2f(-size + x, -size + y);
        glEnd();    // End membuat kotak
    }
    // Lakukan pengecekan posisi kursor terhadap tepi luar kotak yang digambar
    GLboolean isRectangleSelected(double xpos, double ypos){
        double left = x - size;
        double right = x + size;
        double top = y + size;
        double bottom = y - size;

        if((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom))
            return GL_TRUE;
        else
            return GL_FALSE;
    }
    void doIfSelected(double xpos, double ypos){
        if(isRectangleSelected(xpos, ypos) == GL_TRUE)
            red = blue = 0;
        else
            red = blue = 255;
    }
    void doIfClicked(int button, int action, double xpos, double ypos){
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && isRectangleSelected(xpos, ypos) == GL_TRUE){        // mengecek apakah klik kiri ditekan di kotak (DRAG)
            FOLLOW = GL_TRUE;
        }
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE){            // mengecek apakah klik kiri dilepas (DROP)
            FOLLOW = GL_FALSE;
        }
    }
    void moveRect(double xpos, double ypos){        // funsi untuk menggerakan kotak
        x=xpos;
        y=ypos;
    }
};
Rectangle rect; // Define rectangle

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE); // close program on ESC key
}

static void error_callback(int error, const char* description) {
    //fputs(description);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    rect.doIfSelected(xpos, ypos);
    if(FOLLOW == GL_TRUE) rect.moveRect(xpos, ypos);        // memanggil fungsi untuk menggerakan kotak sama dengan mouse
}
// Callback untuk merespons penekanan tombol pada mouse
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    rect.doIfClicked(button, action, xpos, ypos);
}

void setup_viewport(GLFWwindow* window)
{
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 600, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
    void atas_kiri()
    {
glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(24,15);
glVertex2d(191, 15);
glVertex2d(191, 49);
glVertex2d(24, 49);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(24,15);
glVertex2d(24, 182);
glVertex2d(57, 182);
glVertex2d(57, 15);
glEnd();
    }

    void atas_kanan()
    {
glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(516,18);
glVertex2d(683, 18);
glVertex2d(683, 52);
glVertex2d(516, 52);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(683,18);
glVertex2d(683, 185);
glVertex2d(650, 185);
glVertex2d(650, 18);
glEnd();
    }

    void bawah_kiri()
       {
glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(23,506);
glVertex2d(57, 506);
glVertex2d(57, 673);
glVertex2d(23, 673);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(53,639);
glVertex2d(220, 639);
glVertex2d(220, 673);
glVertex2d(53, 673);
glEnd();
    }

    void bawah_kanan(){
    glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(516, 638);
glVertex2d(683, 638);
glVertex2d(683, 672);
glVertex2d(516, 672);
glEnd();

glBegin(GL_POLYGON);
glColor3ub(238, 133, 181);
glVertex2d(650, 505);
glVertex2d(684, 505);
glVertex2d(684, 672);
glVertex2d(650, 672);
glEnd();
    }

void huruf_s(){
    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(184, 303.5);
glVertex2d(104, 303.5);
glVertex2d(104, 318.5);
glVertex2d(184, 318.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(104, 303.5);
glVertex2d(104, 354.5);
glVertex2d(118, 354.5);
glVertex2d(118, 303.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(104, 339.5);
glVertex2d(184.5, 339.5);
glVertex2d(184.5, 354.5);
glVertex2d(104, 354.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(184.5, 339.5);
glVertex2d(184.5, 390);
glVertex2d(169.5, 390);
glVertex2d(169.5, 339.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(104, 375.5);
glVertex2d(184.5, 375.5);
glVertex2d(184.5, 390);
glVertex2d(104, 390);
glEnd();
    }

    void huruf_h(){
    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(204.5, 309);
glVertex2d(219.5, 309);
glVertex2d(219.5, 389);
glVertex2d(204.5, 389);
glEnd();


        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(204.5, 339.5);
glVertex2d(284, 339.5);
glVertex2d(284, 354.5);
glVertex2d(204.5, 354.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(269.5, 309);
glVertex2d(284.5, 309);
glVertex2d(284.5, 389);
glVertex2d(269.5, 389);
glEnd();
    }

    void huruf_i(){
            glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(303.5, 309);
glVertex2d(318.5, 309);
glVertex2d(318.5, 389);
glVertex2d(303.5, 389);
glEnd();
    }

    void huruf_b(){
        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(338, 304);
glVertex2d(352.5, 304);
glVertex2d(352.5, 390);
glVertex2d(338, 390);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(338, 304);
glVertex2d(393, 304);
glVertex2d(393, 319);
glVertex2d(338, 319);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(378, 304);
glVertex2d(393, 304);
glVertex2d(393, 354);
glVertex2d(378, 354);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(338, 339.5);
glVertex2d(419, 339.5);
glVertex2d(419, 354.5);
glVertex2d(338, 354.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(419, 339.5);
glVertex2d(419, 390);
glVertex2d(404.5, 390);
glVertex2d(404.5, 339.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(419, 375.5);
glVertex2d(419, 390);
glVertex2d(338, 390);
glVertex2d(338, 375.5);
glEnd();
    }

   void huruf_g(){
        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(439.5, 307.5);
glVertex2d(521, 307.5);
glVertex2d(521, 322.5);
glVertex2d(439.5, 322.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(439.5, 307.5);
glVertex2d(454.5, 307.5);
glVertex2d(454.5, 389);
glVertex2d(439.5, 389);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(439.5, 374.5);
glVertex2d(520, 374.5);
glVertex2d(520, 389);
glVertex2d(439.5, 389);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(520, 338.5);
glVertex2d(520, 389);
glVertex2d(505.5, 389);
glVertex2d(505.5, 338.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(470, 338.5);
glVertex2d(520, 338.5);
glVertex2d(520, 353.5);
glVertex2d(470, 353.5);
glEnd();
    }

    void huruf_o(){
        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(546.5, 306.5);
glVertex2d(627, 306.5);
glVertex2d(627, 321.5);
glVertex2d(546.5, 321.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(546.5, 306.5);
glVertex2d(561.5, 306.5);
glVertex2d(561.5, 388);
glVertex2d(546.5, 388);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(546.5, 372.5);
glVertex2d(627, 372.5);
glVertex2d(627, 388);
glVertex2d(546.5, 388);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(612.5, 306.5);
glVertex2d(627, 306.5);
glVertex2d(627, 388);
glVertex2d(612.5, 388);
glEnd();
    }

    void plus_atas(){
    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(266.5, 1);
glVertex2d(266.5, 29);
glVertex2d(433.5, 29);
glVertex2d(433.5, 1);
glEnd();

   glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(335, -68);
glVertex2d(335, 99);
glVertex2d(365, 99);
glVertex2d(365, -68);
glEnd();

    }

        void plus_bawah(){
    glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(266.5, 670);
glVertex2d(266.5, 698);
glVertex2d(433.5, 698);
glVertex2d(433.5, 670);
glEnd();


   glBegin(GL_POLYGON);
glColor3d(255, 0, 230);
glVertex2d(336, 600);
glVertex2d(364, 600);
glVertex2d(364, 767);
glVertex2d(336, 767);
glEnd();
    }

        void kotak(){
    glBegin(GL_POLYGON);
glColor3ub(40, 35, 73);
glVertex2d(0, 0);
glVertex2d(0, 700);
glVertex2d(700, 700);
glVertex2d(700, 0);
glEnd();
    }

 int main(void) {
        //Window
        GLFWwindow* window;
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())exit(EXIT_FAILURE);
        window = glfwCreateWindow(700, 700, "Simple Example", NULL, NULL);

        if (!window){
          glfwTerminate();
          exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        glfwSetKeyCallback(window, key_callback);

        while (!glfwWindowShouldClose(window)){
          int width, height;
          glfwGetFramebufferSize(window, &width, &height);
          glViewport(0, 0, width, height);
          //fungsi untuk menampilkan objek
           setup_viewport(window);
           kotak();
           atas_kiri();
           bawah_kiri();
           bawah_kanan();
           atas_kanan();
           huruf_s();
           huruf_h();
           huruf_i();
           huruf_b();
           huruf_g();
           huruf_o();
           plus_atas();
           plus_bawah();
          glfwSwapBuffers(window);
          glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
