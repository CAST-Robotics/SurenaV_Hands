;; Auto-generated. Do not edit!


(when (boundp 'surena_eth::set_led)
  (if (not (find-package "SURENA_ETH"))
    (make-package "SURENA_ETH"))
  (shadow 'set_led (find-package "SURENA_ETH")))
(unless (find-package "SURENA_ETH::SET_LED")
  (make-package "SURENA_ETH::SET_LED"))
(unless (find-package "SURENA_ETH::SET_LEDREQUEST")
  (make-package "SURENA_ETH::SET_LEDREQUEST"))
(unless (find-package "SURENA_ETH::SET_LEDRESPONSE")
  (make-package "SURENA_ETH::SET_LEDRESPONSE"))

(in-package "ROS")





(defclass surena_eth::set_ledRequest
  :super ros::object
  :slots (_effect ))

(defmethod surena_eth::set_ledRequest
  (:init
   (&key
    ((:effect __effect) 0)
    )
   (send-super :init)
   (setq _effect (round __effect))
   self)
  (:effect
   (&optional __effect)
   (if __effect (setq _effect __effect)) _effect)
  (:serialization-length
   ()
   (+
    ;; int16 _effect
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int16 _effect
       (write-word _effect s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int16 _effect
     (setq _effect (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass surena_eth::set_ledResponse
  :super ros::object
  :slots (_result ))

(defmethod surena_eth::set_ledResponse
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

(defclass surena_eth::set_led
  :super ros::object
  :slots ())

(setf (get surena_eth::set_led :md5sum-) "e25c7994b68742a69959bfbdd1390188")
(setf (get surena_eth::set_led :datatype-) "surena_eth/set_led")
(setf (get surena_eth::set_led :request) surena_eth::set_ledRequest)
(setf (get surena_eth::set_led :response) surena_eth::set_ledResponse)

(defmethod surena_eth::set_ledRequest
  (:response () (instance surena_eth::set_ledResponse :init)))

(setf (get surena_eth::set_ledRequest :md5sum-) "e25c7994b68742a69959bfbdd1390188")
(setf (get surena_eth::set_ledRequest :datatype-) "surena_eth/set_ledRequest")
(setf (get surena_eth::set_ledRequest :definition-)
      "int16 effect
---
int16 result

")

(setf (get surena_eth::set_ledResponse :md5sum-) "e25c7994b68742a69959bfbdd1390188")
(setf (get surena_eth::set_ledResponse :datatype-) "surena_eth/set_ledResponse")
(setf (get surena_eth::set_ledResponse :definition-)
      "int16 effect
---
int16 result

")



(provide :surena_eth/set_led "e25c7994b68742a69959bfbdd1390188")


