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
    void atas_kiri()
    {
glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(24,15);
glVertex2d(191, 15);
glVertex2d(191, 49);
glVertex2d(24, 49);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(24,15);
glVertex2d(24, 182);
glVertex2d(57, 182);
glVertex2d(57, 15);
glEnd();
    }

    void atas_kanan()
    {
glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(683, 18);
glVertex2d(516,18);
glVertex2d(516, 52);
glVertex2d(683, 52);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(683,18);
glVertex2d(683, 185);
glVertex2d(650, 185);
glVertex2d(650, 18);
glEnd();
    }

    void bawah_kiri()
       {
glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(23, 673);
glVertex2d(23,506);
glVertex2d(57, 506);
glVertex2d(57, 673);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(53,639);
glVertex2d(220, 639);
glVertex2d(220, 673);
glVertex2d(53, 673);
glEnd();
    }

    void bawah_kanan(){
    glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(683, 672);
glVertex2d(516, 672);
glVertex2d(516, 638);
glVertex2d(683, 638);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3ub(238, 133, 181);
glVertex2d(650, 672);
glVertex2d(650, 505);
glVertex2d(684, 505);
glVertex2d(684, 672);
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
        glPushMatrix();
    glTranslatef(350, 15.5, 0);
    glRotatef((float) glfwGetTime() * 50,0,0, 1);
    glTranslatef(-350, -15.5, 0);
    glBegin(GL_LINE_LOOP);
glColor3d(255, 0, 230);
glVertex2d(266.5, 1);
glVertex2d(266.5, 29);
glVertex2d(433.5, 29);
glVertex2d(433.5, 1);
glEnd();

   glBegin(GL_LINE_LOOP);
glColor3d(255, 0, 230);
glVertex2d(335, -68);
glVertex2d(335, 99);
glVertex2d(365, 99);
glVertex2d(365, -68);
glEnd();
glPopMatrix();

    }

        void plus_bawah(){
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

        void garis(){
        glBegin(GL_QUADS);
    glColor3ub(238, 133, 181);
    glVertex2d(550+arah2, 410);
    glVertex2d(550+arah2, 420);
    glVertex2d(700+arah2, 420);
    glVertex2d(700+arah2, 410);
    glEnd();

            glBegin(GL_QUADS);
    glColor3ub(238, 133, 181);
    glVertex2d(550+arah2a, 430);
    glVertex2d(550+arah2a, 440);
    glVertex2d(700+arah2a, 440);
    glVertex2d(700+arah2a, 430);
    glEnd();

            glBegin(GL_QUADS);
    glColor3ub(238, 133, 181);
    glVertex2d(550+arah2b, 450);
    glVertex2d(550+arah2b, 460);
    glVertex2d(700+arah2b, 460);
    glVertex2d(700+arah2b, 450);
    glEnd();

            glBegin(GL_QUADS);
    glColor3ub(238, 133, 181);
    glVertex2d(0+arah, 256);
    glVertex2d(0+arah, 266);
    glVertex2d(150+arah, 266);
    glVertex2d(150+arah, 256);
    glEnd();

                glBegin(GL_QUADS);
    glColor3ub(238, 133, 181);
    glVertex2d(0+araha, 236);
    glVertex2d(0+araha, 246);
    glVertex2d(150+araha, 246);
    glVertex2d(150+araha, 236);
    glEnd();

                glBegin(GL_QUADS);
    glColor3ub(238, 133, 181);
    glVertex2d(0+arahb, 276);
    glVertex2d(0+arahb, 286);
    glVertex2d(150+arahb, 286);
    glVertex2d(150+arahb, 276);
    glEnd();
    }

void huruf_s2(){
    glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(191, 310.5);
glVertex2d(111, 310.5);
glVertex2d(111, 325.5);
glVertex2d(191, 325.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(111, 310.5);
glVertex2d(111, 361.5);
glVertex2d(125, 361.5);
glVertex2d(125, 310.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(111, 346.5);
glVertex2d(191.5, 346.5);
glVertex2d(191.5, 361.5);
glVertex2d(111, 361.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(191.5, 346.5);
glVertex2d(191.5, 397);
glVertex2d(176.5, 397);
glVertex2d(176.5, 346.5);
glEnd();

    glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(111, 382.5);
glVertex2d(191.5, 382.5);
glVertex2d(191.5, 397);
glVertex2d(111, 397);
glEnd();
    }

    void huruf_h2(){
    glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(211.5, 316);
glVertex2d(226.5, 316);
glVertex2d(226.5, 396);
glVertex2d(211.5, 396);
glEnd();
        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(211.5, 346.5);
glVertex2d(291, 346.5);
glVertex2d(291, 361.5);
glVertex2d(211.5, 361.5);
glEnd();
        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(276.5, 316);
glVertex2d(291.5, 316);
glVertex2d(291.5, 396);
glVertex2d(276.5, 396);
glEnd();

    }

    void huruf_i2(){
            glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(310.5, 316);
glVertex2d(325.5, 316);
glVertex2d(325.5, 396);
glVertex2d(310.5, 396);
glEnd();
    }

    void huruf_b2(){
        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(345, 311);
glVertex2d(359.5, 311);
glVertex2d(359.5, 397);
glVertex2d(345, 397);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(345, 311);
glVertex2d(400, 311);
glVertex2d(400, 326);
glVertex2d(345, 326);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(385, 311);
glVertex2d(400, 311);
glVertex2d(400, 361);
glVertex2d(385, 361);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(345, 346.5);
glVertex2d(426, 346.5);
glVertex2d(426, 361.5);
glVertex2d(345, 361.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(426, 346.5);
glVertex2d(426, 397);
glVertex2d(411.5, 397);
glVertex2d(411.5, 346.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(426, 382.5);
glVertex2d(426, 397);
glVertex2d(345, 397);
glVertex2d(345, 382.5);
glEnd();
    }

   void huruf_g2(){
        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(446.5, 314.5);
glVertex2d(528, 314.5);
glVertex2d(528, 329.5);
glVertex2d(446.5, 329.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(446.5, 314.5);
glVertex2d(461.5, 314.5);
glVertex2d(461.5, 396);
glVertex2d(446.5, 396);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(446.5, 381.5);
glVertex2d(527, 381.5);
glVertex2d(527, 396);
glVertex2d(446.5, 396);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(527, 345.5);
glVertex2d(527, 396);
glVertex2d(512.5, 396);
glVertex2d(512.5, 345.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(477, 345.5);
glVertex2d(527, 345.5);
glVertex2d(527, 360.5);
glVertex2d(477, 360.5);
glEnd();
    }

    void huruf_o2(){
        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(551.5, 313.5);
glVertex2d(635, 313.5);
glVertex2d(635, 328.5);
glVertex2d(551.5, 328.5);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(553.5, 313.5);
glVertex2d(568.5, 313.5);
glVertex2d(568.5, 395);
glVertex2d(553.5, 395);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(551.5, 379.5);
glVertex2d(634, 379.5);
glVertex2d(634, 395);
glVertex2d(551.5, 395);
glEnd();

        glBegin(GL_POLYGON);
glColor3d(0,0,0);
glVertex2d(619.5, 313.5);
glVertex2d(635, 313.5);
glVertex2d(635, 395);
glVertex2d(619.5, 395);
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
           atas_kiri();
           bawah_kiri();
           bawah_kanan();
           atas_kanan();
                      huruf_s2();
           huruf_h2();
           huruf_i2();
           huruf_b2();
           huruf_g2();
           huruf_o2();
           huruf_s();
           huruf_h();
           huruf_i();
           huruf_b();
           huruf_g();
           huruf_o();

           plus_atas();
           plus_bawah();
           garis();
           rect.display();

           if (arah < 700)
            arah += 0.3;
           else arah = 0;
           if (araha < 700)
            araha += 0.1;
           else araha = 0;
           if (arahb < 700)
            arahb += 0.05;
           else arahb = 0;
           if (arah2 > -700)
            arah2 -= 0.1;
            else arah2 = 0;
            if (arah2a > -700)
            arah2a -= 0.3;
            else arah2a = 0;
            if (arah2b > -700)
            arah2b -= 0.05;
            else arah2b = 0;

          glfwSwapBuffers(window);
          glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
