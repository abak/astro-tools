#ifndef LOGGING_HPP___
#define LOGGING_HPP___

#define BOOST_LOG_DYN_LINK

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

namespace logging = boost::log;

#define LOG(x) BOOST_LOG_TRIVIAL(x)

#define LogInfo    BOOST_LOG_TRIVIAL(info)
#define LogDebug   BOOST_LOG_TRIVIAL(debug)
#define LogWarning BOOST_LOG_TRIVIAL(warning)
#define LogError   BOOST_LOG_TRIVIAL(error)
#define LogFatal   BOOST_LOG_TRIVIAL(fatal)

#endif
