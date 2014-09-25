#include <processor.hpp>

#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace blender;

processor::processor(const std::string& high_res_path,
          const std::string& lo_res_path)
{
    hi_res = cv::imread(high_res_path);
    lo_res   = cv::imread(lo_res_path);

    if(hi_res.data == NULL || lo_res.data == NULL)
    {
        CV_Error(-1, "images mot loaded correctly");
    }

    result.create(hi_res.size(), hi_res.type());
}

processor::~processor()
{

}

void processor::preprocess()
{
    if(hi_res.size() != lo_res.size())
    {
        cv::Mat temp(hi_res.size(), hi_res.type());
        cv::resize(lo_res, temp, temp.size());
        lo_res = temp;
    }
}


const int max_dimension_for_display = 512;
void processor::display()const 
{


    int max_dim = std::max(hi_res.size().width, hi_res.size().height);

    if (max_dim < max_dimension_for_display)
    {
        cv::imshow("high_res", hi_res);
        cv::imshow("low res", lo_res);
    }
    else
    {
        const float mult = max_dimension_for_display / static_cast<float>(max_dim);

        cv::Size new_size(hi_res.size().width * mult, hi_res.size().width * mult);
        cv::Mat hi_res_resize(new_size, hi_res.type());
        cv::Mat lo_res_resize(new_size, lo_res.type());

        cv::resize(hi_res, hi_res_resize, new_size);
        cv::resize(lo_res, lo_res_resize, new_size);

        cv::imshow("high_res", hi_res_resize);
        cv::imshow("low res", lo_res_resize);
    }

    cv::waitKey();

    return;
}



