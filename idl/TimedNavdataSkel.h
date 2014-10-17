// -*- C++ -*-
/*!
 *
 * THIS FILE IS GENERATED AUTOMATICALLY!! DO NOT EDIT!!
 *
 * @file TimedNavdataSkel.h 
 * @brief TimedNavdata server skeleton header wrapper code
 * @date Fri Oct 17 16:27:21 2014 
 *
 */

#ifndef _TIMEDNAVDATASKEL_H
#define _TIMEDNAVDATASKEL_H



#include <rtm/config_rtc.h>
#undef PACKAGE_BUGREPORT
#undef PACKAGE_NAME
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_VERSION

#if   defined ORB_IS_TAO
#  include "TimedNavdataC.h"
#  include "TimedNavdataS.h"
#elif defined ORB_IS_OMNIORB
#  if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#    undef USE_stub_in_nt_dll
#  endif
#  include "TimedNavdata.hh"
#elif defined ORB_IS_MICO
#  include "TimedNavdata.h"
#elif defined ORB_IS_ORBIT2
#  include "/TimedNavdata-cpp-stubs.h"
#  include "/TimedNavdata-cpp-skels.h"
#elif defined ORB_IS_RTORB
#  include "TimedNavdata.h"
#else
#  error "NO ORB defined"
#endif

#endif // _TIMEDNAVDATASKEL_H
