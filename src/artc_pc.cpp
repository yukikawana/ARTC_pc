// -*- C++ -*-
/*!
 * @file  artc_pc.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "artc_pc.h"

// Module specification
// <rtc-template block="module_spec">
static const char* artc_pc_spec[] =
  {
    "implementation_id", "artc_pc",
    "type_name",         "artc_pc",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
artc_pc::artc_pc(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_navdataIn("navdata", m_navdata),
    m_controldataOut("controldata", m_controldata)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
artc_pc::~artc_pc()
{
}



RTC::ReturnCode_t artc_pc::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("navdata", m_navdataIn);
  
  // Set OutPort buffer
  addOutPort("controldata", m_controldataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t artc_pc::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t artc_pc::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t artc_pc::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t artc_pc::onActivated(RTC::UniqueId ec_id)
{
  vx=0;
    vy=0;
  vz=0;
  vr=0;
  flying=false;
  count=0;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t artc_pc::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t artc_pc::onExecute(RTC::UniqueId ec_id)
{

count++;
cv::waitKey(33);
if(count<800)flying=true;
else flying=false;
std::cout << "count " << count <<std::endl;
       m_controldata.vx=0;
       m_controldata.vy=0;
       m_controldata.vz=0;
       vr=0;
       if(200> count && count>100 )vr=1.0;
       else if(200> count && count>100 )vr=-1.0;
       else if(300> count && count>200 )vr=1.0;
       else if(400> count && count>300 )vr=-1.0;
       else if(500> count && count>400 )vr=1.0;
       else if(600> count && count>500 )vr=-1.0;
       else if(700> count && count>600 )vr=1.0;
       else if(800> count && count>700 )vr=-1.0;
       m_controldata.yaw=vr;
       m_controldata.onground=flying;
       m_controldataOut.write();
if(m_navdataIn.isNew()){
	m_navdataIn.read();
//std::cout << "ardrone.roll  = " << 2.0 * RAD_TO_DEG << " [deg]" << std::endl;
//cv::Mat image=data_mat(m_navdata.imgData);
//cv::imshow("camera", image);
 //cv::waitKey(33);
 //cv::Mat red_img(cv::Size(640, 480), CV_8UC3, cv::Scalar(0,0,255));
 cv::Mat image(cv::Size(m_navdata.imgwidth, m_navdata.imgheight), m_navdata.imgType);
 std::cout << "width " << m_navdata.imgwidth << " height " <<  m_navdata.imgheight << " data length "<< m_navdata.imgData.data.length() <<std::endl;
 memcpy(image.data,(void *)&(m_navdata.imgData.data[0]),m_navdata.imgData.data.length());
 //image.data=m_navdata.imgData.data;
//image.put(0, 0, red_img.data)
 
 cv::imshow("camera", image);
 }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t artc_pc::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t artc_pc::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t artc_pc::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t artc_pc::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t artc_pc::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void artc_pcInit(RTC::Manager* manager)
  {
    coil::Properties profile(artc_pc_spec);
    manager->registerFactory(profile,
                             RTC::Create<artc_pc>,
                             RTC::Delete<artc_pc>);
  }
  
};


