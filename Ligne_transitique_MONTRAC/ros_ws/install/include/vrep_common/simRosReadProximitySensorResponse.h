// Generated by gencpp from file vrep_common/simRosReadProximitySensorResponse.msg
// DO NOT EDIT!


#ifndef VREP_COMMON_MESSAGE_SIMROSREADPROXIMITYSENSORRESPONSE_H
#define VREP_COMMON_MESSAGE_SIMROSREADPROXIMITYSENSORRESPONSE_H


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
struct simRosReadProximitySensorResponse_
{
  typedef simRosReadProximitySensorResponse_<ContainerAllocator> Type;

  simRosReadProximitySensorResponse_()
    : result(0)
    , detectedPoint()
    , detectedObject(0)
    , normalVector()  {
    }
  simRosReadProximitySensorResponse_(const ContainerAllocator& _alloc)
    : result(0)
    , detectedPoint(_alloc)
    , detectedObject(0)
    , normalVector(_alloc)  {
    }



   typedef int32_t _result_type;
  _result_type result;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _detectedPoint_type;
  _detectedPoint_type detectedPoint;

   typedef int32_t _detectedObject_type;
  _detectedObject_type detectedObject;

   typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _normalVector_type;
  _normalVector_type normalVector;




  typedef boost::shared_ptr< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> const> ConstPtr;

}; // struct simRosReadProximitySensorResponse_

typedef ::vrep_common::simRosReadProximitySensorResponse_<std::allocator<void> > simRosReadProximitySensorResponse;

typedef boost::shared_ptr< ::vrep_common::simRosReadProximitySensorResponse > simRosReadProximitySensorResponsePtr;
typedef boost::shared_ptr< ::vrep_common::simRosReadProximitySensorResponse const> simRosReadProximitySensorResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vrep_common

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/jade/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/jade/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/jade/share/geometry_msgs/cmake/../msg'], 'vrep_common': ['/home/etudiant/M1_ISTR/Ligne_transitique_MONTRAC/ros_ws/src/vrep_common/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6d96957b6da2491c9e2ffcfcd60996ad";
  }

  static const char* value(const ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6d96957b6da2491cULL;
  static const uint64_t static_value2 = 0x9e2ffcfcd60996adULL;
};

template<class ContainerAllocator>
struct DataType< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vrep_common/simRosReadProximitySensorResponse";
  }

  static const char* value(const ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 result\n\
float32[] detectedPoint\n\
int32 detectedObject\n\
float32[] normalVector\n\
\n\
";
  }

  static const char* value(const ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.detectedPoint);
      stream.next(m.detectedObject);
      stream.next(m.normalVector);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct simRosReadProximitySensorResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vrep_common::simRosReadProximitySensorResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result);
    s << indent << "detectedPoint[]" << std::endl;
    for (size_t i = 0; i < v.detectedPoint.size(); ++i)
    {
      s << indent << "  detectedPoint[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.detectedPoint[i]);
    }
    s << indent << "detectedObject: ";
    Printer<int32_t>::stream(s, indent + "  ", v.detectedObject);
    s << indent << "normalVector[]" << std::endl;
    for (size_t i = 0; i < v.normalVector.size(); ++i)
    {
      s << indent << "  normalVector[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.normalVector[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // VREP_COMMON_MESSAGE_SIMROSREADPROXIMITYSENSORRESPONSE_H
