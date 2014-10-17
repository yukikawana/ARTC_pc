// This file is generated by omniidl (C++ backend)- omniORB_4_1. Do not edit.

#include "TimedNavdata.hh"
#include <omniORB4/IOP_S.h>
#include <omniORB4/IOP_C.h>
#include <omniORB4/callDescriptor.h>
#include <omniORB4/callHandle.h>
#include <omniORB4/objTracker.h>


OMNI_USING_NAMESPACE(omni)

static const char* _0RL_library_version = omniORB_4_1;



void
naistrobotics::TimedNavdata::operator>>= (cdrStream &_n) const
{
  (const RTC::Time&) tm >>= _n;
  imgwidth >>= _n;
  imgheight >>= _n;
  imgSize >>= _n;
  imgType >>= _n;
  (const RTC::TimedOctetSeq&) imgData >>= _n;
  roll >>= _n;
  pitch >>= _n;
  yaw >>= _n;
  altitude >>= _n;
  vx >>= _n;
  vy >>= _n;
  vz >>= _n;
  battery >>= _n;
  _n.marshalBoolean(onground);
  (const RTC::TimedDoubleSeq&) additional >>= _n;

}

void
naistrobotics::TimedNavdata::operator<<= (cdrStream &_n)
{
  (RTC::Time&)tm <<= _n;
  (::CORBA::Long&)imgwidth <<= _n;
  (::CORBA::Long&)imgheight <<= _n;
  (::CORBA::Long&)imgSize <<= _n;
  (::CORBA::Long&)imgType <<= _n;
  (RTC::TimedOctetSeq&)imgData <<= _n;
  (::CORBA::Double&)roll <<= _n;
  (::CORBA::Double&)pitch <<= _n;
  (::CORBA::Double&)yaw <<= _n;
  (::CORBA::Double&)altitude <<= _n;
  (::CORBA::Double&)vx <<= _n;
  (::CORBA::Double&)vy <<= _n;
  (::CORBA::Double&)vz <<= _n;
  (::CORBA::Short&)battery <<= _n;
  onground = _n.unmarshalBoolean();
  (RTC::TimedDoubleSeq&)additional <<= _n;

}
