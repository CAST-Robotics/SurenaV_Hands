// Generated by gencpp from file surena_eth/reset_nodeResponse.msg
// DO NOT EDIT!


#ifndef SURENA_ETH_MESSAGE_RESET_NODERESPONSE_H
#define SURENA_ETH_MESSAGE_RESET_NODERESPONSE_H


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
struct reset_nodeResponse_
{
  typedef reset_nodeResponse_<ContainerAllocator> Type;

  reset_nodeResponse_()
    : result(0)  {
    }
  reset_nodeResponse_(const ContainerAllocator& _alloc)
    : result(0)  {
  (void)_alloc;
    }



   typedef int32_t _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::surena_eth::reset_nodeResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::surena_eth::reset_nodeResponse_<ContainerAllocator> const> ConstPtr;

}; // struct reset_nodeResponse_

typedef ::surena_eth::reset_nodeResponse_<std::allocator<void> > reset_nodeResponse;

typedef boost::shared_ptr< ::surena_eth::reset_nodeResponse > reset_nodeResponsePtr;
typedef boost::shared_ptr< ::surena_eth::reset_nodeResponse const> reset_nodeResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::surena_eth::reset_nodeResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::surena_eth::reset_nodeResponse_<ContainerAllocator1> & lhs, const ::surena_eth::reset_nodeResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::surena_eth::reset_nodeResponse_<ContainerAllocator1> & lhs, const ::surena_eth::reset_nodeResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace surena_eth

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::surena_eth::reset_nodeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::surena_eth::reset_nodeResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::surena_eth::reset_nodeResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "034a8e20d6a306665e3a5b340fab3f09";
  }

  static const char* value(const ::surena_eth::reset_nodeResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x034a8e20d6a30666ULL;
  static const uint64_t static_value2 = 0x5e3a5b340fab3f09ULL;
};

template<class ContainerAllocator>
struct DataType< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "surena_eth/reset_nodeResponse";
  }

  static const char* value(const ::surena_eth::reset_nodeResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 result\n"
"\n"
;
  }

  static const char* value(const ::surena_eth::reset_nodeResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct reset_nodeResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::surena_eth::reset_nodeResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::surena_eth::reset_nodeResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<int32_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SURENA_ETH_MESSAGE_RESET_NODERESPONSE_H
