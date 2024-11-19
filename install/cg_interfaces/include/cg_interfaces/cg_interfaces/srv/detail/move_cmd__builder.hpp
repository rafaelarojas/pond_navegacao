// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_interfaces:srv/MoveCmd.idl
// generated code does not contain a copyright notice

#ifndef CG_INTERFACES__SRV__DETAIL__MOVE_CMD__BUILDER_HPP_
#define CG_INTERFACES__SRV__DETAIL__MOVE_CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_interfaces/srv/detail/move_cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveCmd_Request_direction
{
public:
  Init_MoveCmd_Request_direction()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_interfaces::srv::MoveCmd_Request direction(::cg_interfaces::srv::MoveCmd_Request::_direction_type arg)
  {
    msg_.direction = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_interfaces::srv::MoveCmd_Request>()
{
  return cg_interfaces::srv::builder::Init_MoveCmd_Request_direction();
}

}  // namespace cg_interfaces


namespace cg_interfaces
{

namespace srv
{

namespace builder
{

class Init_MoveCmd_Response_right
{
public:
  explicit Init_MoveCmd_Response_right(::cg_interfaces::srv::MoveCmd_Response & msg)
  : msg_(msg)
  {}
  ::cg_interfaces::srv::MoveCmd_Response right(::cg_interfaces::srv::MoveCmd_Response::_right_type arg)
  {
    msg_.right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

class Init_MoveCmd_Response_up
{
public:
  explicit Init_MoveCmd_Response_up(::cg_interfaces::srv::MoveCmd_Response & msg)
  : msg_(msg)
  {}
  Init_MoveCmd_Response_right up(::cg_interfaces::srv::MoveCmd_Response::_up_type arg)
  {
    msg_.up = std::move(arg);
    return Init_MoveCmd_Response_right(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

class Init_MoveCmd_Response_down
{
public:
  explicit Init_MoveCmd_Response_down(::cg_interfaces::srv::MoveCmd_Response & msg)
  : msg_(msg)
  {}
  Init_MoveCmd_Response_up down(::cg_interfaces::srv::MoveCmd_Response::_down_type arg)
  {
    msg_.down = std::move(arg);
    return Init_MoveCmd_Response_up(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

class Init_MoveCmd_Response_left
{
public:
  explicit Init_MoveCmd_Response_left(::cg_interfaces::srv::MoveCmd_Response & msg)
  : msg_(msg)
  {}
  Init_MoveCmd_Response_down left(::cg_interfaces::srv::MoveCmd_Response::_left_type arg)
  {
    msg_.left = std::move(arg);
    return Init_MoveCmd_Response_down(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

class Init_MoveCmd_Response_target_pos
{
public:
  explicit Init_MoveCmd_Response_target_pos(::cg_interfaces::srv::MoveCmd_Response & msg)
  : msg_(msg)
  {}
  Init_MoveCmd_Response_left target_pos(::cg_interfaces::srv::MoveCmd_Response::_target_pos_type arg)
  {
    msg_.target_pos = std::move(arg);
    return Init_MoveCmd_Response_left(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

class Init_MoveCmd_Response_robot_pos
{
public:
  explicit Init_MoveCmd_Response_robot_pos(::cg_interfaces::srv::MoveCmd_Response & msg)
  : msg_(msg)
  {}
  Init_MoveCmd_Response_target_pos robot_pos(::cg_interfaces::srv::MoveCmd_Response::_robot_pos_type arg)
  {
    msg_.robot_pos = std::move(arg);
    return Init_MoveCmd_Response_target_pos(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

class Init_MoveCmd_Response_success
{
public:
  Init_MoveCmd_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveCmd_Response_robot_pos success(::cg_interfaces::srv::MoveCmd_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveCmd_Response_robot_pos(msg_);
  }

private:
  ::cg_interfaces::srv::MoveCmd_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_interfaces::srv::MoveCmd_Response>()
{
  return cg_interfaces::srv::builder::Init_MoveCmd_Response_success();
}

}  // namespace cg_interfaces

#endif  // CG_INTERFACES__SRV__DETAIL__MOVE_CMD__BUILDER_HPP_
