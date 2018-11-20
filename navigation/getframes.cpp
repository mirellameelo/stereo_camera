#include "opencv2/opencv.hpp"
#include <iostream>


#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

using namespace cv;
using namespace std;

int main(int, char**)
{
	bool stop = false;
	VideoCapture cap_1(0);
	VideoCapture cap_2(1);
	Mat right_image, left_image;

	if (!cap_1.isOpened() || !cap_2.isOpened())
		return -1;
	int i = 0;
	std::vector<Mat> right_frame_data_list, left_frame_data_list;

	while (!stop) {
		cap_1 >> left_image;
		cap_2 >> right_image;
		right_frame_data_list.push_back(right_image.clone());
		left_frame_data_list.push_back(left_image.clone());
		imshow("right", right_image);
		imshow("left", left_image);
		char key = cv::waitKey(1);
		if (key == 's') {
			stop = true;
		}
	}
	for (int j = 0; j < right_frame_data_list.size(); j++) {
		stringstream ss;
		ss << j;
		string str = "right/" + ss.str() + ".jpg";
		imwrite(str, right_frame_data_list[j]);
	}
	for (int j = 0; j < left_frame_data_list.size(); j++) {
		stringstream ss;
		ss << j;
		string str = "left/" + ss.str() + ".jpg";
		imwrite(str, left_frame_data_list[j]);
	}
}