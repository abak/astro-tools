#ifndef OPTIONS_HPP___
#define OPTIONS_HPP___

#include <boost/program_options.hpp>

namespace blender
{

    enum ErrorCodes
    {
        kOK= 0,
        kFail = 1,
        kHelp = 2,
    };

    namespace keys
    {
        const std::string high_res_input = "high_res";
        const std::string low_res_input  = "low_res";
        const std::string output_file    = "output";
    }

    struct Options
    {
        typedef boost::program_options::variables_map internal_t;

        ErrorCodes parse_command_line(int argc, char* argv[]);

        template <typename T>
        T get(std::string key)
        {
            return internal_[key].as<T>();
        }

    private:
        internal_t internal_;

    };
}



#endif