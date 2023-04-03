#include <iostream>
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>
using namespace std;

bool up = false;
bool down = false;
bool bleft = false;
bool bright = false;

bool more = false;
bool menos = false;
bool reset = false;

bool menorTamanho = false;
bool maiorTamanho = false;

bool contructor = false;

struct Ponto {

	float x;
	float y;
	float z;
};

struct Face
{
	Ponto a;
	Ponto b;
	Ponto c;
	Ponto d;
};

struct Cubo
{
	Face verde;
	Face laranja;
	Face azul;
	Face vermelho;
	Face magenta;
	Face amarelo;
};




void rotationX(Ponto& ponto, double x, double y, double z) {

	double rad = 0;

	rad = x;
	ponto.y = cos(rad) * ponto.y - sin(rad) * ponto.z;
	ponto.z = sin(rad) * ponto.y + cos(rad) * ponto.z;

}
void rotationY(Ponto& ponto, double x, double y, double z) {
	double rad = 0;

	rad = y;
	ponto.x = cos(rad) * ponto.x + sin(rad) * ponto.z;
	ponto.z = -sin(rad) * ponto.x + cos(rad) * ponto.z;
}

void translation(Ponto& ponto, double x, double y, double z) {

	ponto.x = ponto.x + x;
	ponto.y = ponto.y + y;
	ponto.z = ponto.z + z;

}

void scale(Ponto& ponto, double x, double y, double z) {

	ponto.x = ponto.x * x;
	ponto.y = ponto.y * y;
	ponto.z = ponto.z * z;

}


void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Coloca a cor de background para preto e opaco
	glClearDepth(1.0f);                   // Define o buffer de profundidade para o mais distante possível
	glEnable(GL_DEPTH_TEST);   // Habilita o culling de profundidade
	glDepthFunc(GL_LEQUAL);    // Define o tipo de teste de profundidade
}

