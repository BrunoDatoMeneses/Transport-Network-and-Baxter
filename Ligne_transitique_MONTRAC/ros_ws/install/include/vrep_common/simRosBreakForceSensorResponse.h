// Generated by gencpp from file vrep_common/simRosBreakForceSensorResponse.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSBREAKFORCESENSORRESPONSE_H
#define VREP_COMMON_MESSAGE_SIMROSBREAKFORCESENSORRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vrep_common
{
template <class ContainerAllocator>
struct simRosBreakForceSensorResponse_
{
  typedef simRosBreakForceSensorResponse_<ContainerAllocator> Type;

  simRosBreakForceSensorResponse_()
    : result(0)  {
    }
  simRosBreakForceSensorResponse_(const ContainerAllocator& _alloc)
    : result(0)  {
    }



   typedef int32_t _result_type;
  _result_type result;




  typedef boost::shared_ptr< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> const> ConstPtr;

}; // struct simRosBreakForceSensorResponse_

typedef ::vrep_common::simRosBreakForceSensorResponse_<std::allocator<void> > simRosBreakForceSensorResponse;

typedef boost::shared_ptr< ::vrep_common::simRosBreakForceSensorResponse > simRosBreakForceSensorResponsePtr;
typedef boost::shared_ptr< ::vrep_common::simRosBreakForceSensorResponse const> simRosBreakForceSensorResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vrep_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/jade/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg'], 'vrep_common': ['/home/etudiant/M1_ISTR/Ligne_transitique_MONTRAC/ros_ws/src/vrep_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "034a8e20d6a306665e3a5b340fab3f09";
  }

  static const char* value(const ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x034a8e20d6a30666ULL;
  static const uint64_t static_value2 = 0x5e3a5b340fab3f09ULL;
};

template<class ContainerAllocator>
struct DataType< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vrep_common/simRosBreakForceSensorResponse";
  }

  static const char* value(const ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 result\n\
\n\
\n\
";
  }

  static const char* value(const ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct simRosBreakForceSensorResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vrep_common::simRosBreakForceSensorResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSBREAKFORCESENSORRESPONSE_H
