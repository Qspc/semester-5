#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <list>
#include <iterator>
//241 488 384 470
using namespace std;

GLboolean FOLLOW = GL_FALSE;       // Variabel untuk mengecek apakah mouse sudah klik di kotak apa belum

float red=100, green=100;
float arah=0.0, araha=0.0, arahb=0.0;
float arah2=0.0, arah2a=0.0, arah2b=0.0;
float i = 0;
float putar = 0, putar2 = 0, putar3 = 0, putar4 = 0;
float putar5 = 0, putar6 = 0, putar7 = 0;
bool gerak = true;

class Rectangle{    // Buat kelas rectangle
public:
    double x=0, y=0;
    double prevY = 0;
    int red = 0, green = 0, blue = 0;
    int size = 11;  // def size

        void batu1(){
                glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(241+x,488+y);
        glVertex2d(259+x,477+y);
        glVertex2d(276+x,488+y);
        glVertex2d(258+x,498+y);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(241+x,488+y);
        glVertex2d(258+x,498+y);
        glVertex2d(258+x,515+y);
        glVertex2d(241+x,506+y);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(258+x,498+y);
        glVertex2d(276+x,488+y);
        glVertex2d(276+x,505+y);
        glVertex2d(258+x,515+y);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(276+x,514+y);
        glVertex2d(291+x,506+y);
        glVertex2d(291+x,512+y);
        glVertex2d(276+x,520+y);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(259+x,504+y);
        glVertex2d(275.74+x,496.06+y);
        glVertex2d(291+x,506+y);
        glVertex2d(276+x,514+y);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(259+x,504+y);
        glVertex2d(276+x,514+y);
        glVertex2d(276+x,520+y);
        glVertex2d(259+x,511+y);
        glEnd();
    }
    // Lakukan pengecekan posisi kursor terhadap tepi luar kotak yang digambar
    GLboolean isRectangleSelected(double xpos, double ypos){
        double left = 0;
        double right = 700;
        double top = 700;
        double bottom = 0;

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
        if (key == GLFW_KEY_Z  && action == GLFW_PRESS)
            putar5 = 173, putar6 = 146, putar7 = -37;
        if (key == GLFW_KEY_X  && action == GLFW_PRESS)
            putar5 = 0, putar6 = 0, putar7 = 0;
    }
    void doIfClicked(int button, int action, double xpos, double ypos){
        double left = 0;
        double right = 700;
        double top = 700;
        double bottom = 0;
        if (button == GLFW_MOUSE_BUTTON_LEFT && ((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom)) && action == GLFW_PRESS){
            putar = -179, putar2 = -255, putar3 = 9, putar4 = 172;

        }
        else if (button == GLFW_MOUSE_BUTTON_RIGHT && ((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom)) && action == GLFW_PRESS){
            putar = 0, putar2 = 0, putar3 = 0, putar4 = 0;

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


    void awan(){
            float j = 0;
        float beta = 0;
          glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(156.5+arah+50*cos(beta),119.5+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(227+arah+50*cos(beta),149+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(292+arah+50*cos(beta),142+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(289+arah+50*cos(beta),90+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(203+arah+50*cos(beta),87+50*sin(beta));
      }
      glEnd();

                glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(475+arah+50*cos(beta),115+50*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(526+arah+50*cos(beta),100+50*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(583+arah+50*cos(beta),138+50*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(519+arah+36*cos(beta),165+36*sin(beta));
      }
      glEnd();

                      glBegin(GL_POLYGON);
      glColor3ub(255+putar2,255+putar2,255+putar2);
      for(i=0;i<360;i++){
        beta=i*3.14/180;
        glVertex2d(598.5+arah+36*cos(beta),82.5+36*sin(beta));
      }
      glEnd();
    }

    void kotak(){

        glBegin(GL_POLYGON);
        glColor3ub(179+putar,255+putar2,255+putar2);
        glVertex2d(0,0);
        glVertex2d(700,0);
        glVertex2d(700,700);
        glVertex2d(0,700);
        glEnd();
    }

        void latar(){

        glBegin(GL_POLYGON);
        glColor3ub(146,176,114);
        glVertex2d(16,397);
        glVertex2d(340,585);
        glVertex2d(680,389);
        glVertex2d(359,200);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(247,220,170);
        glVertex2d(133,329);
        glVertex2d(359,200);
        glVertex2d(558,317);
        glVertex2d(336,447);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(92,132,83);
        glVertex2d(16,397);
        glVertex2d(340,585);
        glVertex2d(340.96,597.52);
        glVertex2d(16,410);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(92,132,83);
        glVertex2d(340,585);
        glVertex2d(340.96,597.52);
        glVertex2d(680,402);
        glVertex2d(680,389);
        glEnd();
    }

    void pohon1() {
        glBegin(GL_POLYGON);
        glColor3ub(153,203,131);
        glVertex2d(330,547);
        glVertex2d(312,537);
        glVertex2d(330,526);
        glVertex2d(347,538);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(128,199,119);
        glVertex2d(330,547);
        glVertex2d(329,562);
        glVertex2d(312,553);
        glVertex2d(312,537);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(76,170,108);
        glVertex2d(330,547);
        glVertex2d(329,562);
        glVertex2d(347,552);
        glVertex2d(347,538);
        glEnd();
    }

    void pohon2(){
            glBegin(GL_POLYGON);
        glColor3ub(120,73,40);
        glVertex2d(314,480);
        glVertex2d(314,495);
        glVertex2d(321,490);
        glVertex2d(321,476);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(120,73,40);
        glVertex2d(314,480);
        glVertex2d(314,495);
        glVertex2d(308,492);
        glVertex2d(308,476);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(76,170,108);
        glVertex2d(314,480);
        glVertex2d(336,467);
        glVertex2d(336,433);
        glVertex2d(314,447);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(128,199,118);
        glVertex2d(314,480);
        glVertex2d(292,469);
        glVertex2d(292,434);
        glVertex2d(314,447);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(153,203,131);
        glVertex2d(314,447);
        glVertex2d(292,434);
        glVertex2d(314,421);
        glVertex2d(336,433);
        glEnd();
    }

    void pohon3(){
            glBegin(GL_POLYGON);
        glColor3ub(120,73,40);
        glVertex2d(214,430);
        glVertex2d(214,445);
        glVertex2d(221,440);
        glVertex2d(221,426);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(120,73,40);
        glVertex2d(214,430);
        glVertex2d(214,445);
        glVertex2d(208,442);
        glVertex2d(208,426);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(76,170,108);
        glVertex2d(214,430);
        glVertex2d(236,417);
        glVertex2d(236,383);
        glVertex2d(214,397);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(128,199,118);
        glVertex2d(214,430);
        glVertex2d(192,419);
        glVertex2d(192,384);
        glVertex2d(214,397);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(153,203,131);
        glVertex2d(214,397);
        glVertex2d(192,384);
        glVertex2d(214,371);
        glVertex2d(236,383);
        glEnd();
    }

    void pohon4(){
            glBegin(GL_POLYGON);
        glColor3ub(120,73,40);
        glVertex2d(84,380);
        glVertex2d(84,395);
        glVertex2d(91,390);
        glVertex2d(91,376);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(120,73,40);
        glVertex2d(84,380);
        glVertex2d(84,395);
        glVertex2d(78,392);
        glVertex2d(78,376);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(76,170,108);
        glVertex2d(84,380);
        glVertex2d(106,367);
        glVertex2d(106,333);
        glVertex2d(84,347);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(128,199,118);
        glVertex2d(84,380);
        glVertex2d(62,369);
        glVertex2d(62,334);
        glVertex2d(84,347);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(153,203,131);
        glVertex2d(84,347);
        glVertex2d(62,334);
        glVertex2d(84,321);
        glVertex2d(106,333);
        glEnd();
    }



        void batu2(){
                glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(101,388);
        glVertex2d(119,377);
        glVertex2d(136,388);
        glVertex2d(118,398);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(101,388);
        glVertex2d(118,398);
        glVertex2d(118,415);
        glVertex2d(101,406);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(118,398);
        glVertex2d(136,388);
        glVertex2d(136,405);
        glVertex2d(118,415);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(136,414);
        glVertex2d(151,406);
        glVertex2d(151,412);
        glVertex2d(136,420);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(119,404);
        glVertex2d(135.74,396.06);
        glVertex2d(151,406);
        glVertex2d(136,414);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(119,404);
        glVertex2d(136,414);
        glVertex2d(136,420);
        glVertex2d(119,411);
        glEnd();
    }

    void batu3(){
                glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(381,473);
        glVertex2d(399,462);
        glVertex2d(416,473);
        glVertex2d(398,483);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(381,473);
        glVertex2d(398,483);
        glVertex2d(398,500);
        glVertex2d(381,491);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(398,483);
        glVertex2d(416,473);
        glVertex2d(416,490);
        glVertex2d(398,500);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(385,496);
        glVertex2d(398,488);
        glVertex2d(398,494);
        glVertex2d(385,502);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(385,496);
        glVertex2d(398,488);
        glVertex2d(384.16,478.6);
        glVertex2d(370,486);
        glEnd();

                glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(385,496);
        glVertex2d(370,486);
        glVertex2d(370,492);
        glVertex2d(385,502);
        glEnd();
    }


    void kolam(){
            glBegin(GL_POLYGON);
        glColor3ub(255,255,255);
        glVertex2d(488,482);
        glVertex2d(381,420);
        glVertex2d(557.56,316.6);
        glVertex2d(664.84,379.96);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(193,209,215);
        glVertex2d(487,475);
        glVertex2d(392,419);
        glVertex2d(558,323);
        glVertex2d(654,378);
        glEnd();

            glBegin(GL_POLYGON);
        glColor3ub(3,172,230);
        glVertex2d(487,475);
        glVertex2d(397,422);
        glVertex2d(557,329);
        glVertex2d(650,381);
        glEnd();
    }

    void rumah(){
        glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(182,228);
        glVertex2d(348,323);
        glVertex2d(348,420);
        glVertex2d(182,325);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(348,323);
        glVertex2d(348,420);
        glVertex2d(519,318);
        glVertex2d(519,226);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(489,242);
        glVertex2d(519,226);
        glVertex2d(519,151);
        glVertex2d(491,166);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(232,232,232);
        glVertex2d(463,150);
        glVertex2d(462,227);
        glVertex2d(355,287);
        glVertex2d(355,207);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(355,287);
        glVertex2d(355,207);
        glVertex2d(218,132);
        glVertex2d(217,207);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(244,241,247);
        glVertex2d(355,207);
        glVertex2d(218,132);
        glVertex2d(323,70);
        glVertex2d(463,150);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(244,241,247);
        glVertex2d(519,151);
        glVertex2d(491,166);
        glVertex2d(353,87);
        glVertex2d(380,69);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(198,211,199);
        glVertex2d(463,150);
        glVertex2d(462,227);
        glVertex2d(489,242);
        glVertex2d(491,166);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(462,227);
        glVertex2d(489,242);
        glVertex2d(348,323);
        glVertex2d(355,287);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(166,152,160);
        glVertex2d(348,323);
        glVertex2d(355,287);
        glVertex2d(217,207);
        glVertex2d(182,228);
        glEnd();

//jendela
        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(508,251);
        glVertex2d(492,260);
        glVertex2d(492,320);
        glVertex2d(509,310);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(488,262);
        glVertex2d(470,272);
        glVertex2d(471,332);
        glVertex2d(488,321);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(467,275);
        glVertex2d(449,285);
        glVertex2d(449,345);
        glVertex2d(468,334);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(445,287);
        glVertex2d(427,298);
        glVertex2d(427,357);
        glVertex2d(446,347);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(424,300);
        glVertex2d(404,311);
        glVertex2d(405,370);
        glVertex2d(425,359);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(240,288);
        glVertex2d(231,282);
        glVertex2d(231,325);
        glVertex2d(239,330);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(226,280);
        glVertex2d(191,260);
        glVertex2d(190,325);
        glVertex2d(225,345);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(252,165);
        glVertex2d(251,225);
        glVertex2d(354.76,284.68);
        glVertex2d(356,225);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(354.76,284.68);
        glVertex2d(356,225);
        glVertex2d(429,183);
        glVertex2d(429.88,241.48);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(433,181);
        glVertex2d(439,177);
        glVertex2d(439,237);
        glVertex2d(433,240);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(82+putar5,100+putar6,120+putar7);
        glVertex2d(442,176);
        glVertex2d(459,166);
        glVertex2d(460,225);
        glVertex2d(443,235);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,0,0);
        glVertex2d(209.08,270.52);
        glVertex2d(207,270);
        glVertex2d(206.68,334.6);
        glVertex2d(208.88,335.44);
        glEnd();
    }

    void matahari(){
        float i = 0;
        float beta2 = 0;
          glBegin(GL_POLYGON);
      glColor3ub(255,246+putar3,83+putar4);
      for(i=0;i<360;i++){
        beta2=i*3.14/180;
        glVertex2d(646.5+40*cos(beta2),47.5+40*sin(beta2));
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
           matahari();
           awan();
           latar();
           pohon1();
           pohon2();
           pohon3();
           pohon4();
           rect.batu1();
           batu2();
           batu3();
           kolam();
           rumah();
          // rect.display();

           if (arah < 900)
            arah += 0.3;
            else arah = -700;

          glfwSwapBuffers(window);
          glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
