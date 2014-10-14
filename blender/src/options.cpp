#include <options.hpp>

#include <log.hpp>

#include <iostream>
#include <string>

namespace po = boost::program_options;
using namespace blender;

ErrorCodes Options::parse_command_line(int argc, char* argv[])
{
    po::options_description desc("Supported Options");
    desc.add_options()
        ("help,h", "print usage")
        ("low_res,w", po::value<std::string>()->required(), "low resolution input file")
        ("high_res,i", po::value<std::string>()->required(), "high resolution input file")
        ("output,o", po::value<std::string>()->required(), "output composite file")
    ;

    po::store(po::parse_command_line(argc, argv, desc), internal_);

    if(internal_.count("help"))
    {
        std::cout << desc <<"\n";
        return kHelp;
    }

    try
    {
        po::notify(internal_);
    }
    catch (po::error& e)
    {
        LogError << e.what();
        return kFail;
    }

    return kOK;
}