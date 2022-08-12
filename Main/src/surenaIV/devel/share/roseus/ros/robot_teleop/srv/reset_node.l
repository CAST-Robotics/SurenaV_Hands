;; Auto-generated. Do not edit!


(when (boundp 'robot_teleop::reset_node)
  (if (not (find-package "ROBOT_TELEOP"))
    (make-package "ROBOT_TELEOP"))
  (shadow 'reset_node (find-package "ROBOT_TELEOP")))
(unless (find-package "ROBOT_TELEOP::RESET_NODE")
  (make-package "ROBOT_TELEOP::RESET_NODE"))
(unless (find-package "ROBOT_TELEOP::RESET_NODEREQUEST")
  (make-package "ROBOT_TELEOP::RESET_NODEREQUEST"))
(unless (find-package "ROBOT_TELEOP::RESET_NODERESPONSE")
  (make-package "ROBOT_TELEOP::RESET_NODERESPONSE"))

(in-package "ROS")





(defclass robot_teleop::reset_nodeRequest
  :super ros::object
  :slots (_nodeID ))

(defmethod robot_teleop::reset_nodeRequest
  (:init
   (&key
    ((:nodeID __nodeID) 0)
    )
   (send-super :init)
   (setq _nodeID (round __nodeID))
   self)
  (:nodeID
   (&optional __nodeID)
   (if __nodeID (setq _nodeID __nodeID)) _nodeID)
  (:serialization-length
   ()
   (+
    ;; int32 _nodeID
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _nodeID
       (write-long _nodeID s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _nodeID
     (setq _nodeID (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass robot_teleop::reset_nodeResponse
  :super ros::object
  :slots (_result ))

(defmethod robot_teleop::reset_nodeResponse
  (:init
   (&key
    ((:result __result) 0)
    )
   (send-super :init)
   (setq _result (round __result))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:serialization-length
   ()
   (+
    ;; int32 _result
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _result
       (write-long _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _result
     (setq _result (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass robot_teleop::reset_node
  :super ros::object
  :slots ())

(setf (get robot_teleop::reset_node :md5sum-) "0c471dfb6b81ef71ddb24300538963e0")
(setf (get robot_teleop::reset_node :datatype-) "robot_teleop/reset_node")
(setf (get robot_teleop::reset_node :request) robot_teleop::reset_nodeRequest)
(setf (get robot_teleop::reset_node :response) robot_teleop::reset_nodeResponse)

(defmethod robot_teleop::reset_nodeRequest
  (:response () (instance robot_teleop::reset_nodeResponse :init)))

(setf (get robot_teleop::reset_nodeRequest :md5sum-) "0c471dfb6b81ef71ddb24300538963e0")
(setf (get robot_teleop::reset_nodeRequest :datatype-) "robot_teleop/reset_nodeRequest")
(setf (get robot_teleop::reset_nodeRequest :definition-)
      "int32 nodeID
---
int32 result

")

(setf (get robot_teleop::reset_nodeResponse :md5sum-) "0c471dfb6b81ef71ddb24300538963e0")
(setf (get robot_teleop::reset_nodeResponse :datatype-) "robot_teleop/reset_nodeResponse")
(setf (get robot_teleop::reset_nodeResponse :definition-)
      "int32 nodeID
---
int32 result

")



(provide :robot_teleop/reset_node "0c471dfb6b81ef71ddb24300538963e0")


