#include <log.hpp>
#include <options.hpp>
#include <processor.hpp>


#include <string>

using namespace blender;

int main (int argc, char* argv[])
{
    Options options;

    switch (options.parse_command_line(argc, argv))
    {
        case kFail :
            LogError << "An error occured during the parsing odf the cli options";
            return kFail;

        case kHelp:
            return kOK;
    }

    processor processor(options.get<std::string>(keys::high_res_input),
                        options.get<std::string>(keys::low_res_input));

    return 0;
}