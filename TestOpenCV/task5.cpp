/*

#include<opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

#define IMAGE_SIZE 801

const int density = IMAGE_SIZE / 4;

int OriginX, OriginY;
RNG g_rng(12345);
bool Enlarging = false;
Point A = Point(0, 0);
Point B = Point(0, 0);


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

void Tintage(Mat img, int X0, int Y0)
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

void on_mouse(int EVENT, int x, int y, int flags, void* userdata);

int main()
{
	Mat img(IMAGE_SIZE, IMAGE_SIZE, CV_8UC3);

	OriginX = OriginY = IMAGE_SIZE / 2;

	Tintage(img, OriginX, OriginY);

	namedWindow("mandelbrot");

	setMouseCallback("mandelbrot", on_mouse, &img);

	imshow("mandelbrot", img);

	printf("按Esc键退出\n");

	int k = waitKey();
	while (k != 27)k = waitKey();
	return 0;
}



void on_mouse(int event, int x, int y, int flags, void *ustc)
//event鼠标事件代号，x,y鼠标坐标，flags拖拽和键盘操作的代号    
{
	Mat& img = *(Mat*) ustc;
	switch (event) 
	{
		case EVENT_LBUTTONDOWN://按下左键
		{
			destroyWindow("放大窗口");
			A = Point(x, y);
			printf("x=%d y=%d\n", x, y);
		}	
		break;

		case EVENT_MOUSEMOVE: //移动鼠标
		{
			//printf("x=%d y=%d\n", x, y);
		}
		break;

		case EVENT_LBUTTONUP:
		{
			B = Point(x, y);

			
			if (A==B)
			{
				if (Enlarging)
				{
					Tintage(img, OriginX, OriginY);
					imshow("mandelbrot", img);
					destroyWindow("放大窗口");
					Enlarging = false;
				}
				else 
				{
					OriginX = A.y;
					OriginY = A.x;
					Tintage(img, A.y, A.x);
					imshow("mandelbrot", img);
				}
				
			}
			

			else
			{
				printf("x=%d y=%d\n", x, y);

				int m = A.x, n = A.y;

				A = Point(min(m, x), min(n, y));
				B = Point(max(m, x), max(n, y));

				int i, j;
				for (i = A.x; i <= B.x; i++)
				{
					img.at<Vec3b>(A.y ,i) = Vec3b(255, 0, 0);
					img.at<Vec3b>(B.y, i) = Vec3b(255, 0, 0);
				}
				for (i = A.y; i <= B.y; i++)
				{
					img.at<Vec3b>(i, A.x) = Vec3b(255, 0, 0);
					img.at<Vec3b>(i, B.x) = Vec3b(255, 0, 0);
				}


				imshow("mandelbrot", img);

				int col= (B.y - A.y) * 20 , row= (B.x - A.x) * 20;

				Mat Large_image(col, row, CV_8UC3);

				double Lx = (double)(A.x - OriginY) / density;
				double Ly = (double)(OriginX - A.y) / density;

				printf("Lx=%lf Ly=%lf\n", Lx, Ly);

				double xx, yy;
				for (i = 0; i < col; i++)
				{
					yy = Ly - (double)i / (density * 20);
					
					for (j = 0; j < row; j++)
					{
						xx = Lx + (double)j / (density * 20);
						if (mSetTest(xx, yy) == 0)
						{
							Large_image.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
						}
						else Large_image.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
					}
				}
				namedWindow("放大窗口");
				imshow("放大窗口", Large_image);
				Enlarging = true;
				
			}
		}
		break;
	}
}
*/


/*
void on_mouse(int event, int x, int y, int flags, void* userdata)
{
	Mat img;
	img = *(Mat*)userdata;

	// 这里以左上角为原点，向右为x轴，向下为y轴 （F**k!!!）

	switch (event)
	{
	case EVENT_RBUTTONDBLCLK:
		break;

	case EVENT_LBUTTONDOWN:
		Tintage(img, y, x);
		imshow("mandelbrot", img);
		break;

	case EVENT_MOUSEMOVE:
		if ((flags & EVENT_FLAG_LBUTTON))
		{



		}
		break;


	}
}
*/









