#ifndef OPTIONS_HPP___
#define OPTIONS_HPP___

#include <boost/program_options.hpp>

namespace blender
{
    struct Options
    {
        typedef boost::program_options::variables_map internal_t;

        bool parse_command_line(int argc, char* argv[]);


    private:
        internal_t internal_;

    };
}



#endif