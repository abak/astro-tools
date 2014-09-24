#include <processor.hpp>

#include <opencv2/highgui.hpp>

using namespace blender;

processor::processor(const std::string& high_res_path,
          const std::string& lo_res_path)
{
    high_res = cv::imread(high_res_path);
    lo_res   = cv::imread(lo_res_path);
}

processor::~processor()
{

}
