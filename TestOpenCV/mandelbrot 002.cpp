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


int mSetTest(double c_re, double c_im);

void Tintage(Mat, int, int, int col = IMAGE_SIZE, int row = IMAGE_SIZE, int Multiple = 1);

void on_mouse(int EVENT, int x, int y, int flags, void* userdata);

int main()
{
	Mat img(IMAGE_SIZE, IMAGE_SIZE, CV_8UC3);

	OriginX = OriginY = IMAGE_SIZE / 2;

	Tintage(img, 0, 0);

	namedWindow("mandelbrot");

	setMouseCallback("mandelbrot", on_mouse, &img);

	imshow("mandelbrot", img);

	printf("按Esc键退出\n");

	int k = waitKey();
	while (k != 27)k = waitKey();
	return 0;
}


int mSetTest(double c_re, double c_im)
{
	double x = c_re, y = c_im;
	if (x > -0.5 && x<0.25 && y>-0.5 && y < 0.5)return 0;
	double temp;
	for (int i = 1; i <= 200; i++)
	{
		if (x*x + y * y >= 4.0)return i;
		temp = x * x - y * y + c_re;
		y = 2 * x*y + c_im;
		x = temp;
	}
	return 0;
}

void Tintage(Mat img, int Lx, int Ly, int col , int row, int Multiple)
{
	//Lx,Ly 左上角的像素坐标
	double x0 = (double)(Lx - OriginY) / density;
	double y0 = (double)(OriginX - Ly) / density;

	bool flag=false;
	if (Lx == 0 && Ly == 0 && col == row && col == IMAGE_SIZE && Multiple == 1)flag = true;

	double xx, yy;
	int i, j;
	for (i = 0; i < col; i++)
	{
		yy = y0 - (double)i / (density * Multiple);
		for (j = 0; j < row; j++)
		{
			xx = x0 + (double)j / (density * Multiple);
			if (mSetTest(xx, yy) == 0)
			{
				img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
			}
			else if(flag)img.at<Vec3b>(i, j) = Vec3b(255, 255, 255);

			if (flag)
			{
				//if(i==OriginX||j==OriginY)img.at<Vec3b>(i, j) = Vec3b(128, 128, 128);
			}
		}
	}
}

void on_mouse(int event, int x, int y, int flags, void *ustc) 
{
	Mat& img = *(Mat*)ustc;
	switch (event)
	{
		case EVENT_LBUTTONDOWN:
		{
			destroyWindow("放大窗口");
			A = Point(x, y);
		}
		break;

		case EVENT_LBUTTONUP:
		{
			B = Point(x, y);
			if (A == B)
			{
				if (Enlarging)
				{
					Tintage(img, 0, 0);
					imshow("mandelbrot", img);
					destroyWindow("放大窗口");
					Enlarging = false;
				}
				else
				{
					OriginX = A.y;
					OriginY = A.x;
					Tintage(img, 0, 0);
					imshow("mandelbrot", img);
				}
			}

			else
			{
				if (Enlarging)
				{
					Tintage(img, 0, 0);
					imshow("mandelbrot", img);
					destroyWindow("放大窗口");
				}

				int m = A.x, n = A.y;
				A = Point(min(m, x), min(n, y));
				B = Point(max(m, x), max(n, y));

				int i;
				for (i = A.x; i <= B.x; i++)
				{
					img.at<Vec3b>(A.y, i) = Vec3b(255, 0, 0);
					img.at<Vec3b>(B.y, i) = Vec3b(255, 0, 0);
				}
				for (i = A.y; i <= B.y; i++)
				{
					img.at<Vec3b>(i, A.x) = Vec3b(255, 0, 0);
					img.at<Vec3b>(i, B.x) = Vec3b(255, 0, 0);
				}

				imshow("mandelbrot", img);

				int col = (B.y - A.y) * 20, row = (B.x - A.x) * 20;
				Mat Large_image(col, row, CV_8UC3);

				Tintage(Large_image, A.x, A.y, col, row, 20);
				namedWindow("放大窗口");
				imshow("放大窗口", Large_image);
				Enlarging = true;
			}
		}
		break;
	}
}

*/






