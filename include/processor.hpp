#ifndef PROCESSOR_HPP___
#define PROCESSOR_HPP___

#include <log.hpp>

#include <opencv2/core.hpp>

namespace blender
{
    class processor
    {
    public:
        processor(const std::string& high_res_path,
                  const std::string& lo_res_path);
        ~processor();

    private:
        cv::Mat high_res;
        cv::Mat lo_res;
        cv::Mat result;
    };

}


#endif