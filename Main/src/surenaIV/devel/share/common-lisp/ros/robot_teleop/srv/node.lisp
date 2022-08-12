; Auto-generated. Do not edit!


(cl:in-package robot_teleop-srv)


;//! \htmlinclude node-request.msg.html

(cl:defclass <node-request> (roslisp-msg-protocol:ros-message)
  ((nodeID
    :reader nodeID
    :initarg :nodeID
    :type cl:integer
    :initform 0))
)

(cl:defclass node-request (<node-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <node-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'node-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_teleop-srv:<node-request> is deprecated: use robot_teleop-srv:node-request instead.")))

(cl:ensure-generic-function 'nodeID-val :lambda-list '(m))
(cl:defmethod nodeID-val ((m <node-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_teleop-srv:nodeID-val is deprecated.  Use robot_teleop-srv:nodeID instead.")
  (nodeID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <node-request>) ostream)
  "Serializes a message object of type '<node-request>"
  (cl:let* ((signed (cl:slot-value msg 'nodeID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <node-request>) istream)
  "Deserializes a message object of type '<node-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'nodeID) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<node-request>)))
  "Returns string type for a service object of type '<node-request>"
  "robot_teleop/nodeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node-request)))
  "Returns string type for a service object of type 'node-request"
  "robot_teleop/nodeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<node-request>)))
  "Returns md5sum for a message object of type '<node-request>"
  "0c471dfb6b81ef71ddb24300538963e0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'node-request)))
  "Returns md5sum for a message object of type 'node-request"
  "0c471dfb6b81ef71ddb24300538963e0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<node-request>)))
  "Returns full string definition for message of type '<node-request>"
  (cl:format cl:nil "int32 nodeID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'node-request)))
  "Returns full string definition for message of type 'node-request"
  (cl:format cl:nil "int32 nodeID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <node-request>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <node-request>))
  "Converts a ROS message object to a list"
  (cl:list 'node-request
    (cl:cons ':nodeID (nodeID msg))
))
;//! \htmlinclude node-response.msg.html

(cl:defclass <node-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:integer
    :initform 0))
)

(cl:defclass node-response (<node-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <node-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'node-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name robot_teleop-srv:<node-response> is deprecated: use robot_teleop-srv:node-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <node-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader robot_teleop-srv:result-val is deprecated.  Use robot_teleop-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <node-response>) ostream)
  "Serializes a message object of type '<node-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <node-response>) istream)
  "Deserializes a message object of type '<node-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<node-response>)))
  "Returns string type for a service object of type '<node-response>"
  "robot_teleop/nodeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node-response)))
  "Returns string type for a service object of type 'node-response"
  "robot_teleop/nodeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<node-response>)))
  "Returns md5sum for a message object of type '<node-response>"
  "0c471dfb6b81ef71ddb24300538963e0")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'node-response)))
  "Returns md5sum for a message object of type 'node-response"
  "0c471dfb6b81ef71ddb24300538963e0")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<node-response>)))
  "Returns full string definition for message of type '<node-response>"
  (cl:format cl:nil "int32 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'node-response)))
  "Returns full string definition for message of type 'node-response"
  (cl:format cl:nil "int32 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <node-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <node-response>))
  "Converts a ROS message object to a list"
  (cl:list 'node-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'node)))
  'node-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'node)))
  'node-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node)))
  "Returns string type for a service object of type '<node>"
  "robot_teleop/node")