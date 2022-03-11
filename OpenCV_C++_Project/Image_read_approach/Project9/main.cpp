#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv; 
using namespace std;

void Atapproach(Mat src)
{
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			/*Vec3b pixel = src.at<Vec3b>(i, j);
			int B = pixel.val[0];
			int G = pixel.val[1];
			int R = pixel.val[2];
			std::cout << B << "," << G << "," << R << std::endl;*/

			int pixelgray = src.at<uchar>(i, j);
			cout << pixelgray << endl; 
		}
	}
}

void pointerapproach(Mat src)
{
	for (int i = 0; i < src.rows; i++)
	{
		uchar* pixel_row = src.ptr<uchar>(i);
		for (int j = 0; j < src.cols; j++)
		{

			int B = pixel_row[j * 3 + 0];
			int G = pixel_row[j * 3 + 1];
			int R = pixel_row[j * 3 + 2];

			std::cout << B << "," << G << "," << R << std::endl;
		}
	}
}

void dataApproach(Mat src)
{
	uchar* pixel_data = src.data;

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			int B = pixel_data[i * src.cols * 3 + j * 3 + 0];
			int G = pixel_data[i * src.cols * 3 + j * 3 + 1];
			int R = pixel_data[i * src.cols * 3 + j * 3 + 2];

			if (i == 10 && j == 10)
				std::cout << B << "," << G << "," << R << std::endl;
		}
	}
}
int main()
{
	Mat src, temp;

	src = cv::imread("dog.jpg",1);
	cvtColor(src, temp, COLOR_BGR2GRAY);

	
	Atapproach(temp);
	
	

	imshow("src_img",src);
	imshow("temp_img",temp);


	


	waitKey(0);
	return 0; 
}