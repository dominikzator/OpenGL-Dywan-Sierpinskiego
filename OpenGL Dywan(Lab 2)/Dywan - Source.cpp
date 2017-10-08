#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <vector>
#include <time.h>

typedef GLdouble point2[2];
using namespace std;
/*************************************************************************************/

static double side = 190;
static int number_of_moves = 6;
static bool draw_colors = true;
static int red_color = 0;
static int green_color = 1;
static int blue_color = 0;

// Funkcja okreslajaca, co ma byc rysowane
// (zawsze wywolywana, gdy trzeba przerysowac scene)

void draw_random_color(double x1, double y1, double x2, double y2)
{
	//funkcja rysujaca kwadraty z losowymi kolorami
		double red_random;
		double green_random;
		double blue_random;

		red_random = rand() % 10;
		green_random = rand() % 10;
		blue_random = rand() % 10;

		glColor3f(red_random/10*red_color, green_random/10*green_color, blue_random / 10*blue_color);

		glRectf(x1, y1, x2, y2);
}

vector <double> remove_center(vector <double> &points_in);
vector <double> remove_center(double &first_x, double &first_y, double &second_x, double &second_y);

vector <double> divide(vector <double> &points_in)
{
	//funkcja dzielaca kwadrat na 9 czesci, zwracajaca ich wierzcholki
	double side_length;
	srand(time(NULL));
	if (points_in.at(0) > 0 || points_in.at(2) > 0)
	{
		side_length = abs(points_in.at(0) - points_in.at(2));
	}
	vector <double> points_out;
	
	//Rysowanie 1 kwadratu
	points_out.push_back(points_in.at(0));
	points_out.push_back(points_in.at(1) + 2* side_length / 3);
	points_out.push_back(points_in.at(2)-2* side_length /3);
	points_out.push_back(points_in.at(3));
	//divide(points_out);
	

	//Rysowanie 2 kwadratu
	points_out.push_back(points_in.at(0)+ side_length /3);
	points_out.push_back(points_in.at(1) + 2 * side_length / 3);
	points_out.push_back(points_in.at(2) - side_length / 3);
	points_out.push_back(points_in.at(3));

	//Rysowanie 3 kwadratu
	points_out.push_back(points_in.at(0) + 2* side_length / 3);
	points_out.push_back(points_in.at(1) + 2 * side_length / 3);
	points_out.push_back(points_in.at(2));
	points_out.push_back(points_in.at(3));

	//Rysowanie 4 kwadratu
	points_out.push_back(points_in.at(0));
	points_out.push_back(points_in.at(1) + side_length / 3);
	points_out.push_back(points_in.at(2)-2* side_length /3);
	points_out.push_back(points_in.at(3)- side_length /3);

	//Rysowanie 5 kwadratu
	points_out.push_back(points_in.at(0)+ side_length /3);
	points_out.push_back(points_in.at(1) + side_length / 3);
	points_out.push_back(points_in.at(2) - side_length / 3);
	points_out.push_back(points_in.at(3) - side_length / 3);

	//Rysowanie 6 kwadratu
	points_out.push_back(points_in.at(0)+2* side_length /3);
	points_out.push_back(points_in.at(1) + side_length / 3);
	points_out.push_back(points_in.at(2));
	points_out.push_back(points_in.at(3) - side_length / 3);

	//Rysowanie 7 kwadratu
	points_out.push_back(points_in.at(0));
	points_out.push_back(points_in.at(1));
	points_out.push_back(points_in.at(2)-2* side_length /3);
	points_out.push_back(points_in.at(3) -2* side_length / 3);

	//Rysowanie 8 kwadratu
	points_out.push_back(points_in.at(0)+ side_length /3);
	points_out.push_back(points_in.at(1));
	points_out.push_back(points_in.at(2) - side_length / 3);
	points_out.push_back(points_in.at(3) - 2 * side_length / 3);

	//Rysowanie 9 kwadratu
	points_out.push_back(points_in.at(0)+2* side_length /3);
	points_out.push_back(points_in.at(1));
	points_out.push_back(points_in.at(2));
	points_out.push_back(points_in.at(3) - 2 * side_length / 3);

	
	if (draw_colors)
	{
		for (int i = 0; 4 * i + 3 < points_out.size(); i++)
		{
			if (i != 4)
			{
				draw_random_color(points_out.at(4 * i), points_out.at(4 * i + 1), points_out.at(4 * i + 2), points_out.at(4 * i + 3));
			}
		}
	}

	
	
	{
		glColor3f(0.5f, 0.5f, 0.5f);
		
		for (int i = 0; i < 9; i++)
		{
			if (i != 4)
			{
				remove_center(points_out.at(4 * i), points_out.at(4 * i + 1), points_out.at(4 * i + 2), points_out.at(4 * i + 3));
			}
		}
		
	}
	
	
	

	glFlush();
	return points_out;

}

