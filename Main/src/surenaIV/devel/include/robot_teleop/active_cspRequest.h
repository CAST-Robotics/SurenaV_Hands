// Generated by gencpp from file robot_teleop/active_cspRequest.msg
// DO NOT EDIT!


#ifndef ROBOT_TELEOP_MESSAGE_ACTIVE_CSPREQUEST_H
#define ROBOT_TELEOP_MESSAGE_ACTIVE_CSPREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robot_teleop
{
template <class ContainerAllocator>
struct active_cspRequest_
{
  typedef active_cspRequest_<ContainerAllocator> Type;

  active_cspRequest_()
    : nodeID(0)  {
    }
  active_cspRequest_(const ContainerAllocator& _alloc)
    : nodeID(0)  {
  (void)_alloc;
    }



   typedef int16_t _nodeID_type;
  _nodeID_type nodeID;





  typedef boost::shared_ptr< ::robot_teleop::active_cspRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_teleop::active_cspRequest_<ContainerAllocator> const> ConstPtr;

}; // struct active_cspRequest_

typedef ::robot_teleop::active_cspRequest_<std::allocator<void> > active_cspRequest;

typedef boost::shared_ptr< ::robot_teleop::active_cspRequest > active_cspRequestPtr;
typedef boost::shared_ptr< ::robot_teleop::active_cspRequest const> active_cspRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_teleop::active_cspRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_teleop::active_cspRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robot_teleop::active_cspRequest_<ContainerAllocator1> & lhs, const ::robot_teleop::active_cspRequest_<ContainerAllocator2> & rhs)
{
  return lhs.nodeID == rhs.nodeID;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robot_teleop::active_cspRequest_<ContainerAllocator1> & lhs, const ::robot_teleop::active_cspRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robot_teleop

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_teleop::active_cspRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_teleop::active_cspRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_teleop::active_cspRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ab70d03352862bd3e7f20efd8fa5cb9d";
  }

  static const char* value(const ::robot_teleop::active_cspRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xab70d03352862bd3ULL;
  static const uint64_t static_value2 = 0xe7f20efd8fa5cb9dULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_teleop/active_cspRequest";
  }

  static const char* value(const ::robot_teleop::active_cspRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 nodeID\n"
;
  }

  static const char* value(const ::robot_teleop::active_cspRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.nodeID);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct active_cspRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_teleop::active_cspRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_teleop::active_cspRequest_<ContainerAllocator>& v)
  {
    s << indent << "nodeID: ";
    Printer<int16_t>::stream(s, indent + "  ", v.nodeID);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_TELEOP_MESSAGE_ACTIVE_CSPREQUEST_H