Cubo cubo;
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	if (!contructor || reset) {

		//Verde
		cubo.verde.a.x = 1.0f;
		cubo.verde.a.y = 1.0f;
		cubo.verde.a.z = -1.0f;

		cubo.verde.b.x = -1.0f;
		cubo.verde.b.y = 1.0f;
		cubo.verde.b.z = -1.0f;

		cubo.verde.c.x = -1.0f;
		cubo.verde.c.y = 1.0f;
		cubo.verde.c.z = 1.0f;

		cubo.verde.d.x = 1.0f;
		cubo.verde.d.y = 1.0f;
		cubo.verde.d.z = 1.0f;

		//Laranja
		cubo.laranja.a.x = 1.0f;
		cubo.laranja.a.y = -1.0f;
		cubo.laranja.a.z = 1.0f;

		cubo.laranja.b.x = -1.0f;
		cubo.laranja.b.y = -1.0f;
		cubo.laranja.b.z = 1.0f;

		cubo.laranja.c.x = -1.0f;
		cubo.laranja.c.y = -1.0f;
		cubo.laranja.c.z = -1.0f;

		cubo.laranja.d.x = 1.0f;
		cubo.laranja.d.y = -1.0f;
		cubo.laranja.d.z = -1.0f;

		//Vermelho
		cubo.vermelho.a.x = 1.0f;
		cubo.vermelho.a.y = 1.0f;
		cubo.vermelho.a.z = 1.0f;

		cubo.vermelho.b.x = -1.0f;
		cubo.vermelho.b.y = 1.0f;
		cubo.vermelho.b.z = 1.0f;

		cubo.vermelho.c.x = -1.0f;
		cubo.vermelho.c.y = -1.0f;
		cubo.vermelho.c.z = 1.0f;

		cubo.vermelho.d.x = 1.0f;
		cubo.vermelho.d.y = -1.0f;
		cubo.vermelho.d.z = 1.0f;

		//Amarelo
		cubo.amarelo.a.x = 1.0f;
		cubo.amarelo.a.y = -1.0f;
		cubo.amarelo.a.z = -1.0f;

		cubo.amarelo.b.x = -1.0f;
		cubo.amarelo.b.y = -1.0f;
		cubo.amarelo.b.z = -1.0f;

		cubo.amarelo.c.x = -1.0f;
		cubo.amarelo.c.y = 1.0f;
		cubo.amarelo.c.z = -1.0f;

		cubo.amarelo.d.x = 1.0f;
		cubo.amarelo.d.y = 1.0f;
		cubo.amarelo.d.z = -1.0f;

		//Azul
		cubo.azul.a.x = -1.0f;
		cubo.azul.a.y = 1.0f;
		cubo.azul.a.z = 1.0f;

		cubo.azul.b.x = -1.0f;
		cubo.azul.b.y = 1.0f;
		cubo.azul.b.z = -1.0f;

		cubo.azul.c.x = -1.0f;
		cubo.azul.c.y = -1.0f;
		cubo.azul.c.z = -1.0f;

		cubo.azul.d.x = -1.0f;
		cubo.azul.d.y = -1.0f;
		cubo.azul.d.z = 1.0f;

		//Magenta
		cubo.magenta.a.x = 1.0f;
		cubo.magenta.a.y = 1.0f;
		cubo.magenta.a.z = -1.0f;

		cubo.magenta.b.x = 1.0f;
		cubo.magenta.b.y = 1.0f;
		cubo.magenta.b.z = 1.0f;

		cubo.magenta.c.x = 1.0f;
		cubo.magenta.c.y = -1.0f;
		cubo.magenta.c.z = 1.0f;

		cubo.magenta.d.x = 1.0f;
		cubo.magenta.d.y = -1.0f;
		cubo.magenta.d.z = -1.0f;

		contructor = true;
	}

	if (up) {
		//Verde
		rotationX(cubo.verde.a, -0.001, 0, 0);
		rotationX(cubo.verde.b, -0.001, 0, 0);
		rotationX(cubo.verde.c, -0.001, 0, 0);
		rotationX(cubo.verde.d, -0.001, 0, 0);

		//Laranja
		rotationX(cubo.laranja.a, -0.001, 0, 0);
		rotationX(cubo.laranja.b, -0.001, 0, 0);
		rotationX(cubo.laranja.c, -0.001, 0, 0);
		rotationX(cubo.laranja.d, -0.001, 0, 0);

		//Vermelho
		rotationX(cubo.vermelho.a, -0.001, 0, 0);
		rotationX(cubo.vermelho.b, -0.001, 0, 0);
		rotationX(cubo.vermelho.c, -0.001, 0, 0);
		rotationX(cubo.vermelho.d, -0.001, 0, 0);

		//Amarelo
		rotationX(cubo.amarelo.a, -0.001, 0, 0);
		rotationX(cubo.amarelo.b, -0.001, 0, 0);
		rotationX(cubo.amarelo.c, -0.001, 0, 0);
		rotationX(cubo.amarelo.d, -0.001, 0, 0);

		//Azul
		rotationX(cubo.azul.a, -0.001, 0, 0);
		rotationX(cubo.azul.b, -0.001, 0, 0);
		rotationX(cubo.azul.c, -0.001, 0, 0);
		rotationX(cubo.azul.d, -0.001, 0, 0);

		//Magenta
		rotationX(cubo.magenta.a, -0.001, 0, 0);
		rotationX(cubo.magenta.b, -0.001, 0, 0);
		rotationX(cubo.magenta.c, -0.001, 0, 0);
		rotationX(cubo.magenta.d, -0.001, 0, 0);


	}

	if (down) {
		//Verde
		rotationX(cubo.verde.a, 0.001, 0, 0);
		rotationX(cubo.verde.b, 0.001, 0, 0);
		rotationX(cubo.verde.c, 0.001, 0, 0);
		rotationX(cubo.verde.d, 0.001, 0, 0);

		//Laranja
		rotationX(cubo.laranja.a, 0.001, 0, 0);
		rotationX(cubo.laranja.b, 0.001, 0, 0);
		rotationX(cubo.laranja.c, 0.001, 0, 0);
		rotationX(cubo.laranja.d, 0.001, 0, 0);

		//VeRmelho
		rotationX(cubo.vermelho.a, 0.001, 0, 0);
		rotationX(cubo.vermelho.b, 0.001, 0, 0);
		rotationX(cubo.vermelho.c, 0.001, 0, 0);
		rotationX(cubo.vermelho.d, 0.001, 0, 0);

		//Amarelo
		rotationX(cubo.amarelo.a, 0.001, 0, 0);
		rotationX(cubo.amarelo.b, 0.001, 0, 0);
		rotationX(cubo.amarelo.c, 0.001, 0, 0);
		rotationX(cubo.amarelo.d, 0.001, 0, 0);

		//Azul
		rotationX(cubo.azul.a, 0.001, 0, 0);
		rotationX(cubo.azul.b, 0.001, 0, 0);
		rotationX(cubo.azul.c, 0.001, 0, 0);
		rotationX(cubo.azul.d, 0.001, 0, 0);

		//Magenta
		rotationX(cubo.magenta.a, 0.001, 0, 0);
		rotationX(cubo.magenta.b, 0.001, 0, 0);
		rotationX(cubo.magenta.c, 0.001, 0, 0);
		rotationX(cubo.magenta.d, 0.001, 0, 0);


	}

	if (bleft) {
		//Verde
		rotationY(cubo.verde.a, 0, -0.001, 0);
		rotationY(cubo.verde.b, 0, -0.001, 0);
		rotationY(cubo.verde.c, 0, -0.001, 0);
		rotationY(cubo.verde.d, 0, -0.001, 0);

		//Laranja
		rotationY(cubo.laranja.a, 0, -0.001, 0);
		rotationY(cubo.laranja.b, 0, -0.001, 0);
		rotationY(cubo.laranja.c, 0, -0.001, 0);
		rotationY(cubo.laranja.d, 0, -0.001, 0);

		//VeRmelho
		rotationY(cubo.vermelho.a, 0, -0.001, 0);
		rotationY(cubo.vermelho.b, 0, -0.001, 0);
		rotationY(cubo.vermelho.c, 0, -0.001, 0);
		rotationY(cubo.vermelho.d, 0, -0.001, 0);

		//Amarelo
		rotationY(cubo.amarelo.a, 0, -0.001, 0);
		rotationY(cubo.amarelo.b, 0, -0.001, 0);
		rotationY(cubo.amarelo.c, 0, -0.001, 0);
		rotationY(cubo.amarelo.d, 0, -0.001, 0);

		//Azul
		rotationY(cubo.azul.a, 0, -0.001, 0);
		rotationY(cubo.azul.b, 0, -0.001, 0);
		rotationY(cubo.azul.c, 0, -0.001, 0);
		rotationY(cubo.azul.d, 0, -0.001, 0);

		//Magenta
		rotationY(cubo.magenta.a, 0, -0.001, 0);
		rotationY(cubo.magenta.b, 0, -0.001, 0);
		rotationY(cubo.magenta.c, 0, -0.001, 0);
		rotationY(cubo.magenta.d, 0, -0.001, 0);


	}

	if (bright) {
		//Verde
		rotationY(cubo.verde.a, 0, 0.001, 0);
		rotationY(cubo.verde.b, 0, 0.001, 0);
		rotationY(cubo.verde.c, 0, 0.001, 0);
		rotationY(cubo.verde.d, 0, 0.001, 0);

		//Laranja
		rotationY(cubo.laranja.a, 0, 0.001, 0);
		rotationY(cubo.laranja.b, 0, 0.001, 0);
		rotationY(cubo.laranja.c, 0, 0.001, 0);
		rotationY(cubo.laranja.d, 0, 0.001, 0);

		//VeRmelho
		rotationY(cubo.vermelho.a, 0, 0.001, 0);
		rotationY(cubo.vermelho.b, 0, 0.001, 0);
		rotationY(cubo.vermelho.c, 0, 0.001, 0);
		rotationY(cubo.vermelho.d, 0, 0.001, 0);

		//Amarelo
		rotationY(cubo.amarelo.a, 0, 0.001, 0);
		rotationY(cubo.amarelo.b, 0, 0.001, 0);
		rotationY(cubo.amarelo.c, 0, 0.001, 0);
		rotationY(cubo.amarelo.d, 0, 0.001, 0);

		//Azul
		rotationY(cubo.azul.a, 0, 0.001, 0);
		rotationY(cubo.azul.b, 0, 0.001, 0);
		rotationY(cubo.azul.c, 0, 0.001, 0);
		rotationY(cubo.azul.d, 0, 0.001, 0);

		//Magenta
		rotationY(cubo.magenta.a, 0, 0.001, 0);
		rotationY(cubo.magenta.b, 0, 0.001, 0);
		rotationY(cubo.magenta.c, 0, 0.001, 0);
		rotationY(cubo.magenta.d, 0, 0.001, 0);


	}

	if (more) {
		//Verde
		scale(cubo.verde.a, 1.001, 1.001, 1.001);
		scale(cubo.verde.b, 1.001, 1.001, 1.001);
		scale(cubo.verde.c, 1.001, 1.001, 1.001);
		scale(cubo.verde.d, 1.001, 1.001, 1.001);

		//Laranja
		scale(cubo.laranja.a, 1.001, 1.001, 1.001);
		scale(cubo.laranja.b, 1.001, 1.001, 1.001);
		scale(cubo.laranja.c, 1.001, 1.001, 1.001);
		scale(cubo.laranja.d, 1.001, 1.001, 1.001);

		//VeRmelho
		scale(cubo.vermelho.a, 1.001, 1.001, 1.001);
		scale(cubo.vermelho.b, 1.001, 1.001, 1.001);
		scale(cubo.vermelho.c, 1.001, 1.001, 1.001);
		scale(cubo.vermelho.d, 1.001, 1.001, 1.001);

		//Amarelo
		scale(cubo.amarelo.a, 1.001, 1.001, 1.001);
		scale(cubo.amarelo.b, 1.001, 1.001, 1.001);
		scale(cubo.amarelo.c, 1.001, 1.001, 1.001);
		scale(cubo.amarelo.d, 1.001, 1.001, 1.001);

		//Azul
		scale(cubo.azul.a, 1.001, 1.001, 1.001);
		scale(cubo.azul.b, 1.001, 1.001, 1.001);
		scale(cubo.azul.c, 1.001, 1.001, 1.001);
		scale(cubo.azul.d, 1.001, 1.001, 1.001);

		//Magenta
		scale(cubo.magenta.a, 1.001, 1.001, 1.001);
		scale(cubo.magenta.b, 1.001, 1.001, 1.001);
		scale(cubo.magenta.c, 1.001, 1.001, 1.001);
		scale(cubo.magenta.d, 1.001, 1.001, 1.001);
	}

	if (menos) {
		//Verde
		scale(cubo.verde.a, 0.999, 0.999, 0.999);
		scale(cubo.verde.b, 0.999, 0.999, 0.999);
		scale(cubo.verde.c, 0.999, 0.999, 0.999);
		scale(cubo.verde.d, 0.999, 0.999, 0.999);

		//Laranja
		scale(cubo.laranja.a, 0.999, 0.999, 0.999);
		scale(cubo.laranja.b, 0.999, 0.999, 0.999);
		scale(cubo.laranja.c, 0.999, 0.999, 0.999);
		scale(cubo.laranja.d, 0.999, 0.999, 0.999);

		//VeRmelho
		scale(cubo.vermelho.a, 0.999, 0.999, 0.999);
		scale(cubo.vermelho.b, 0.999, 0.999, 0.999);
		scale(cubo.vermelho.c, 0.999, 0.999, 0.999);
		scale(cubo.vermelho.d, 0.999, 0.999, 0.999);

		//Amarelo
		scale(cubo.amarelo.a, 0.999, 0.999, 0.999);
		scale(cubo.amarelo.b, 0.999, 0.999, 0.999);
		scale(cubo.amarelo.c, 0.999, 0.999, 0.999);
		scale(cubo.amarelo.d, 0.999, 0.999, 0.999);

		//Azul
		scale(cubo.azul.a, 0.999, 0.999, 0.999);
		scale(cubo.azul.b, 0.999, 0.999, 0.999);
		scale(cubo.azul.c, 0.999, 0.999, 0.999);
		scale(cubo.azul.d, 0.999, 0.999, 0.999);

		//Magenta
		scale(cubo.magenta.a, 0.999, 0.999, 0.999);
		scale(cubo.magenta.b, 0.999, 0.999, 0.999);
		scale(cubo.magenta.c, 0.999, 0.999, 0.999);
		scale(cubo.magenta.d, 0.999, 0.999, 0.999);
	}

	if (maiorTamanho) {
		//Verde
		translation(cubo.verde.a, 0.001, 0.001, 0.001);
		translation(cubo.verde.b, 0.001, 0.001, 0.001);
		translation(cubo.verde.c, 0.001, 0.001, 0.001);
		translation(cubo.verde.d, 0.001, 0.001, 0.001);

		//Laranja
		translation(cubo.laranja.a, 0.001, 0.001, 0.001);
		translation(cubo.laranja.b, 0.001, 0.001, 0.001);
		translation(cubo.laranja.c, 0.001, 0.001, 0.001);
		translation(cubo.laranja.d, 0.001, 0.001, 0.001);

		//VeRmelho
		translation(cubo.vermelho.a, 0.001, 0.001, 0.001);
		translation(cubo.vermelho.b, 0.001, 0.001, 0.001);
		translation(cubo.vermelho.c, 0.001, 0.001, 0.001);
		translation(cubo.vermelho.d, 0.001, 0.001, 0.001);

		//Amarelo
		translation(cubo.amarelo.a, 0.001, 0.001, 0.001);
		translation(cubo.amarelo.b, 0.001, 0.001, 0.001);
		translation(cubo.amarelo.c, 0.001, 0.001, 0.001);
		translation(cubo.amarelo.d, 0.001, 0.001, 0.001);

		//Azul
		translation(cubo.azul.a, 0.001, 0.001, 0.001);
		translation(cubo.azul.b, 0.001, 0.001, 0.001);
		translation(cubo.azul.c, 0.001, 0.001, 0.001);
		translation(cubo.azul.d, 0.001, 0.001, 0.001);

		//Magenta
		translation(cubo.magenta.a, 0.001, 0.001, 0.001);
		translation(cubo.magenta.b, 0.001, 0.001, 0.001);
		translation(cubo.magenta.c, 0.001, 0.001, 0.001);
		translation(cubo.magenta.d, 0.001, 0.001, 0.001);

	}

	if (menorTamanho) {
		//Verde
		translation(cubo.verde.a, -0.001, -0.001, -0.001);
		translation(cubo.verde.b, -0.001, -0.001, -0.001);
		translation(cubo.verde.c, -0.001, -0.001, -0.001);
		translation(cubo.verde.d, -0.001, -0.001, -0.001);

		//Laranja
		translation(cubo.laranja.a, -0.001, -0.001, -0.001);
		translation(cubo.laranja.b, -0.001, -0.001, -0.001);
		translation(cubo.laranja.c, -0.001, -0.001, -0.001);
		translation(cubo.laranja.d, -0.001, -0.001, -0.001);

		//VeRmelho
		translation(cubo.vermelho.a, -0.001, -0.001, -0.001);
		translation(cubo.vermelho.b, -0.001, -0.001, -0.001);
		translation(cubo.vermelho.c, -0.001, -0.001, -0.001);
		translation(cubo.vermelho.d, -0.001, -0.001, -0.001);

		//Amarelo
		translation(cubo.amarelo.a, -0.001, -0.001, -0.001);
		translation(cubo.amarelo.b, -0.001, -0.001, -0.001);
		translation(cubo.amarelo.c, -0.001, -0.001, -0.001);
		translation(cubo.amarelo.d, -0.001, -0.001, -0.001);

		//Azul
		translation(cubo.azul.a, -0.001, -0.001, -0.001);
		translation(cubo.azul.b, -0.001, -0.001, -0.001);
		translation(cubo.azul.c, -0.001, -0.001, -0.001);
		translation(cubo.azul.d, -0.001, -0.001, -0.001);

		//Magenta
		translation(cubo.magenta.a, -0.001, -0.001, -0.001);
		translation(cubo.magenta.b, -0.001, -0.001, -0.001);
		translation(cubo.magenta.c, -0.001, -0.001, -0.001);
		translation(cubo.magenta.d, -0.001, -0.001, -0.001);
	}

	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); //Define a posição da camera

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//COMANDO ATIVAR WIREFRAME

	glBegin(GL_QUADS);                // Começa a desenhar o cubo
	   // Face de cima (y = 1.0f)
	   // Define os vértice em ordem anti-horário com a face apontando para cima
	glColor3f(0.0f, 1.0f, 0.0f);     // Verde
	glVertex3f(cubo.verde.a.x, cubo.verde.a.y, cubo.verde.a.z);
	glVertex3f(cubo.verde.b.x, cubo.verde.b.y, cubo.verde.b.z);
	glVertex3f(cubo.verde.c.x, cubo.verde.c.y, cubo.verde.c.z);
	glVertex3f(cubo.verde.d.x, cubo.verde.d.y, cubo.verde.d.z);
	//glVertex3f(cubo.verde.a.x, cubo.verde.a.y, cubo.verde.a.z);

	// Face de cima (y = -1.0f)
	glColor3f(1.0f, 0.5f, 0.0f);     // Laranja
	glVertex3f(cubo.laranja.a.x, cubo.laranja.a.y, cubo.laranja.a.z);
	glVertex3f(cubo.laranja.b.x, cubo.laranja.b.y, cubo.laranja.b.z);
	glVertex3f(cubo.laranja.c.x, cubo.laranja.c.y, cubo.laranja.c.z);
	glVertex3f(cubo.laranja.d.x, cubo.laranja.d.y, cubo.laranja.d.z);

	// Face frontal  (z = 1.0f)
	glColor3f(1.0f, 0.0f, 0.0f);     // Vermelho
	glVertex3f(cubo.vermelho.a.x, cubo.vermelho.a.y, cubo.vermelho.a.z);
	glVertex3f(cubo.vermelho.b.x, cubo.vermelho.b.y, cubo.vermelho.b.z);
	glVertex3f(cubo.vermelho.c.x, cubo.vermelho.c.y, cubo.vermelho.c.z);
	glVertex3f(cubo.vermelho.d.x, cubo.vermelho.d.y, cubo.vermelho.d.z);

	// Face direita (x = 1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);     // Amarelo
	glVertex3f(cubo.amarelo.a.x, cubo.amarelo.a.y, cubo.amarelo.a.z);
	glVertex3f(cubo.amarelo.b.x, cubo.amarelo.b.y, cubo.amarelo.b.z);
	glVertex3f(cubo.amarelo.c.x, cubo.amarelo.c.y, cubo.amarelo.c.z);
	glVertex3f(cubo.amarelo.d.x, cubo.amarelo.d.y, cubo.amarelo.d.z);

	// Face traseira (z = -1.0f)
	glColor3f(0.0f, 0.0f, 1.0f);     //Azul
	glVertex3f(cubo.azul.a.x, cubo.azul.a.y, cubo.azul.a.z);
	glVertex3f(cubo.azul.b.x, cubo.azul.b.y, cubo.azul.b.z);
	glVertex3f(cubo.azul.c.x, cubo.azul.c.y, cubo.azul.c.z);
	glVertex3f(cubo.azul.d.x, cubo.azul.d.y, cubo.azul.d.z);

	// Face esquerda (x = -1.0f)
	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(cubo.magenta.a.x, cubo.magenta.a.y, cubo.magenta.a.z);
	glVertex3f(cubo.magenta.b.x, cubo.magenta.b.y, cubo.magenta.b.z);
	glVertex3f(cubo.magenta.c.x, cubo.magenta.c.y, cubo.magenta.c.z);
	glVertex3f(cubo.magenta.d.x, cubo.magenta.d.y, cubo.magenta.d.z);

	/*cout << cubo.magenta.a.x << ' ' << cubo.magenta.a.y << ' ' << cubo.magenta.a.z << endl;
	cout << cubo.magenta.b.x << ' ' << cubo.magenta.b.y << ' ' << cubo.magenta.b.z << endl;
	cout << cubo.magenta.c.x << ' ' << cubo.magenta.c.y << ' ' << cubo.magenta.c.z << endl;
	cout << cubo.magenta.d.x << ' ' << cubo.magenta.d.y << ' ' << cubo.magenta.d.z << endl;
	*/

	/*glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);*/




	glEnd();

	glutSwapBuffers();  // Double Buffer, troca o atual pelo que está aguardando
}


