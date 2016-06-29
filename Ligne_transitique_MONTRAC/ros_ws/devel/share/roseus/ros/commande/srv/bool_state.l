;; Auto-generated. Do not edit!


(when (boundp 'commande::bool_state)
  (if (not (find-package "COMMANDE"))
    (make-package "COMMANDE"))
  (shadow 'bool_state (find-package "COMMANDE")))
(unless (find-package "COMMANDE::BOOL_STATE")
  (make-package "COMMANDE::BOOL_STATE"))
(unless (find-package "COMMANDE::BOOL_STATEREQUEST")
  (make-package "COMMANDE::BOOL_STATEREQUEST"))
(unless (find-package "COMMANDE::BOOL_STATERESPONSE")
  (make-package "COMMANDE::BOOL_STATERESPONSE"))

(in-package "ROS")





(defclass commande::bool_stateRequest
  :super ros::object
  :slots (_query ))

(defmethod commande::bool_stateRequest
  (:init
   (&key
    ((:query __query) nil)
    )
   (send-super :init)
   (setq _query __query)
   self)
  (:query
   (&optional __query)
   (if __query (setq _query __query)) _query)
  (:serialization-length
   ()
   (+
    ;; bool _query
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _query
       (if _query (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _query
     (setq _query (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass commande::bool_stateResponse
  :super ros::object
  :slots (_state ))

(defmethod commande::bool_stateResponse
  (:init
   (&key
    ((:state __state) nil)
    )
   (send-super :init)
   (setq _state __state)
   self)
  (:state
   (&optional __state)
   (if __state (setq _state __state)) _state)
  (:serialization-length
   ()
   (+
    ;; bool _state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _state
       (if _state (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _state
     (setq _state (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass commande::bool_state
  :super ros::object
  :slots ())

(setf (get commande::bool_state :md5sum-) "c7a88ab7a85f83bcb882571b8469aebb")
(setf (get commande::bool_state :datatype-) "commande/bool_state")
(setf (get commande::bool_state :request) commande::bool_stateRequest)
(setf (get commande::bool_state :response) commande::bool_stateResponse)

(defmethod commande::bool_stateRequest
  (:response () (instance commande::bool_stateResponse :init)))

(setf (get commande::bool_stateRequest :md5sum-) "c7a88ab7a85f83bcb882571b8469aebb")
(setf (get commande::bool_stateRequest :datatype-) "commande/bool_stateRequest")
(setf (get commande::bool_stateRequest :definition-)
      "bool query
---
bool state

")

(setf (get commande::bool_stateResponse :md5sum-) "c7a88ab7a85f83bcb882571b8469aebb")
(setf (get commande::bool_stateResponse :datatype-) "commande/bool_stateResponse")
(setf (get commande::bool_stateResponse :definition-)
      "bool query
---
bool state

")



(provide :commande/bool_state "c7a88ab7a85f83bcb882571b8469aebb")