vector <double> divide(double &first_x,double &first_y, double &second_x, double &second_y)
{
	double side_length = abs(first_x - second_x);
	vector <double> points_out2;
	
	//Rysowanie 1 kwadratu
	points_out2.push_back(first_x);
	points_out2.push_back(first_y + 2 * side_length / 3);
	points_out2.push_back(second_x - 2 * side_length / 3);
	points_out2.push_back(second_y);

	//Rysowanie 2 kwadratu
	points_out2.push_back(first_x + side_length / 3);
	points_out2.push_back(first_y + 2 * side_length / 3);
	points_out2.push_back(second_x - side_length / 3);
	points_out2.push_back(second_y);

	//Rysowanie 3 kwadratu
	points_out2.push_back(first_x + 2 * side_length / 3);
	points_out2.push_back(first_y + 2 * side_length / 3);
	points_out2.push_back(second_x);
	points_out2.push_back(second_y);

	//Rysowanie 4 kwadratu
	points_out2.push_back(first_x);
	points_out2.push_back(first_y + side_length / 3);
	points_out2.push_back(second_x - 2 * side_length / 3);
	points_out2.push_back(second_y - side_length / 3);

	//Rysowanie 5 kwadratu
	points_out2.push_back(first_x + side_length / 3);
	points_out2.push_back(first_y + side_length / 3);
	points_out2.push_back(second_x - side_length / 3);
	points_out2.push_back(second_y - side_length / 3);

	//Rysowanie 6 kwadratu
	points_out2.push_back(first_x + 2 * side_length / 3);
	points_out2.push_back(first_y + side_length / 3);
	points_out2.push_back(second_x);
	points_out2.push_back(second_y - side_length / 3);

	//Rysowanie 7 kwadratu
	points_out2.push_back(first_x);
	points_out2.push_back(first_y);
	points_out2.push_back(second_x - 2 * side_length / 3);
	points_out2.push_back(second_y - 2 * side_length / 3);

	//Rysowanie 8 kwadratu
	points_out2.push_back(first_x + side_length / 3);
	points_out2.push_back(first_y);
	points_out2.push_back(second_x - side_length / 3);
	points_out2.push_back(second_y - 2 * side_length / 3);

	//Rysowanie 9 kwadratu
	points_out2.push_back(first_x + 2 * side_length / 3);
	points_out2.push_back(first_y);
	points_out2.push_back(second_x);
	points_out2.push_back(second_y - 2 * side_length / 3);

	
	if (draw_colors)
	{
		for (int i = 0; 4 * i + 3 < points_out2.size(); i++)
		{
			if (i != 4)
			{
				draw_random_color(points_out2.at(4 * i), points_out2.at(4 * i + 1), points_out2.at(4 * i + 2), points_out2.at(4 * i + 3));
			}

		}
	}


	{
		glColor3f(0.5f, 0.5f, 0.5f);
		for (int i = 0; i < 9; i++)
		{
			if (i != 4)
			{
				remove_center(points_out2.at(4 * i), points_out2.at(4 * i + 1), points_out2.at(4 * i + 2), points_out2.at(4 * i + 3));

			}
		}
	}
	

	glFlush();
	return points_out2;

}

