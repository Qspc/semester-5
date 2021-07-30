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
float i = 0;
float putar = 50;
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
            red = 78, green = 126, blue = 30;
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
            putar = 150;
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


        void plus_bawah(){
        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(506, 706.5);
    glVertex2d(549.5, 631.5);
    glVertex2d(592, 706.5);
    glEnd();

            glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(-10, 700);
    glVertex2d(32.5, 624.5);
    glVertex2d(75, 700);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(363, 708.5);
    glVertex2d(406.5, 633.5);
    glVertex2d(450, 708.5);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(233, 704.5);
    glVertex2d(276.5, 629.5);
    glVertex2d(320, 704.5);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(118, 705.5);
    glVertex2d(161.5, 630.5);
    glVertex2d(205, 705.5);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(563, 705);
    glVertex2d(606.5, 582.5);
    glVertex2d(650, 705);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(60, 700);
    glVertex2d(102.5, 577);
    glVertex2d(145, 700);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(631, 707.5);
    glVertex2d(674.5, 632.5);
    glVertex2d(717, 707.5);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(175, 713);
    glVertex2d(218.5, 590.5);
    glVertex2d(261, 713);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(22, 702);
    glVertex2d(66, 627);
    glVertex2d(110, 702);
    glEnd();

        glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(23, 702);
    glVertex2d(66, 627);
    glVertex2d(110, 702);
    glEnd();

            glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(87, 711);
    glVertex2d(130.5, 588.5);
    glVertex2d(173, 711);
    glEnd();

            glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(204, 717);
    glVertex2d(247, 641);
    glVertex2d(290, 717);
    glEnd();

            glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(530, 710);
    glVertex2d(575, 635);
    glVertex2d(617, 710);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(480, 723);
    glVertex2d(523, 600.5);
    glVertex2d(566, 723);
    glEnd();

            glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(438, 707);
    glVertex2d(481.5, 584.5);
    glVertex2d(525, 707.5);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(402, 717);
    glVertex2d(446, 642);
    glVertex2d(490, 717);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3ub(78, 126, 30);
    glVertex2d(338, 728);
    glVertex2d(381.5, 605.5);
    glVertex2d(425, 728);
    glEnd();

                glBegin(GL_TRIANGLES);
    glColor3ub(121, 178, 64);
    glVertex2d(296, 709);
    glVertex2d(339.5, 586.5);
    glVertex2d(382, 709);
    glEnd();
    }

        void kotak(){
    glBegin(GL_POLYGON);
glColor3ub(188, 243, 243);
glVertex2d(0, 0);
glVertex2d(0, 700);
glVertex2d(700, 700);
glVertex2d(700, 0);
glEnd();
    }

            void tiang(){
    glBegin(GL_POLYGON);
glColor3ub(0, 0, 0);
glVertex2d(338, 700);
glVertex2d(338, 338);
glVertex2d(363, 338);
glVertex2d(363, 700);
glEnd();
    }

    void kincir(){
        float i = 0;
        float theta = 0;
        glPushMatrix();
        glTranslatef(346.61, 345.284, 0);
        glRotatef((float) glfwGetTime() * putar,0,0, 1);
        glTranslatef(-346.61, -345.284, 0);

          glBegin(GL_POLYGON);
      glColor3ub(102,102,102);
      for(i=0;i<360;i++){
        theta=i*3.14/180;
        glVertex2d(350+25*cos(theta),346+25*sin(theta));
      }
      glEnd();

          glBegin(GL_POLYGON);
    glColor3ub(74,224, 223);
    glVertex2d(457.432, 458.9);
    glVertex2d(235.288 , 236.757);
    glVertex2d(240.945 , 231.1);
    glVertex2d(463.089, 453.243);
    glEnd();

              glBegin(GL_POLYGON);
    glColor3ub(74,224, 223);
    glVertex2d(233.288, 454.243 );
    glVertex2d(455.432, 232.1);
    glVertex2d(461.089, 237.757 );
    glVertex2d(238.945, 459.9 );
    glEnd();

                  glBegin(GL_POLYGON);
    glColor3ub(51,51, 51);
    glVertex2d(385.893, 309.893 );
    glVertex2d(459.719, 236.067);
    glVertex2d(477.326 , 253.674 );
    glVertex2d(403.5, 327.5);
    glEnd();

                glBegin(GL_POLYGON);
    glColor3ub(51,51, 51);
    glVertex2d(383.5, 385.067 );
    glVertex2d(457.326, 458.893);
    glVertex2d(439.719 , 476.5);
    glVertex2d(365.893, 402.674 );
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(51,51, 51);
    glVertex2d(215.893, 436.893);
    glVertex2d(289.719 , 363.067 );
    glVertex2d(307.326 , 380.674);
    glVertex2d(233.5, 454.5 );
    glEnd();

            glBegin(GL_POLYGON);
    glColor3ub(51,51, 51);
    glVertex2d(314.719, 305.5);
    glVertex2d(240.893  , 231.674 );
    glVertex2d(258.5 , 214.067 );
    glVertex2d(332.326 , 287.893);
    glEnd();
    glPopMatrix();
    }

    void awan(){
            float j = 0;
        float beta = 0;
          glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(156.5+50*cos(beta),119.5+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(227+50*cos(beta),149+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(292+50*cos(beta),142+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(289+50*cos(beta),90+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(203+50*cos(beta),87+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(475+50*cos(beta),115+50*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(526+50*cos(beta),100+50*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(583+50*cos(beta),138+50*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(519+36*cos(beta),165+36*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255,255,255);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(598.5+36*cos(beta),82.5+36*sin(beta));
      }
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

           kotak();
            tiang();
           plus_bawah();
           kincir();
           awan();

           rect.display();

          glfwSwapBuffers(window);
          glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
