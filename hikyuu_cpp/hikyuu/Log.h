/*
 * Log.h
 *
 *  Created on: 2013-2-1
 *      Author: fasiondog
 */

#ifndef LOG_H_
#define LOG_H_

#include <string>

//#define USE_PYTHON_STDOUT_FOR_LOGGING 1
#define USE_SPDLOG_FOR_LOGGING 1
//#define USE_BOOST_LOG_FOR_LOGGING 1
//#define USE_LOG4CPLUS_FOR_LOGGING 1
//#define USE_STDOUT_FOR_LOGGING 1

#ifdef USE_PYTHON_STDOUT_FOR_LOGGING
#include <boost/python/detail/wrap_python.hpp>
#include "datetime/Datetime.h"
#endif


//deprecated
#ifdef USE_LOG4CPLUS_FOR_LOGGING
#include <log4cplus/configurator.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#endif /* for USE_LOG4CPLUS_FOR_LOGGING */

#ifdef USE_BOOST_LOG_FOR_LOGGING
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#endif

#ifdef USE_SPDLOG_FOR_LOGGING
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#endif

#ifdef USE_STDOUT_FOR_LOGGING
#include "datetime/Datetime.h"
#endif

#ifndef HKU_API
#define HKU_API
#endif

namespace hku {

void HKU_API init_logger(const std::string& configue_name);


/**********************************************
 * Use Python stdout for logging
 *
 *********************************************/
#ifdef USE_PYTHON_STDOUT_FOR_LOGGING
#define HKU_DEBUG(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << Datetime::now() << " [DEBUG] " << msg;\
                          PySys_WriteStdout(buf.str().c_str());}
#define HKU_TRACE(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << Datetime::now() << " [TRACE] " << msg;\
                          PySys_WriteStdout(buf.str().c_str());}
#define HKU_INFO(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << Datetime::now() << " [INFO] " << msg;\
                          PySys_WriteStdout(buf.str().c_str());}
#define HKU_WARN(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << Datetime::now() << " [WARN] " << msg;\
                          PySys_WriteStdout(buf.str().c_str());}
#define HKU_ERROR(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << Datetime::now() << " [ERROR] " << msg;\
                          PySys_WriteStdout(buf.str().c_str());}
#define HKU_FATAL(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << Datetime::now() << " [FATAL] " << msg;\
                          PySys_WriteStdout(buf.str().c_str());}
#endif

/**********************************************
 * Use log4cplus for logging
 *
 *********************************************/

#ifdef USE_LOG4CPLUS_FOR_LOGGING
log4cplus::Logger HKU_API getLogger();

typedef log4cplus::Logger Logger;

#define HKU_DEBUG(msg)  LOG4CPLUS_DEBUG(getLogger(), msg)
#define HKU_TRACE(msg)  LOG4CPLUS_TRACE(getLogger(), msg)
#define HKU_INFO(msg)   LOG4CPLUS_INFO(getLogger(), msg)
#define HKU_WARN(msg)   LOG4CPLUS_WARN(getLogger(), msg)
#define HKU_ERROR(msg)  LOG4CPLUS_ERROR(getLogger(), msg)
#define HKU_FATAL(msg)  LOG4CPLUS_FATAL(getLogger(), msg)

#endif /* for USE_LOG4CPLUS_FOR_LOGGING */


/**********************************************
 * Use Boost.log for logging
 *
 *********************************************/
#ifdef USE_BOOST_LOG_FOR_LOGGING
#define HKU_DEBUG(msg)  BOOST_LOG_TRIVIAL(debug) << msg
#define HKU_TRACE(msg)  BOOST_LOG_TRIVIAL(trace) << msg
#define HKU_INFO(msg)   BOOST_LOG_TRIVIAL(info) << msg
#define HKU_WARN(msg)   BOOST_LOG_TRIVIAL(warning) << msg
#define HKU_ERROR(msg)  BOOST_LOG_TRIVIAL(error) << msg
#define HKU_FATAL(msg)  BOOST_LOG_TRIVIAL(fatal) << msg
#endif /* for USE_BOOST_LOG_FOR_LOGGING */


/**********************************************
 * Use SPDLOG for logging
 *
 *********************************************/
#ifdef USE_SPDLOG_FOR_LOGGING
#define HKU_DEBUG(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << msg;\
                          spdlog::get("console")->debug(buf.str().c_str());}
#define HKU_TRACE(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << msg;\
                          spdlog::get("console")->trace(buf.str().c_str());}
#define HKU_INFO(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << msg;\
                          spdlog::get("console")->info(buf.str().c_str());}
#define HKU_WARN(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << msg;\
                          spdlog::get("console")->warn(buf.str().c_str());}
#define HKU_ERROR(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << msg;\
                          spdlog::get("console")->error(buf.str().c_str());}
#define HKU_FATAL(msg)  { std::stringstream buf (std::stringstream::out); \
                          buf << msg;\
                          spdlog::get("console")->critical(buf.str().c_str());}
#endif


/**********************************************
 * Use STDOUT for logging, not threadsafe
 *
 *********************************************/
#ifdef USE_STDOUT_FOR_LOGGING
#define HKU_DEBUG(msg)  { std::cout << Datetime::now() << " [DEBUG] " << msg << std::endl;}
#define HKU_TRACE(msg)  { std::cout << Datetime::now() << " [TRACE] " << msg << std::endl;}
#define HKU_INFO(msg)   { std::cout << Datetime::now() << " [INFO] " << msg << std::endl;}
#define HKU_WARN(msg)   { std::cout << Datetime::now() << " [WARN] " << msg << std::endl;}
#define HKU_ERROR(msg)  { std::cout << Datetime::now() << " [ERROR] " << msg << std::endl;}
#define HKU_FATAL(msg)  { std::cout << Datetime::now() << " [FATAL] " << msg << std::endl;}
#endif /* for USE_STDOUT_FOR_LOGGING */

} /* namespace hku */
#endif /* LOG_H_ */