vector <double> remove_center(vector <double> &points_in)
{
	//algorytm usuwania srodka dla danego kwadratu
	double function_side = abs(points_in.at(0) - points_in.at(2));
	glColor3f(0.5f, 0.5f, 0.5f);
	glRectd(points_in.at(0)+function_side/3, points_in.at(1) + function_side / 3, points_in.at(0) + 2*function_side / 3, points_in.at(1) + 2*function_side / 3);
	double side_length;
	//srand(time(NULL));
	if (points_in.at(0) > 0 || points_in.at(2) > 0)
	{
		side_length = abs(points_in.at(0) - points_in.at(2));
	}
	vector <double> points_out;

	//Rysowanie 1 kwadratu
	points_out.push_back(points_in.at(0));
	points_out.push_back(points_in.at(1) + 2 * side_length / 3);
	points_out.push_back(points_in.at(2) - 2 * side_length / 3);
	points_out.push_back(points_in.at(3));

	//Rysowanie 2 kwadratu
	points_out.push_back(points_in.at(0) + side_length / 3);
	points_out.push_back(points_in.at(1) + 2 * side_length / 3);
	points_out.push_back(points_in.at(2) - side_length / 3);
	points_out.push_back(points_in.at(3));

	//Rysowanie 3 kwadratu
	points_out.push_back(points_in.at(0) + 2 * side_length / 3);
	points_out.push_back(points_in.at(1) + 2 * side_length / 3);
	points_out.push_back(points_in.at(2));
	points_out.push_back(points_in.at(3));

	//Rysowanie 4 kwadratu
	points_out.push_back(points_in.at(0));
	points_out.push_back(points_in.at(1) + side_length / 3);
	points_out.push_back(points_in.at(2) - 2 * side_length / 3);
	points_out.push_back(points_in.at(3) - side_length / 3);

	//Rysowanie 5 kwadratu
	points_out.push_back(points_in.at(0) + side_length / 3);
	points_out.push_back(points_in.at(1) + side_length / 3);
	points_out.push_back(points_in.at(2) - side_length / 3);
	points_out.push_back(points_in.at(3) - side_length / 3);

	//Rysowanie 6 kwadratu
	points_out.push_back(points_in.at(0) + 2 * side_length / 3);
	points_out.push_back(points_in.at(1) + side_length / 3);
	points_out.push_back(points_in.at(2));
	points_out.push_back(points_in.at(3) - side_length / 3);

	//Rysowanie 7 kwadratu
	points_out.push_back(points_in.at(0));
	points_out.push_back(points_in.at(1));
	points_out.push_back(points_in.at(2) - 2 * side_length / 3);
	points_out.push_back(points_in.at(3) - 2 * side_length / 3);

	//Rysowanie 8 kwadratu
	points_out.push_back(points_in.at(0) + side_length / 3);
	points_out.push_back(points_in.at(1));
	points_out.push_back(points_in.at(2) - side_length / 3);
	points_out.push_back(points_in.at(3) - 2 * side_length / 3);

	//Rysowanie 9 kwadratu
	points_out.push_back(points_in.at(0) + 2 * side_length / 3);
	points_out.push_back(points_in.at(1));
	points_out.push_back(points_in.at(2));
	points_out.push_back(points_in.at(3) - 2 * side_length / 3);

	return points_out;
}

