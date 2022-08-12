; Auto-generated. Do not edit!


(cl:in-package surena_eth-srv)


;//! \htmlinclude home-request.msg.html

(cl:defclass <home-request> (roslisp-msg-protocol:ros-message)
  ((nodeID
    :reader nodeID
    :initarg :nodeID
    :type cl:fixnum
    :initform 0))
)

(cl:defclass home-request (<home-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <home-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'home-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name surena_eth-srv:<home-request> is deprecated: use surena_eth-srv:home-request instead.")))

(cl:ensure-generic-function 'nodeID-val :lambda-list '(m))
(cl:defmethod nodeID-val ((m <home-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader surena_eth-srv:nodeID-val is deprecated.  Use surena_eth-srv:nodeID instead.")
  (nodeID m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <home-request>) ostream)
  "Serializes a message object of type '<home-request>"
  (cl:let* ((signed (cl:slot-value msg 'nodeID)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <home-request>) istream)
  "Deserializes a message object of type '<home-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'nodeID) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<home-request>)))
  "Returns string type for a service object of type '<home-request>"
  "surena_eth/homeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'home-request)))
  "Returns string type for a service object of type 'home-request"
  "surena_eth/homeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<home-request>)))
  "Returns md5sum for a message object of type '<home-request>"
  "9d17c7a086f295f3ddeb8ac344bfc6ca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'home-request)))
  "Returns md5sum for a message object of type 'home-request"
  "9d17c7a086f295f3ddeb8ac344bfc6ca")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<home-request>)))
  "Returns full string definition for message of type '<home-request>"
  (cl:format cl:nil "int16 nodeID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'home-request)))
  "Returns full string definition for message of type 'home-request"
  (cl:format cl:nil "int16 nodeID~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <home-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <home-request>))
  "Converts a ROS message object to a list"
  (cl:list 'home-request
    (cl:cons ':nodeID (nodeID msg))
))
;//! \htmlinclude home-response.msg.html

(cl:defclass <home-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:fixnum
    :initform 0))
)

(cl:defclass home-response (<home-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <home-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'home-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name surena_eth-srv:<home-response> is deprecated: use surena_eth-srv:home-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <home-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader surena_eth-srv:result-val is deprecated.  Use surena_eth-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <home-response>) ostream)
  "Serializes a message object of type '<home-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <home-response>) istream)
  "Deserializes a message object of type '<home-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<home-response>)))
  "Returns string type for a service object of type '<home-response>"
  "surena_eth/homeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'home-response)))
  "Returns string type for a service object of type 'home-response"
  "surena_eth/homeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<home-response>)))
  "Returns md5sum for a message object of type '<home-response>"
  "9d17c7a086f295f3ddeb8ac344bfc6ca")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'home-response)))
  "Returns md5sum for a message object of type 'home-response"
  "9d17c7a086f295f3ddeb8ac344bfc6ca")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<home-response>)))
  "Returns full string definition for message of type '<home-response>"
  (cl:format cl:nil "int16 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'home-response)))
  "Returns full string definition for message of type 'home-response"
  (cl:format cl:nil "int16 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <home-response>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <home-response>))
  "Converts a ROS message object to a list"
  (cl:list 'home-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'home)))
  'home-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'home)))
  'home-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'home)))
  "Returns string type for a service object of type '<home>"
  "surena_eth/home")