//Função de redesenhou prioriza o aspecto da projeção
void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void releasedSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: //Seta pra cima
		//Variavel que representa a tecla--
		up = false;
		break;
	case GLUT_KEY_DOWN: //Seta pra baixo
		down = false;
		break;
	case GLUT_KEY_LEFT: //Seta pra esquerda
		bleft = false;
		break;
	case GLUT_KEY_RIGHT: //Seta pra direita
		bright = false;
		break;
	}
}

void pressedSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP: //Seta pra cima
		//Variavel que representa a tecla++
		up = true;
		break;
	case GLUT_KEY_DOWN: //Seta pra baixo
		down = true;
		break;
	case GLUT_KEY_LEFT: //Seta pra esquerda
		bleft = true;
		break;
	case GLUT_KEY_RIGHT: //Seta pra direita
		bright = true;
		break;
	}
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27: //Esc
		exit(0);
		break;
	case 119: //w
		//Variavel que representa a tecla = 1
		up = true;
		break;
	case 115: //s
		down = true;
		break;
	case 97: //a
		bleft = true;
		break;
	case 100: //w
		bright = true;
		break;
	case 45: //menos
		menos = true;
		break;
	case 43: //mais
		more = true;
		break;
	case 61: //igual (mais)
		more = true;
		break;
	case 48: //tecla zero = reset
		reset = true;
		break;
	case 60: //menor que
		menorTamanho = true;
		break;
	case 44: //menor que (vírgula)
		menorTamanho = true;
		break;
	case 101: //menor que (letra e)
		menorTamanho = true;
		break;
	case 62: //maior que
		maiorTamanho = true;
		break;
	case 46: //maior que (ponto)
		maiorTamanho = true;
		break;
	case 114: //maior que (letra r)
		maiorTamanho = true;
		break;
	}
}

