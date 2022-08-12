; Auto-generated. Do not edit!


(cl:in-package surena_eth-srv)


;//! \htmlinclude set_led-request.msg.html

(cl:defclass <set_led-request> (roslisp-msg-protocol:ros-message)
  ((effect
    :reader effect
    :initarg :effect
    :type cl:fixnum
    :initform 0))
)

(cl:defclass set_led-request (<set_led-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_led-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_led-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name surena_eth-srv:<set_led-request> is deprecated: use surena_eth-srv:set_led-request instead.")))

(cl:ensure-generic-function 'effect-val :lambda-list '(m))
(cl:defmethod effect-val ((m <set_led-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader surena_eth-srv:effect-val is deprecated.  Use surena_eth-srv:effect instead.")
  (effect m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_led-request>) ostream)
  "Serializes a message object of type '<set_led-request>"
  (cl:let* ((signed (cl:slot-value msg 'effect)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_led-request>) istream)
  "Deserializes a message object of type '<set_led-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'effect) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_led-request>)))
  "Returns string type for a service object of type '<set_led-request>"
  "surena_eth/set_ledRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_led-request)))
  "Returns string type for a service object of type 'set_led-request"
  "surena_eth/set_ledRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_led-request>)))
  "Returns md5sum for a message object of type '<set_led-request>"
  "e25c7994b68742a69959bfbdd1390188")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_led-request)))
  "Returns md5sum for a message object of type 'set_led-request"
  "e25c7994b68742a69959bfbdd1390188")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_led-request>)))
  "Returns full string definition for message of type '<set_led-request>"
  (cl:format cl:nil "int16 effect~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_led-request)))
  "Returns full string definition for message of type 'set_led-request"
  (cl:format cl:nil "int16 effect~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_led-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_led-request>))
  "Converts a ROS message object to a list"
  (cl:list 'set_led-request
    (cl:cons ':effect (effect msg))
))
;//! \htmlinclude set_led-response.msg.html

(cl:defclass <set_led-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:fixnum
    :initform 0))
)

(cl:defclass set_led-response (<set_led-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <set_led-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'set_led-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name surena_eth-srv:<set_led-response> is deprecated: use surena_eth-srv:set_led-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <set_led-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader surena_eth-srv:result-val is deprecated.  Use surena_eth-srv:result instead.")
  (result m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <set_led-response>) ostream)
  "Serializes a message object of type '<set_led-response>"
  (cl:let* ((signed (cl:slot-value msg 'result)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <set_led-response>) istream)
  "Deserializes a message object of type '<set_led-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<set_led-response>)))
  "Returns string type for a service object of type '<set_led-response>"
  "surena_eth/set_ledResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_led-response)))
  "Returns string type for a service object of type 'set_led-response"
  "surena_eth/set_ledResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<set_led-response>)))
  "Returns md5sum for a message object of type '<set_led-response>"
  "e25c7994b68742a69959bfbdd1390188")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'set_led-response)))
  "Returns md5sum for a message object of type 'set_led-response"
  "e25c7994b68742a69959bfbdd1390188")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<set_led-response>)))
  "Returns full string definition for message of type '<set_led-response>"
  (cl:format cl:nil "int16 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'set_led-response)))
  "Returns full string definition for message of type 'set_led-response"
  (cl:format cl:nil "int16 result~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <set_led-response>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <set_led-response>))
  "Converts a ROS message object to a list"
  (cl:list 'set_led-response
    (cl:cons ':result (result msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'set_led)))
  'set_led-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'set_led)))
  'set_led-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'set_led)))
  "Returns string type for a service object of type '<set_led>"
  "surena_eth/set_led")