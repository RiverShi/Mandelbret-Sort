#include<opencv.hpp>
#include<iostream>
#include<stack>

using namespace std;
using namespace cv;

#define IMAGE_SIZE 501
const int density = IMAGE_SIZE / 4;

struct State
{
	double Lx;
	double Ly;
	double d;
	bool Enlarged;

	State(){}
	State(double x,double y,double p,bool Lar):Lx(x),Ly(y),d(p),Enlarged(Lar){}
	
};

const State Origin(-2, 2, 1 / (double)density,false);
State present;
bool is_LBD=false;
Mat img(IMAGE_SIZE, IMAGE_SIZE, CV_8UC3);
Point A = Point(0, 0);
Point B = Point(0, 0);

stack<State> Image_state;

void square_print();
void square_earse();
int mSetTest(double c_re, double c_im);
void Tintage(State ); //Ⱦɫ
void on_mouse(int EVENT, int x, int y, int flags, void* userdata);

int main()
{
	namedWindow("mandelbrot");
	setMouseCallback("mandelbrot", on_mouse, &img);

	printf("�� Esc���˳�\n");
	printf("�� A ������һ��\n");
	printf("��������������\n");

	int k;

	while(1)
	{ 
		present = Origin;
		while (!Image_state.empty())Image_state.pop();
		Image_state.push(Origin);
		Tintage(Origin);
		imshow("mandelbrot", img);
		while (1)
		{
			k = waitKey();
			if (k == 27 || k == -1)return 0;
			if (k == 65 || k == 97)
			{
				if (Image_state.size() > 1)
				{
					printf("������һ��\n");
					Image_state.pop();
					present = Image_state.top();
					Tintage(present);
					imshow("mandelbrot", img);
				}
				else printf("�޸��ϲ�\n");
			}
			else
			{
				printf("\n����\n");
				break;
			}
		}
	}
}

void Tintage(State info)
{
	int i, j;
	double x, y;
	for (i = 0; i < IMAGE_SIZE; i++)
	{
		y = info.Ly - (double)i * info.d;
		for (j = 0; j < IMAGE_SIZE; j++)
		{
			x = info.Lx + (double)j * info.d;

			if (mSetTest(x, y) == 0)
				img.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
			else
				img.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
		}
	}
}

void on_mouse(int event, int x, int y, int flags, void *ustc)
{
	Mat& img = *(Mat*)ustc;
	switch (event)
	{
		case EVENT_LBUTTONDOWN://�������
			A = B = Point(x, y);
			is_LBD = true;
			break;

		case EVENT_MOUSEMOVE: //�ƶ����
		{
			if (is_LBD) //������ڰ�ס״̬
			{
				square_earse();
				B = Point(x, y);
				square_print();
				imshow("mandelbrot", img);
			}
		}
		break;

		case EVENT_LBUTTONUP://�ͷ����
		{
			is_LBD = false;
			B = Point(x, y);

			if (A == B)
			{
				if (present.Enlarged)break;
				else
				{
					double Lx = -A.x / (double)density;
					double Ly = A.y / (double)density;

					printf("�ı�ԭ��\n");
					State new_state(Lx, Ly, Origin.d, false);
					Image_state.push(new_state);
					Tintage(new_state);
					present = new_state;
					imshow("mandelbrot", img);
				}
			}

			else if(B.x > A.x && B.y > A.y)
			{
				int len = min(B.y - A.y, B.x - A.x);
				double Lx = present.Lx + A.x * present.d;
				double Ly = present.Ly - A.y * present.d;

				printf("�ֲ��Ŵ�\n");
				State new_state(Lx, Ly, present.d * len / (IMAGE_SIZE - 1) ,true);
				Tintage(new_state);
				Image_state.push(new_state);
				present = new_state;
				imshow("mandelbrot", img);	
			}
		}
		break;
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

void square_print()
{
	int len = min(B.y - A.y, B.x - A.x);
	int i;
	for (i = 0; i <= len; i++)
	{
		if (A.y + i < IMAGE_SIZE)
		{
			img.at<Vec3b>(A.y + i, A.x) = Vec3b(0, 255, 0);
			if (A.x + len < IMAGE_SIZE)
				img.at<Vec3b>(A.y + i, A.x + len) = Vec3b(0, 255, 0);
		}

		if (A.x + i < IMAGE_SIZE)
		{
			img.at<Vec3b>(A.y, A.x + i) = Vec3b(0, 255, 0);
			if (A.y + len < IMAGE_SIZE)
				img.at<Vec3b>(A.y + len, A.x + i) = Vec3b(0, 255, 0);
		}
	}
}

void square_earse()
{
	int len = min(B.y - A.y, B.x - A.x);
	int i;
	
	double Lx = present.Lx + A.x * present.d;
	double Ly = present.Ly - A.y * present.d;
	double Rx = present.Lx + (A.x + len)*present.d;
	double Ry = present.Ly - (A.y + len)*present.d;

	for (i = 0; i <= len; i++)
	{
		if (A.y + i < IMAGE_SIZE)
		{
			if (mSetTest(Lx, Ly - i * present.d) == 0)
				img.at<Vec3b>(A.y + i, A.x) = Vec3b(0, 0, 0);
			else img.at<Vec3b>(A.y + i, A.x) = Vec3b(255, 255, 255);

			if (A.x + len < IMAGE_SIZE)
			{
				if (mSetTest(Rx, Ly - i * present.d) == 0)
					img.at<Vec3b>(A.y + i, A.x + len) = Vec3b(0, 0, 0);
				else img.at<Vec3b>(A.y + i, A.x + len) = Vec3b(255, 255, 255);
			}
		}

		if (A.x + i < IMAGE_SIZE)
		{
			if (mSetTest(Lx + i * present.d, Ly) == 0)
				img.at<Vec3b>(A.y, A.x + i) = Vec3b(0, 0, 0);
			else img.at<Vec3b>(A.y, A.x + i) = Vec3b(255, 255, 255);

			if (A.y + len < IMAGE_SIZE)
			{
				if (mSetTest(Lx + i * present.d, Ry) == 0)
					img.at<Vec3b>(A.y + len, A.x + i) = Vec3b(0, 0, 0);
				else img.at<Vec3b>(A.y + len, A.x + i) = Vec3b(255, 255, 255);
			}
		}
	}
}



