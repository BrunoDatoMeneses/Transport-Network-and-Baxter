;; Auto-generated. Do not edit!


(when (boundp 'automates::Sorties)
  (if (not (find-package "AUTOMATES"))
    (make-package "AUTOMATES"))
  (shadow 'Sorties (find-package "AUTOMATES")))
(unless (find-package "AUTOMATES::SORTIES")
  (make-package "AUTOMATES::SORTIES"))

(in-package "ROS")
;;//! \htmlinclude Sorties.msg.html


(defclass automates::Sorties
  :super ros::object
  :slots (_sorties ))

(defmethod automates::Sorties
  (:init
   (&key
    ((:sorties __sorties) 0)
    )
   (send-super :init)
   (setq _sorties (round __sorties))
   self)
  (:sorties
   (&optional __sorties)
   (if __sorties (setq _sorties __sorties)) _sorties)
  (:serialization-length
   ()
   (+
    ;; int32 _sorties
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sorties
       (write-long _sorties s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sorties
     (setq _sorties (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get automates::Sorties :md5sum-) "eb8c2e3936f3777631d8548f59e5c804")
(setf (get automates::Sorties :datatype-) "automates/Sorties")
(setf (get automates::Sorties :definition-)
      "int32 sorties

")



(provide :automates/Sorties "eb8c2e3936f3777631d8548f59e5c804")


