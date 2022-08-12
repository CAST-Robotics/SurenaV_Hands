;; Auto-generated. Do not edit!


(when (boundp 'robot_teleop::home)
  (if (not (find-package "ROBOT_TELEOP"))
    (make-package "ROBOT_TELEOP"))
  (shadow 'home (find-package "ROBOT_TELEOP")))
(unless (find-package "ROBOT_TELEOP::HOME")
  (make-package "ROBOT_TELEOP::HOME"))
(unless (find-package "ROBOT_TELEOP::HOMEREQUEST")
  (make-package "ROBOT_TELEOP::HOMEREQUEST"))
(unless (find-package "ROBOT_TELEOP::HOMERESPONSE")
  (make-package "ROBOT_TELEOP::HOMERESPONSE"))

(in-package "ROS")





(defclass robot_teleop::homeRequest
  :super ros::object
  :slots (_nodeID ))

(defmethod robot_teleop::homeRequest
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
    ;; int16 _nodeID
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _nodeID
       (write-word _nodeID s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _nodeID
     (setq _nodeID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass robot_teleop::homeResponse
  :super ros::object
  :slots (_result ))

(defmethod robot_teleop::homeResponse
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
    ;; int16 _result
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _result
       (write-word _result s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _result
     (setq _result (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass robot_teleop::home
  :super ros::object
  :slots ())

(setf (get robot_teleop::home :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get robot_teleop::home :datatype-) "robot_teleop/home")
(setf (get robot_teleop::home :request) robot_teleop::homeRequest)
(setf (get robot_teleop::home :response) robot_teleop::homeResponse)

(defmethod robot_teleop::homeRequest
  (:response () (instance robot_teleop::homeResponse :init)))

(setf (get robot_teleop::homeRequest :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get robot_teleop::homeRequest :datatype-) "robot_teleop/homeRequest")
(setf (get robot_teleop::homeRequest :definition-)
      "int16 nodeID
---
int16 result

")

(setf (get robot_teleop::homeResponse :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get robot_teleop::homeResponse :datatype-) "robot_teleop/homeResponse")
(setf (get robot_teleop::homeResponse :definition-)
      "int16 nodeID
---
int16 result

")



(provide :robot_teleop/home "9d17c7a086f295f3ddeb8ac344bfc6ca")


