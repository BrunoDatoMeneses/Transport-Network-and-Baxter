;; Auto-generated. Do not edit!


(when (boundp 'commande_locale::Msg_StopControl)
  (if (not (find-package "COMMANDE_LOCALE"))
    (make-package "COMMANDE_LOCALE"))
  (shadow 'Msg_StopControl (find-package "COMMANDE_LOCALE")))
(unless (find-package "COMMANDE_LOCALE::MSG_STOPCONTROL")
  (make-package "COMMANDE_LOCALE::MSG_STOPCONTROL"))

(in-package "ROS")
;;//! \htmlinclude Msg_StopControl.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass commande_locale::Msg_StopControl
  :super ros::object
  :slots (_header _STOP _GO ))

(defmethod commande_locale::Msg_StopControl
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:STOP __STOP) (let (r) (dotimes (i 25) (push nil r)) r))
    ((:GO __GO) (let (r) (dotimes (i 25) (push nil r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _STOP __STOP)
   (setq _GO __GO)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:STOP
   (&optional __STOP)
   (if __STOP (setq _STOP __STOP)) _STOP)
  (:GO
   (&optional __GO)
   (if __GO (setq _GO __GO)) _GO)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; bool[25] _STOP
    (* 1    25)
    ;; bool[25] _GO
    (* 1    25)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; bool[25] _STOP
     (dotimes (i 25)
       (if (elt _STOP i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; bool[25] _GO
     (dotimes (i 25)
       (if (elt _GO i) (write-byte -1 s) (write-byte 0 s))
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; bool[25] _STOP
   (dotimes (i (length _STOP))
     (setf (elt _STOP i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;; bool[25] _GO
   (dotimes (i (length _GO))
     (setf (elt _GO i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;;
   self)
  )

(setf (get commande_locale::Msg_StopControl :md5sum-) "3351a875ff673c8814a96d783877c306")
(setf (get commande_locale::Msg_StopControl :datatype-) "commande_locale/Msg_StopControl")
(setf (get commande_locale::Msg_StopControl :definition-)
      "Header header

bool[25] STOP
bool[25] GO

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :commande_locale/Msg_StopControl "3351a875ff673c8814a96d783877c306")


