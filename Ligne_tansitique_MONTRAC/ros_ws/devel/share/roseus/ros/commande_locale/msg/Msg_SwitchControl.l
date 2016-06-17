;; Auto-generated. Do not edit!


(when (boundp 'commande_locale::Msg_SwitchControl)
  (if (not (find-package "COMMANDE_LOCALE"))
    (make-package "COMMANDE_LOCALE"))
  (shadow 'Msg_SwitchControl (find-package "COMMANDE_LOCALE")))
(unless (find-package "COMMANDE_LOCALE::MSG_SWITCHCONTROL")
  (make-package "COMMANDE_LOCALE::MSG_SWITCHCONTROL"))

(in-package "ROS")
;;//! \htmlinclude Msg_SwitchControl.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass commande_locale::Msg_SwitchControl
  :super ros::object
  :slots (_header _LOCK _RD _RG ))

(defmethod commande_locale::Msg_SwitchControl
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:LOCK __LOCK) (let (r) (dotimes (i 13) (push nil r)) r))
    ((:RD __RD) (let (r) (dotimes (i 13) (push nil r)) r))
    ((:RG __RG) (let (r) (dotimes (i 13) (push nil r)) r))
    )
   (send-super :init)
   (setq _header __header)
   (setq _LOCK __LOCK)
   (setq _RD __RD)
   (setq _RG __RG)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:LOCK
   (&optional __LOCK)
   (if __LOCK (setq _LOCK __LOCK)) _LOCK)
  (:RD
   (&optional __RD)
   (if __RD (setq _RD __RD)) _RD)
  (:RG
   (&optional __RG)
   (if __RG (setq _RG __RG)) _RG)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; bool[13] _LOCK
    (* 1    13)
    ;; bool[13] _RD
    (* 1    13)
    ;; bool[13] _RG
    (* 1    13)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; bool[13] _LOCK
     (dotimes (i 13)
       (if (elt _LOCK i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; bool[13] _RD
     (dotimes (i 13)
       (if (elt _RD i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; bool[13] _RG
     (dotimes (i 13)
       (if (elt _RG i) (write-byte -1 s) (write-byte 0 s))
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; bool[13] _LOCK
   (dotimes (i (length _LOCK))
     (setf (elt _LOCK i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;; bool[13] _RD
   (dotimes (i (length _RD))
     (setf (elt _RD i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;; bool[13] _RG
   (dotimes (i (length _RG))
     (setf (elt _RG i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     )
   ;;
   self)
  )

(setf (get commande_locale::Msg_SwitchControl :md5sum-) "0797883d1e8c7216af064c8c90c37c74")
(setf (get commande_locale::Msg_SwitchControl :datatype-) "commande_locale/Msg_SwitchControl")
(setf (get commande_locale::Msg_SwitchControl :definition-)
      "Header header

bool[13] LOCK
bool[13] RD
bool[13] RG

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



(provide :commande_locale/Msg_SwitchControl "0797883d1e8c7216af064c8c90c37c74")