vector <double> remove_center(double &first_x, double &first_y,double &second_x, double &second_y)
{
	double function_side = abs(first_x - second_x);
	glColor3f(0.5f, 0.5f, 0.5f);
	glRectd(first_x + function_side / 3, first_y + function_side / 3, first_x + 2 * function_side / 3, first_y + 2 * function_side / 3);
	double side_length = abs(first_x - second_x);
	vector <double> points_out2;

	//Rysowanie 1 kwadratu
	points_out2.push_back(first_x);
	points_out2.push_back(first_y + 2 * side_length / 3);
	points_out2.push_back(second_x - 2 * side_length / 3);
	points_out2.push_back(second_y);

	//draw_random_color(points_out2.at(0), points_out2.at(1), points_out2.at(2), points_out2.at(3));

	//Rysowanie 2 kwadratu
	points_out2.push_back(first_x + side_length / 3);
	points_out2.push_back(first_y + 2 * side_length / 3);
	points_out2.push_back(second_x - side_length / 3);
	points_out2.push_back(second_y);
	//draw_random_color(points_out2.at(4), points_out2.at(5), points_out2.at(6), points_out2.at(7));

	//Rysowanie 3 kwadratu
	points_out2.push_back(first_x + 2 * side_length / 3);
	points_out2.push_back(first_y + 2 * side_length / 3);
	points_out2.push_back(second_x);
	points_out2.push_back(second_y);
	//draw_random_color(points_out2.at(8), points_out2.at(9), points_out2.at(10), points_out2.at(11));

	//Rysowanie 4 kwadratu
	points_out2.push_back(first_x);
	points_out2.push_back(first_y + side_length / 3);
	points_out2.push_back(second_x - 2 * side_length / 3);
	points_out2.push_back(second_y - side_length / 3);

	//Rysowanie 5 kwadratu
	points_out2.push_back(first_x + side_length / 3);
	points_out2.push_back(first_y + side_length / 3);
	points_out2.push_back(second_x - side_length / 3);
	points_out2.push_back(second_y - side_length / 3);

	//Rysowanie 6 kwadratu
	points_out2.push_back(first_x + 2 * side_length / 3);
	points_out2.push_back(first_y + side_length / 3);
	points_out2.push_back(second_x);
	points_out2.push_back(second_y - side_length / 3);

	//Rysowanie 7 kwadratu
	points_out2.push_back(first_x);
	points_out2.push_back(first_y);
	points_out2.push_back(second_x - 2 * side_length / 3);
	points_out2.push_back(second_y - 2 * side_length / 3);

	//Rysowanie 8 kwadratu
	points_out2.push_back(first_x + side_length / 3);
	points_out2.push_back(first_y);
	points_out2.push_back(second_x - side_length / 3);
	points_out2.push_back(second_y - 2 * side_length / 3);

	//Rysowanie 9 kwadratu
	points_out2.push_back(first_x + 2 * side_length / 3);
	points_out2.push_back(first_y);
	points_out2.push_back(second_x);
	points_out2.push_back(second_y - 2 * side_length / 3);

	return points_out2;
}


void RenderScene(void)