void keyboardOnRelease(unsigned char key, int x, int y) {
	switch (key) {
	case 119: //w
		//Variavel que representa a tecla = 0
		up = false;
		break;
	case 115: //s
		down = false;
		break;
	case 97: //a
		bleft = false;
		break;
	case 100: //w
		bright = false;
		break;
	case 45: //menos
		menos = false;
		break;
	case 43: //mais
		more = false;
		break;
	case 61: //igual
		more = false;
		break;
	case 48: //tecla zero = reset
		reset = false;
		break;
	case 60: //menor que
		menorTamanho = false;
		break;
	case 44: //menor que (vírgula)
		menorTamanho = false;
		break;
	case 101: //menor que (letra e)
		menorTamanho = false;
		break;
	case 62: //maior que
		maiorTamanho = false;
		break;
	case 46: //maior que (ponto)
		maiorTamanho = false;
		break;
	case 114: //maior que (letra r)
		maiorTamanho = false;
		break;
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("CUbo - Natan N. Martins");
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);

	//Entrada
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardOnRelease);
	glutSpecialFunc(pressedSpecialKeys);
	glutSpecialUpFunc(releasedSpecialKeys);

	glutReshapeFunc(reshape);
	glutIdleFunc(display);

	glutMainLoop();
	return 0;
}