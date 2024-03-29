// Generated by gencpp from file surena_eth/set_ledRequest.msg
// DO NOT EDIT!


#ifndef SURENA_ETH_MESSAGE_SET_LEDREQUEST_H
#define SURENA_ETH_MESSAGE_SET_LEDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace surena_eth
{
template <class ContainerAllocator>
struct set_ledRequest_
{
  typedef set_ledRequest_<ContainerAllocator> Type;

  set_ledRequest_()
    : effect(0)  {
    }
  set_ledRequest_(const ContainerAllocator& _alloc)
    : effect(0)  {
  (void)_alloc;
    }



   typedef int16_t _effect_type;
  _effect_type effect;





  typedef boost::shared_ptr< ::surena_eth::set_ledRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::surena_eth::set_ledRequest_<ContainerAllocator> const> ConstPtr;

}; // struct set_ledRequest_

typedef ::surena_eth::set_ledRequest_<std::allocator<void> > set_ledRequest;

typedef boost::shared_ptr< ::surena_eth::set_ledRequest > set_ledRequestPtr;
typedef boost::shared_ptr< ::surena_eth::set_ledRequest const> set_ledRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::surena_eth::set_ledRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::surena_eth::set_ledRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::surena_eth::set_ledRequest_<ContainerAllocator1> & lhs, const ::surena_eth::set_ledRequest_<ContainerAllocator2> & rhs)
{
  return lhs.effect == rhs.effect;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::surena_eth::set_ledRequest_<ContainerAllocator1> & lhs, const ::surena_eth::set_ledRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace surena_eth

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::surena_eth::set_ledRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::surena_eth::set_ledRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::surena_eth::set_ledRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::surena_eth::set_ledRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::surena_eth::set_ledRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::surena_eth::set_ledRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::surena_eth::set_ledRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d5b16c38fab6ec555795be0fbd20633f";
  }

  static const char* value(const ::surena_eth::set_ledRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd5b16c38fab6ec55ULL;
  static const uint64_t static_value2 = 0x5795be0fbd20633fULL;
};

template<class ContainerAllocator>
struct DataType< ::surena_eth::set_ledRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "surena_eth/set_ledRequest";
  }

  static const char* value(const ::surena_eth::set_ledRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::surena_eth::set_ledRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16 effect\n"
;
  }

  static const char* value(const ::surena_eth::set_ledRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::surena_eth::set_ledRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.effect);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct set_ledRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::surena_eth::set_ledRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::surena_eth::set_ledRequest_<ContainerAllocator>& v)
  {
    s << indent << "effect: ";
    Printer<int16_t>::stream(s, indent + "  ", v.effect);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SURENA_ETH_MESSAGE_SET_LEDREQUEST_H
