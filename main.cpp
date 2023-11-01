#include <opencv2/opencv.hpp>

#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

int main() {
  std::string configFilePath = "../config.txt";
  std::ifstream configFile(configFilePath);

  if (!configFile.is_open()) {
    std::cout << "无法打开配置文件: " << configFilePath << std::endl;
    return -1;
  }

  std::string inputVideoPath;
  std::string outputImagePath;
  std::string line;
  while (std::getline(configFile, line)) {
    size_t delimiterPos = line.find("=");
    if (delimiterPos != std::string::npos) {
      std::string key = line.substr(0, delimiterPos);
      std::string value = line.substr(delimiterPos + 1);
      std::cout << std::endl << key << "1" << std::endl;
      std::cout << std::endl << value << std::endl;
      if (key == "input_video")
        inputVideoPath = value;
      else if (key == "output_image")
        outputImagePath = value;
    }
  }
  std::cerr << std::endl << inputVideoPath << std::endl;
  configFile.close();
  cv::VideoCapture cap(inputVideoPath); // 打开视频文件

  if (!cap.isOpened()) {
    std::cout << "无法打开视频文件" << std::endl;
    return -1;
  }

  int frameCount = 0; // 帧计数器
  int interval = 10;  // 每隔10帧截图一次

  cv::Mat frame;
  while (cap.read(frame)) {
    if (frameCount % interval == 0) {
      std::string filename =
          outputImagePath + "/" + std::to_string(frameCount) + ".jpg";
      cv::imwrite(filename, frame); // 保存帧图像
    }

    frameCount++;
  }

  cap.release(); // 释放视频文件
  return 0;
}