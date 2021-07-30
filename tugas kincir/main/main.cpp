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
float arah=0.0, araha=0.0, arahb=0.0;
float arah2=0.0, arah2a=0.0, arah2b=0.0;
bool gerak = true;

class Rectangle{    // Buat kelas rectangle
public:
    double x=34, y=466;
    double prevY = 0;
    int red = 0, green = 0, blue = 0;
    int size = 11;  // def size

    void display()
    {
        glBegin(GL_QUADS);    // Buat kotak
            glColor3ub(red, green, blue);   // Define warna
            // Define koordinat untuk kotak
            glVertex2f(123,  564);
            glVertex2f( 157,  564);
            glVertex2f(157, 530);
            glVertex2f(123, 530);
        glEnd();    // End membuat kotak
    }
    // Lakukan pengecekan posisi kursor terhadap tepi luar kotak yang digambar
    GLboolean isRectangleSelected(double xpos, double ypos){
        double left = 123;
        double right = 157;
        double top = 564;
        double bottom = 530;

        if((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom))
            return GL_TRUE;
        else
            return GL_FALSE;
    }
    void doIfSelected(double xpos, double ypos){
        if(isRectangleSelected(xpos, ypos) == GL_TRUE)
            red = 255, green = 0, blue = 230;
        else
            red = 40,green = 35,blue = 73;
    }
    void doIfKeyPressed(int key, int action){
        if (key == GLFW_KEY_UP && action == GLFW_PRESS)
            y-=10;
        if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
            y+=10;
        if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
            x-=10;
        if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
            x+=10;
    }
    void doIfClicked(int button, int action, double xpos, double ypos){
        double left = 123;
        double right = 157;
        double top = 564;
        double bottom = 530;
        if (button == GLFW_MOUSE_BUTTON_LEFT && ((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom)) && action == GLFW_PRESS){
            arah = araha = arahb = 0;
            arah2 = arah2a = arah2b = 0;
        }
        else
            GL_FALSE;
    }
};
Rectangle rect; // Define rectangle

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    rect.doIfKeyPressed(key, action);
}

static void error_callback(int error, const char* description) {
    //fputs(description);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    rect.doIfSelected(xpos, ypos);       // memanggil fungsi untuk menggerakan kotak sama dengan mouse
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
    glOrtho(0, 700, 700, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

    void segitiga(){
glBegin(GL_TRIANGLES);
glColor3ub(188, 243, 243);
glVertex2d(-10,700);
glVertex2d(32.5, 624.5);
glVertex2d(75, 700);
glEnd();

    }


    glPushMatrix();
    glTranslatef(350, 679.25, 0);
    glRotatef((float) glfwGetTime() * 50,0,0, 1);
    glTranslatef(-350, -679.25, 0);
    glBegin(GL_TRIANGLES);
    glColor3d(255, 0, 230);
    glVertex2d(350, 612);
    glVertex2d(428, 746.5);
    glVertex2d(272, 746.5);
    glEnd();
    glPopMatrix();

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
    /* Creating Windows */
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit());
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(700, 700, "tugas grafkom", NULL, NULL);
    if (!window){
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Registering Callbacks */
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

        while (!glfwWindowShouldClose(window)){
          int width, height;
          glfwGetFramebufferSize(window, &width, &height);
          glViewport(0, 0, width, height);
          //fungsi untuk menampilkan objek
           setup_viewport(window);
           segitiga();
           kotak();

           rect.display();

          glfwSwapBuffers(window);
          glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
