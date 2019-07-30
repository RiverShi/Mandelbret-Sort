/*
#include<opencv.hpp>
#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include <opencv2/core/core.hpp>
#include <opencv2/core/core_c.h>
#include <opencv2/core/mat.hpp>

#include <opencv2/imgproc/types_c.h>

using namespace std;
using namespace cv;

#define IMAGE_SIZE 801

const int density = IMAGE_SIZE /4 ;
const int X0 = IMAGE_SIZE / 2;
const int Y0 = IMAGE_SIZE / 2;


int mSetTest(double c_re, double c_im)
{
	double x = c_re, y = c_im;

	if(x>-0.5&&x<0.25&&y>-0.5&&y<0.5)return 0;

	int i;
	double temp;
	for (i = 1; i <= 200; i++)
	{
		if (x*x + y * y >= 4.0)return i;
		temp = x * x - y * y+c_re;
		y = 2 * x*y+c_im;
		x = temp;
	}
	return 0;
}

void change(IplImage *img,int X0, int Y0)
{
	CvScalar sca;
	int i, j;
	double x, y;

	// 像素点的起点（0,0）在左上角
	// (i,j)是第i行第j列的像素点

	for (i = 0; i < IMAGE_SIZE; i++)
	{
		y = double(X0-i) / density;
		for (j = 0; j < IMAGE_SIZE; j++)
		{
			x = double(j - Y0) / density;

			if (mSetTest(x, y) == 0)
			{
				sca.val[0] = 0; //blue 
				sca.val[1] = 0; //green 
				sca.val[2] = 0; //red 
				cvSet2D(img, i, j, sca);
			}
			else
			{

				sca.val[0] = 255; //blue 
				sca.val[1] = 255; //green 
				sca.val[2] = 255; //red 
				cvSet2D(img, i, j, sca);
			}
		}
	}
}
*/

/*
void test_set(IplImage *img)
{
	CvScalar sca;
	int i, j;
	for (i = 0; i <= 400; i++)
	{
		for (j = 0; j <= 200; j++)
		{
			sca.val[0] = 0; //blue 
			sca.val[1] = 0; //green 
			sca.val[2] = 0; //red 
			cvSet2D(img, i, j, sca);
		}
	}
}
*/

/*
int main()
{
	IplImage *pImg =
		cvCreateImage(cvSize(IMAGE_SIZE, IMAGE_SIZE), 8, 3);

	Mat img(IMAGE_SIZE, IMAGE_SIZE, CV_8UC3);
	//M = cvarrToMat(pImg);
	
	change(pImg, X0, Y0);
	//test_set(pImg);

	namedWindow("mandelbrot", 1);
	cvShowImage("mandelbrot", pImg);

	//cvSaveImage

	waitKey(0);

	//change(pImg, X0+100, Y0+100);
	//cvShowImage("mandelbrot", pImg);

	//waitKey(0);

	destroyWindow("mandelbrot");
	cvReleaseImage(&pImg);
}
*/

/*
int main(int argc, char **argv)
{
	IplImage *img = cvCreateImage(cvSize(IMAGE_SIZE, IMAGE_SIZE), 8, 3);
	CvScalar pixel;
	for (int i = 0; i < img->height; ++i)
	{
		for (int j = 0; j < img->width; ++j)
		{
			//获得像素的RGB值并显示, 注意内存中存储顺序是BGR
			pixel = cvGet2D(img, i, j);
			printf("B=%f,G=%f,R=%f/t\n", pixel.val[0], pixel.val[1], pixel.val[2]);
			//修改各点的值
			pixel.val[0] = 0;
			pixel.val[1] = 0;
			pixel.val[2] = 0;
			cvSet2D(img, i, j, pixel);
		}
	}
	cvNamedWindow("image", 1);
	cvShowImage("image", img);
	cvWaitKey(0);
	cvDestroyWindow("image");
	cvReleaseImage(&img);
	return 0;
}
*/


/*
int main()
{
	IplImage *pImg =
		cvCreateImage(cvSize(IMAGE_SIZE, IMAGE_SIZE), 8, 3);
	namedWindow("mandelbrot", 1);
	cvShowImage("mandelbrot", pImg);

	waitKey(0);

	destroyWindow("mandelbrot");
	cvReleaseImage(&pImg);
}

*/


/*
int main(int argc, char ** argv)
{
	Mat img = imread("C:/Users/River/Pictures/Camera Roll/TIM图片20190221103346.png");
	
	img = imread("C:/Users/River/source/repos/TestOpenCV/test.jpg");

	if (img.empty())
	{
		printf("Could not find this image!");
		system("pause");
		waitKey(0);
		return 0;

	}

	//namedWindow("test", CV_WINDOW_AUTOSIZE);
	imshow("test", img);
	waitKey(0);
	return 0;
}
*/








