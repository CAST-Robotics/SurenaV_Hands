;; Auto-generated. Do not edit!


(when (boundp 'surena_eth::home)
  (if (not (find-package "SURENA_ETH"))
    (make-package "SURENA_ETH"))
  (shadow 'home (find-package "SURENA_ETH")))
(unless (find-package "SURENA_ETH::HOME")
  (make-package "SURENA_ETH::HOME"))
(unless (find-package "SURENA_ETH::HOMEREQUEST")
  (make-package "SURENA_ETH::HOMEREQUEST"))
(unless (find-package "SURENA_ETH::HOMERESPONSE")
  (make-package "SURENA_ETH::HOMERESPONSE"))

(in-package "ROS")





(defclass surena_eth::homeRequest
  :super ros::object
  :slots (_nodeID ))

(defmethod surena_eth::homeRequest
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

(defclass surena_eth::homeResponse
  :super ros::object
  :slots (_result ))

(defmethod surena_eth::homeResponse
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

(defclass surena_eth::home
  :super ros::object
  :slots ())

(setf (get surena_eth::home :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get surena_eth::home :datatype-) "surena_eth/home")
(setf (get surena_eth::home :request) surena_eth::homeRequest)
(setf (get surena_eth::home :response) surena_eth::homeResponse)

(defmethod surena_eth::homeRequest
  (:response () (instance surena_eth::homeResponse :init)))

(setf (get surena_eth::homeRequest :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get surena_eth::homeRequest :datatype-) "surena_eth/homeRequest")
(setf (get surena_eth::homeRequest :definition-)
      "int16 nodeID
---
int16 result

")

(setf (get surena_eth::homeResponse :md5sum-) "9d17c7a086f295f3ddeb8ac344bfc6ca")
(setf (get surena_eth::homeResponse :datatype-) "surena_eth/homeResponse")
(setf (get surena_eth::homeResponse :definition-)
      "int16 nodeID
---
int16 result

")



(provide :surena_eth/home "9d17c7a086f295f3ddeb8ac344bfc6ca")