{
	vector <double> my_points;
	glClear(GL_COLOR_BUFFER_BIT);
	// Czyszczenie okna aktualnym kolorem czyszczacym
	int color_counter;
	

	glColor3f(1.0f, 1.0f, 1.0f);
	// Ustawienie aktualnego koloru rysowania na zielony

	// Narysowanie prostokata

	vector <double> first_points;
	vector <double> help_vector;
	vector <double> help_vector2;
	vector <double> help_vector3;
	vector <double> help_vector4;
	vector <double> help_vector5;
	vector <double> help2_vector;
	vector <double> help2_vector2;
	vector <double> help2_vector3;
	vector <double> help2_vector4;
	vector <double> help2_vector5;

	
	if (number_of_moves>= 0)
	{
		first_points.push_back(-side / 2);
		first_points.push_back(-side / 2);
		first_points.push_back(side / 2);
		first_points.push_back(side / 2);
		if (draw_colors)
		{
			draw_random_color(first_points.at(0), first_points.at(1), first_points.at(2), first_points.at(3));
		}
		glRectd(first_points.at(0), first_points.at(1), first_points.at(2), first_points.at(3));
	}
	
	if (number_of_moves >= 1)
	{
		if (draw_colors)
		{
			draw_random_color(first_points.at(0), first_points.at(1), first_points.at(2), first_points.at(3));
		}

		remove_center(first_points);
	}

	if (number_of_moves >= 2)
	{
		if (draw_colors)
		{
			draw_random_color(first_points.at(0), first_points.at(1), first_points.at(2), first_points.at(3));
		}
		help_vector = divide(first_points);

		if (number_of_moves >= 3)
		{
			for (int i = 0; 4 * i + 3 < help_vector.size(); i++)
			{
				help_vector2 = divide(help_vector.at(4 * i), help_vector.at(4 * i + 1), help_vector.at(4 * i + 2), help_vector.at(4 * i + 3));
				
				if (number_of_moves >= 4)
				{
					for (int i = 0; 4 * i + 3 < help_vector2.size(); i++)
					{
						help_vector3 = divide(help_vector2.at(4 * i), help_vector2.at(4 * i + 1), help_vector2.at(4 * i + 2), help_vector2.at(4 * i + 3));
					
						if (number_of_moves >= 5)
						{
							for (int i = 0; 4 * i + 3 < help_vector3.size(); i++)
							{
								help_vector4 = divide(help_vector3.at(4 * i), help_vector3.at(4 * i + 1), help_vector3.at(4 * i + 2), help_vector3.at(4 * i + 3));

								if (number_of_moves >= 6)
								{
									for (int i = 0; 4 * i + 3 < help_vector4.size(); i++)
									{

										help_vector5=divide(help_vector4.at(4 * i), help_vector4.at(4 * i + 1), help_vector4.at(4 * i + 2), help_vector4.at(4 * i + 3));
									
										if (number_of_moves >= 7)
										{
											for (int i = 0; 4 * i + 3 < help_vector5.size(); i++)
											{

												divide(help_vector5.at(4 * i), help_vector5.at(4 * i + 1), help_vector5.at(4 * i + 2), help_vector5.at(4 * i + 3));
												
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		

	}


	//rysowanie dziur
	if (number_of_moves >= 1)
	{
		glColor3f(0.5f, 0.5f, 0.5f);
		remove_center(first_points);
	}

	if (number_of_moves >= 2)
	{
		help2_vector = remove_center(first_points);

		if (number_of_moves >= 3)
		{
			for (int i = 0; 4 * i + 3 < help2_vector.size(); i++)
			{

				help2_vector2 = remove_center(help2_vector.at(4 * i), help2_vector.at(4 * i + 1), help2_vector.at(4 * i + 2), help2_vector.at(4 * i + 3));
	
				if (number_of_moves >= 4)
				{
					for (int i = 0; 4 * i + 3 < help2_vector2.size(); i++)
					{
						help2_vector3 = remove_center(help2_vector2.at(4 * i), help2_vector2.at(4 * i + 1), help2_vector2.at(4 * i + 2), help2_vector2.at(4 * i + 3));
						if (number_of_moves >= 5)
						{
							for (int i = 0; 4 * i + 3 < help2_vector3.size(); i++)
							{
								//vector <double> help_vector2;
								help2_vector4 = remove_center(help2_vector3.at(4 * i), help2_vector3.at(4 * i + 1), help2_vector3.at(4 * i + 2), help2_vector3.at(4 * i + 3));

								if (number_of_moves >= 6)
								{
									for (int i = 0; 4 * i + 3 < help2_vector4.size(); i++)
									{

										help2_vector5 = remove_center(help2_vector4.at(4 * i), help2_vector4.at(4 * i + 1), help2_vector4.at(4 * i + 2), help2_vector4.at(4 * i + 3));

										if (number_of_moves >= 7)
										{
											for (int i = 0; 4 * i + 3 < help2_vector5.size(); i++)
											{

												remove_center(help2_vector5.at(4 * i), help2_vector5.at(4 * i + 1), help2_vector5.at(4 * i + 2), help2_vector5.at(4 * i + 3));

											}
										}
									}
								}
							}
						}
					}
				}
			}
		}



	}







	
	//divide(divide(first_points));


	
	/*
	vector <double> help_vector2;
	help_vector2 = divide(help_vector.at(0), help_vector.at(1), help_vector.at(2), help_vector.at(3));
	
	divide(help_vector2.at(0), help_vector2.at(1), help_vector2.at(2), help_vector2.at(3));
	*/

	glFlush();
	// Przekazanie polecen rysujacych do wykonania

}



/*************************************************************************************/

// Funkcja ustalajaca stan renderowania



void MyInit(void)

{

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	// Kolor okna wnetrza okna - ustawiono na szary

}

/*************************************************************************************/

// Funkcja sluzaca do kontroli zachowania proporcji rysowanych obiektów
// niezaleznie od rozmiarów okna graficznego



void ChangeSize(GLsizei horizontal, GLsizei vertical)

// Parametry horizontal i vertical (szerokosc i wysokosc okna) sa
// przekazywane do funkcji za kazdym razem, gdy zmieni sie rozmiar okna

{

	GLfloat AspectRatio;

	// Deklaracja zmiennej AspectRatio okreslajacej proporcje wymiarów okna



	if (vertical == 0)
		// Zabezpieczenie pzred dzieleniem przez 0

		vertical = 1;

	glViewport(0, 0, horizontal, vertical);
	// Ustawienie wielkosciokna okna urzadzenia (Viewport)
	// W tym przypadku od (0,0) do (horizontal, vertical)

	glMatrixMode(GL_PROJECTION);
	// Okreslenie ukladu wspólrzednych obserwatora

	glLoadIdentity();
	// Okreslenie przestrzeni ograniczajacej

	AspectRatio = (GLfloat)horizontal / (GLfloat)vertical;
	// Wyznaczenie wspólczynnika proporcji okna

	// Gdy okno na ekranie nie jest kwadratem wymagane jest
	// okreslenie okna obserwatora.
	// Pozwala to zachowac wlasciwe proporcje rysowanego obiektu
	// Do okreslenia okna obserwatora sluzy funkcja glOrtho(...)



	if (horizontal <= vertical)

		glOrtho(-100.0, 100.0, -100.0 / AspectRatio, 100.0 / AspectRatio, 1.0, -1.0);

	else

		glOrtho(-100.0*AspectRatio, 100.0*AspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	// Okreslenie ukladu wspólrzednych     

	glLoadIdentity();

}

/*************************************************************************************/

// Glówny punkt wejscia programu. Program dziala w trybie konsoli



void main(void)

{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	// Ustawienie trybu wyswietlania
	// GLUT_SINGLE - pojedynczy bufor wyswietlania
	// GLUT_RGBA - model kolorów RGB



	glutCreateWindow("Dywan Sierpinskiego");
	// Utworzenie okna i okreslenie tresci napisu w naglówku okna

	glutDisplayFunc(RenderScene);
	// Okreslenie, ze funkcja RenderScene bedzie funkcja zwrotna (callback)
	// Biblioteka GLUT bedzie wywolywala ta funkcje za kazdym razem, gdy
	// trzeba bedzie przerysowac okno


	glutReshapeFunc(ChangeSize);
	// Dla aktualnego okna ustala funkcje zwrotna odpowiedzialna za
	// zmiany rozmiaru okna

	MyInit();
	// Funkcja MyInit (zdefiniowana powyzej) wykonuje wszelkie 
	// inicjalizacje konieczneprzed przystapieniem do renderowania


	glutMainLoop();
	// Funkcja uruchamia szkielet biblioteki GLUT

}