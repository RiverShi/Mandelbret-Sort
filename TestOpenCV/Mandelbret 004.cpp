/*
#include<opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

#define IMAGE_SIZE 801

const int density = IMAGE_SIZE / 4;

int OriginX, OriginY;
bool Enlarging = false;
Point A = Point(0, 0);
Point B = Point(0, 0);
Mat img(IMAGE_SIZE, IMAGE_SIZE, CV_8UC3);

double Lx = -2, Ly = 2, Rx = 2, Ry = -2;
double d = 1 / (double)density;

//void square_print();
//void square_earse();
int mSetTest(double c_re, double c_im);
void Tintage(int X0, int Y0);
void Tintage();
void on_mouse(int EVENT, int x, int y, int flags, void* userdata);

void init()
{
	OriginX = OriginY = IMAGE_SIZE / 2;
	Tintage(OriginX, OriginY);
	Lx = -2, Ly = 2, Rx = 2, Ry = -2;
	d = 1 / (double)density;
	Enlarging = false;
}

int main()
{



	namedWindow("mandelbrot");
	setMouseCallback("mandelbrot", on_mouse, &img);

	printf("按Esc键退出\n");
	printf("任意其他键复原\n");
	while (1)
	{
		init();
		imshow("mandelbrot", img);
		int k = waitKey();
		if (k == 27)return 0;
	}
}



void Tintage()
{
	double length = Rx - Lx;
	int i, j;
	double x, y;

	for (i = 0; i < IMAGE_SIZE; i++)
	{
		y = Ly - (double)i * d;
		for (j = 0; j < IMAGE_SIZE; j++)
		{
			x = Lx + (double)j * d;

			if (mSetTest(x, y) == 0)
			{
				img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
			}
			else
			{
				img.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
			}
		}
	}
}

void on_mouse(int event, int x, int y, int flags, void *ustc)
//event鼠标事件代号，x,y鼠标坐标，flags拖拽和键盘操作的代号
{
	Mat& img = *(Mat*)ustc;
	switch (event)
	{
	case EVENT_LBUTTONDOWN://按下左键
	{
		A = Point(x, y);
	}
	break;

	case EVENT_MOUSEMOVE: //移动鼠标
	{
		//printf("x=%d y=%d\n", x, y);
	}
	break;

	case EVENT_LBUTTONUP://释放左键
	{
		B = Point(x, y);

		if (A == B)
		{
			if (Enlarging)break;
			else
			{
				OriginX = A.y;
				OriginY = A.x;
				Tintage(A.y, A.x);

				Lx = -A.x / (double)density;
				Ly = A.y / (double)density;
				Rx = Lx + 2.0;
				Ry = Ly - 2.0;

				imshow("mandelbrot", img);
			}
		}


		else
		{
			int m = A.x, n = A.y;

			A = Point(min(m, x), min(n, y));
			B = Point(max(m, x), n = max(n, y));

			int col = (B.y - A.y), row = (B.x - A.x);
			col = row = min(col, row);
			B = Point(A.x + col, A.y + row);

			Lx = Lx + A.x * d;
			Ly = Ly - A.y * d;

			Rx = Lx + B.x * d;
			Ry = Ly - B.y * d;

			d = d * col / (IMAGE_SIZE - 1);
			Enlarging = true;
			Tintage();
			imshow("mandelbrot", img);
		}
	}
	break;
	}
}

void Tintage(int X0, int Y0)
{
	int i, j;
	double x, y;

	// 像素点的起点（0,0）在左上角
	// (i,j)是第i行第j列的像素点

	for (i = 0; i < IMAGE_SIZE; i++)
	{
		y = double(X0 - i) / density;
		for (j = 0; j < IMAGE_SIZE; j++)
		{
			x = double(j - Y0) / density;

			if (mSetTest(x, y) == 0)
			{
				img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
			}
			else
			{
				img.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
			}

			//if (i == X0 || j == Y0)img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);

		}
	}
}

int mSetTest(double c_re, double c_im)
{
	double x = c_re, y = c_im;

	if (x > -0.5&&x<0.25&&y>-0.5&&y < 0.5)return 0;

	int i;
	double temp;
	for (i = 1; i <= 200; i++)
	{
		if (x*x + y * y >= 4.0)return i;
		temp = x * x - y * y + c_re;
		y = 2 * x*y + c_im;
		x = temp;
	}
	return 0;
}


*/

