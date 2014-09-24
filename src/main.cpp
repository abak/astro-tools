#include <log.hpp>
#include <options.hpp>


int main (int argc, char* argv[])
{
    blender::Options options;

    if(!options.parse_command_line(argc, argv))
    {
        LogError << "An error occured during the parsing odf the cli options";
    }

    return 0;
}