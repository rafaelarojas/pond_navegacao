// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cg_interfaces:srv/GetMap.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cg_interfaces/srv/detail/get_map__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetMap_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cg_interfaces::srv::GetMap_Request(_init);
}

void GetMap_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cg_interfaces::srv::GetMap_Request *>(message_memory);
  typed_message->~GetMap_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetMap_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_interfaces::srv::GetMap_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetMap_Request_message_members = {
  "cg_interfaces::srv",  // message namespace
  "GetMap_Request",  // message name
  1,  // number of fields
  sizeof(cg_interfaces::srv::GetMap_Request),
  GetMap_Request_message_member_array,  // message members
  GetMap_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  GetMap_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetMap_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetMap_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace cg_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cg_interfaces::srv::GetMap_Request>()
{
  return &::cg_interfaces::srv::rosidl_typesupport_introspection_cpp::GetMap_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cg_interfaces, srv, GetMap_Request)() {
  return &::cg_interfaces::srv::rosidl_typesupport_introspection_cpp::GetMap_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "cg_interfaces/srv/detail/get_map__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void GetMap_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cg_interfaces::srv::GetMap_Response(_init);
}

void GetMap_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cg_interfaces::srv::GetMap_Response *>(message_memory);
  typed_message->~GetMap_Response();
}

size_t size_function__GetMap_Response__occupancy_grid_flattened(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetMap_Response__occupancy_grid_flattened(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__GetMap_Response__occupancy_grid_flattened(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetMap_Response__occupancy_grid_flattened(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__GetMap_Response__occupancy_grid_flattened(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__GetMap_Response__occupancy_grid_flattened(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__GetMap_Response__occupancy_grid_flattened(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__GetMap_Response__occupancy_grid_flattened(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GetMap_Response__occupancy_grid_shape(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GetMap_Response__occupancy_grid_shape(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void * get_function__GetMap_Response__occupancy_grid_shape(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  return &member[index];
}

void fetch_function__GetMap_Response__occupancy_grid_shape(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint8_t *>(
    get_const_function__GetMap_Response__occupancy_grid_shape(untyped_member, index));
  auto & value = *reinterpret_cast<uint8_t *>(untyped_value);
  value = item;
}

void assign_function__GetMap_Response__occupancy_grid_shape(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint8_t *>(
    get_function__GetMap_Response__occupancy_grid_shape(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint8_t *>(untyped_value);
  item = value;
}

void resize_function__GetMap_Response__occupancy_grid_shape(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<uint8_t> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GetMap_Response_message_member_array[2] = {
  {
    "occupancy_grid_flattened",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_interfaces::srv::GetMap_Response, occupancy_grid_flattened),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetMap_Response__occupancy_grid_flattened,  // size() function pointer
    get_const_function__GetMap_Response__occupancy_grid_flattened,  // get_const(index) function pointer
    get_function__GetMap_Response__occupancy_grid_flattened,  // get(index) function pointer
    fetch_function__GetMap_Response__occupancy_grid_flattened,  // fetch(index, &value) function pointer
    assign_function__GetMap_Response__occupancy_grid_flattened,  // assign(index, value) function pointer
    resize_function__GetMap_Response__occupancy_grid_flattened  // resize(index) function pointer
  },
  {
    "occupancy_grid_shape",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    2,  // array size
    true,  // is upper bound
    offsetof(cg_interfaces::srv::GetMap_Response, occupancy_grid_shape),  // bytes offset in struct
    nullptr,  // default value
    size_function__GetMap_Response__occupancy_grid_shape,  // size() function pointer
    get_const_function__GetMap_Response__occupancy_grid_shape,  // get_const(index) function pointer
    get_function__GetMap_Response__occupancy_grid_shape,  // get(index) function pointer
    fetch_function__GetMap_Response__occupancy_grid_shape,  // fetch(index, &value) function pointer
    assign_function__GetMap_Response__occupancy_grid_shape,  // assign(index, value) function pointer
    resize_function__GetMap_Response__occupancy_grid_shape  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GetMap_Response_message_members = {
  "cg_interfaces::srv",  // message namespace
  "GetMap_Response",  // message name
  2,  // number of fields
  sizeof(cg_interfaces::srv::GetMap_Response),
  GetMap_Response_message_member_array,  // message members
  GetMap_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  GetMap_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GetMap_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetMap_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace cg_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cg_interfaces::srv::GetMap_Response>()
{
  return &::cg_interfaces::srv::rosidl_typesupport_introspection_cpp::GetMap_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cg_interfaces, srv, GetMap_Response)() {
  return &::cg_interfaces::srv::rosidl_typesupport_introspection_cpp::GetMap_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "cg_interfaces/srv/detail/get_map__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace cg_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers GetMap_service_members = {
  "cg_interfaces::srv",  // service namespace
  "GetMap",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<cg_interfaces::srv::GetMap>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t GetMap_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GetMap_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace cg_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<cg_interfaces::srv::GetMap>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::cg_interfaces::srv::rosidl_typesupport_introspection_cpp::GetMap_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::cg_interfaces::srv::GetMap_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::cg_interfaces::srv::GetMap_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cg_interfaces, srv, GetMap)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<cg_interfaces::srv::GetMap>();
}

#ifdef __cplusplus
}
#endif
