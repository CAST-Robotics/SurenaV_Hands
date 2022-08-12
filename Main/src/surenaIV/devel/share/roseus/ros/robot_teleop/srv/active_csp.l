;; Auto-generated. Do not edit!


(when (boundp 'robot_teleop::active_csp)
  (if (not (find-package "ROBOT_TELEOP"))
    (make-package "ROBOT_TELEOP"))
  (shadow 'active_csp (find-package "ROBOT_TELEOP")))
(unless (find-package "ROBOT_TELEOP::ACTIVE_CSP")
  (make-package "ROBOT_TELEOP::ACTIVE_CSP"))
(unless (find-package "ROBOT_TELEOP::ACTIVE_CSPREQUEST")
  (make-package "ROBOT_TELEOP::ACTIVE_CSPREQUEST"))
(unless (find-package "ROBOT_TELEOP::ACTIVE_CSPRESPONSE")
  (make-package "ROBOT_TELEOP::ACTIVE_CSPRESPONSE"))

(in-package "ROS")





(defclass robot_teleop::active_cspRequest
  :super ros::object
  :slots (_nodeID ))

(defmethod robot_teleop::active_cspRequest
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

(defclass robot_teleop::active_cspResponse
  :super ros::object
  :slots (_result ))

(defmethod robot_teleop::active_cspResponse
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

(defclass robot_teleop::active_csp
  :super ros::object
  :slots ())

(setf (get robot_teleop::active_csp :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get robot_teleop::active_csp :datatype-) "robot_teleop/active_csp")
(setf (get robot_teleop::active_csp :request) robot_teleop::active_cspRequest)
(setf (get robot_teleop::active_csp :response) robot_teleop::active_cspResponse)

(defmethod robot_teleop::active_cspRequest
  (:response () (instance robot_teleop::active_cspResponse :init)))

(setf (get robot_teleop::active_cspRequest :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get robot_teleop::active_cspRequest :datatype-) "robot_teleop/active_cspRequest")
(setf (get robot_teleop::active_cspRequest :definition-)
      "int16 nodeID
---
int16 result

")

(setf (get robot_teleop::active_cspResponse :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get robot_teleop::active_cspResponse :datatype-) "robot_teleop/active_cspResponse")
(setf (get robot_teleop::active_cspResponse :definition-)
      "int16 nodeID
---
int16 result

")



(provide :robot_teleop/active_csp "9d17c7a086f295f3ddeb8ac344bfc6ca")


