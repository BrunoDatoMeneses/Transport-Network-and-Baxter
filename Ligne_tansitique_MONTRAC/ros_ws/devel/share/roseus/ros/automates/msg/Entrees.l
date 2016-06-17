;; Auto-generated. Do not edit!


(when (boundp 'automates::Entrees)
  (if (not (find-package "AUTOMATES"))
    (make-package "AUTOMATES"))
  (shadow 'Entrees (find-package "AUTOMATES")))
(unless (find-package "AUTOMATES::ENTREES")
  (make-package "AUTOMATES::ENTREES"))

(in-package "ROS")
;;//! \htmlinclude Entrees.msg.html


(defclass automates::Entrees
  :super ros::object
  :slots (_entrees ))

(defmethod automates::Entrees
  (:init
   (&key
    ((:entrees __entrees) 0)
    )
   (send-super :init)
   (setq _entrees (round __entrees))
   self)
  (:entrees
   (&optional __entrees)
   (if __entrees (setq _entrees __entrees)) _entrees)
  (:serialization-length
   ()
   (+
    ;; int32 _entrees
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _entrees
       (write-long _entrees s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _entrees
     (setq _entrees (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get automates::Entrees :md5sum-) "2fd94acaf54653c950d522c68a591eb3")
(setf (get automates::Entrees :datatype-) "automates/Entrees")
(setf (get automates::Entrees :definition-)
      "int32 entrees


")



(provide :automates/Entrees "2fd94acaf54653c950d522c68a591eb3")


