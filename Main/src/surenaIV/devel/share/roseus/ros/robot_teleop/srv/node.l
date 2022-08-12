;; Auto-generated. Do not edit!


(when (boundp 'robot_teleop::node)
  (if (not (find-package "ROBOT_TELEOP"))
    (make-package "ROBOT_TELEOP"))
  (shadow 'node (find-package "ROBOT_TELEOP")))
(unless (find-package "ROBOT_TELEOP::NODE")
  (make-package "ROBOT_TELEOP::NODE"))
(unless (find-package "ROBOT_TELEOP::NODEREQUEST")
  (make-package "ROBOT_TELEOP::NODEREQUEST"))
(unless (find-package "ROBOT_TELEOP::NODERESPONSE")
  (make-package "ROBOT_TELEOP::NODERESPONSE"))

(in-package "ROS")





(defclass robot_teleop::nodeRequest
  :super ros::object
  :slots (_nodeID ))

(defmethod robot_teleop::nodeRequest
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

(defclass robot_teleop::nodeResponse
  :super ros::object
  :slots (_result ))

(defmethod robot_teleop::nodeResponse
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

(defclass robot_teleop::node
  :super ros::object
  :slots ())

(setf (get robot_teleop::node :md5sum-) "0c471dfb6b81ef71ddb24300538963e0")
(setf (get robot_teleop::node :datatype-) "robot_teleop/node")
(setf (get robot_teleop::node :request) robot_teleop::nodeRequest)
(setf (get robot_teleop::node :response) robot_teleop::nodeResponse)

(defmethod robot_teleop::nodeRequest
  (:response () (instance robot_teleop::nodeResponse :init)))

(setf (get robot_teleop::nodeRequest :md5sum-) "0c471dfb6b81ef71ddb24300538963e0")
(setf (get robot_teleop::nodeRequest :datatype-) "robot_teleop/nodeRequest")
(setf (get robot_teleop::nodeRequest :definition-)
      "int32 nodeID
---
int32 result

")

(setf (get robot_teleop::nodeResponse :md5sum-) "0c471dfb6b81ef71ddb24300538963e0")
(setf (get robot_teleop::nodeResponse :datatype-) "robot_teleop/nodeResponse")
(setf (get robot_teleop::nodeResponse :definition-)
      "int32 nodeID
---
int32 result

")



(provide :robot_teleop/node "0c471dfb6b81ef71ddb24300538963e0")


